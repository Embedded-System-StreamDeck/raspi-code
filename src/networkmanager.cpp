#include "networkmanager.h"
#include "moc_networkmanager.cpp"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QProcess>
#include <QRegularExpression>
#include "clientsocket.h"

NetworkManager::NetworkManager(QObject *parent)
    : QObject(parent)
    , m_socket(new QTcpSocket(this))
    , m_serverAddress("192.168.207.213") // Varsayılan sunucu adresi
    , m_serverPort(5000) // Varsayılan port
    , m_connected(false)
{
    connect(m_socket, &QTcpSocket::connected, this, &NetworkManager::onConnected);
    connect(m_socket, &QTcpSocket::disconnected, this, &NetworkManager::onDisconnected);
    // Qt6 ile uyumlu hata sinyali bağlantısı
    connect(m_socket, &QTcpSocket::errorOccurred, this, &NetworkManager::onError);
    connect(m_socket, &QTcpSocket::readyRead, this, &NetworkManager::onDataReceived);
    
    // Start by updating server address with device's IP
    updateServerWithDeviceIp();
}

bool NetworkManager::isConnected() const
{
    return m_connected;
}

QString NetworkManager::serverAddress() const
{
    return m_serverAddress;
}

void NetworkManager::setServerAddress(const QString &address)
{
    if (m_serverAddress != address) {
        m_serverAddress = address;
        emit serverAddressChanged(address);
    }
}

int NetworkManager::serverPort() const
{
    return m_serverPort;
}

void NetworkManager::setServerPort(int port)
{
    if (m_serverPort != port) {
        m_serverPort = port;
        emit serverPortChanged(port);
    }
}

void NetworkManager::connectToServer()
{
    if (m_socket->state() == QAbstractSocket::UnconnectedState) {
        qDebug() << "Connecting to:" << m_serverAddress << ":" << m_serverPort;
        m_socket->connectToHost(m_serverAddress, m_serverPort);
    }
}

void NetworkManager::disconnectFromServer()
{
    if (m_socket->state() == QAbstractSocket::ConnectedState) {
        m_socket->disconnectFromHost();
    }
}

bool NetworkManager::sendCommand(const QString &commandId, const QVariant &parameters)
{
    if (m_socket->state() != QAbstractSocket::ConnectedState) {
        return false;
    }
    
    QJsonObject command;
    command["commandId"] = commandId;
    
    if (parameters.isValid()) {
        // Qt5 uyumluluğu için typeId() yerine type() ve QVariant::Map/List kullanıldı
        if (parameters.type() == QVariant::Map) {
            command["parameters"] = QJsonObject::fromVariantMap(parameters.toMap());
        } else if (parameters.type() == QVariant::List) {
            command["parameters"] = QJsonArray::fromVariantList(parameters.toList());
        } else if (parameters.canConvert<QString>()) {
            command["parameters"] = parameters.toString();
        } else {
            command["parameters"] = QJsonValue::fromVariant(parameters);
        }
    }
    
    QJsonDocument doc(command);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    data.append("\n"); // Add newline as command terminator
    
    qint64 bytesWritten = m_socket->write(data);
    return bytesWritten == data.size();
}

bool NetworkManager::sendRawCommand(const QString &command)
{
    if (m_socket->state() != QAbstractSocket::ConnectedState) {
        return false;
    }
    
    QByteArray data = command.toUtf8();
    if (!data.endsWith('\n')) {
        data.append('\n'); // Add newline as command terminator
    }
    
    qint64 bytesWritten = m_socket->write(data);
    return bytesWritten == data.size();
}

void NetworkManager::onConnected()
{
    qDebug() << "Connected to server:" << m_serverAddress << ":" << m_serverPort;
    m_connected = true;
    emit connectionStatusChanged(true);
}

void NetworkManager::onDisconnected()
{
    qDebug() << "Disconnected from server";
    m_connected = false;
    emit connectionStatusChanged(false);
}

void NetworkManager::onError(QAbstractSocket::SocketError socketError)
{
    QString errorMessage = m_socket->errorString();
    qWarning() << "Socket error:" << socketError << errorMessage;
    emit errorOccurred(errorMessage);
}

void NetworkManager::updateServerWithDeviceIp()
{
    QString deviceIp = getDeviceIpAddress();
    if (!deviceIp.isEmpty()) {
        setServerAddress(deviceIp);
        qDebug() << "Server address updated to device IP:" << deviceIp;
    }
}

QString NetworkManager::getDeviceIpAddress() const
{
    QProcess process;
    process.start("ip", QStringList() << "a");
    process.waitForFinished();
    
    QString output = QString::fromUtf8(process.readAllStandardOutput());
    qDebug() << "IP address query output:" << output;
    
    // Parse the output to find IP addresses (excluding localhost 127.0.0.1)
    QRegularExpression ipRegex("inet\\s+(\\d+\\.\\d+\\.\\d+\\.\\d+)");
    QRegularExpressionMatchIterator i = ipRegex.globalMatch(output);
    
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString ip = match.captured(1);
        
        // Skip localhost
        if (ip != "127.0.0.1") {
            qDebug() << "Found device IP:" << ip;
            return ip;
        }
    }
    
    qWarning() << "Could not determine device IP address";
    return QString();
}

void NetworkManager::onDataReceived()
{
    QByteArray data = m_socket->readAll();
    qDebug() << "Received data from server, size:" << data.size();

    // JSON ayrıştırması
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(data, &err);
    if (err.error != QJsonParseError::NoError) {
        qWarning() << "JSON parse hatası:" << err.errorString() << "Ham veri:" << data;
        return;
    }

    QJsonObject obj = doc.object();
    if (obj.contains("buttons") && obj["buttons"].isArray()) {
        QJsonArray buttonArray = obj["buttons"].toArray();
        qDebug() << "Butonlar alındı, sayı:" << buttonArray.size();
        
        // JSON string olarak mesajı gönder
        QString jsonString = QString::fromUtf8(data);
        emit messageReceived(jsonString);
    } else {
        qWarning() << "Gelen JSON'da buttons alanı bulunamadı veya array değil";
        // Raw mesaj olarak da ilet
        QString message = QString::fromUtf8(data);
        emit messageReceived(message);
    }
}
