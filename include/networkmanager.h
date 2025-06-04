#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <QVariant>
#include <QHostAddress>

class NetworkManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool connected READ isConnected NOTIFY connectionStatusChanged)
    Q_PROPERTY(QString serverAddress READ serverAddress WRITE setServerAddress NOTIFY serverAddressChanged)
    Q_PROPERTY(int serverPort READ serverPort WRITE setServerPort NOTIFY serverPortChanged)

public:
    explicit NetworkManager(QObject *parent = nullptr);
    
    bool isConnected() const;
    
    QString serverAddress() const;
    void setServerAddress(const QString &address);
    
    int serverPort() const;
    void setServerPort(int port);
    
    void updateServerWithDeviceIp();
    QString getDeviceIpAddress() const;
    QString deviceIpAddress() const { return getDeviceIpAddress(); }
    
public slots:
    Q_INVOKABLE void connectToServer();
    Q_INVOKABLE void disconnectFromServer();
    Q_INVOKABLE bool sendCommand(const QString &commandId, const QVariant &parameters = QVariant());
    Q_INVOKABLE bool sendRawCommand(const QString &command);
    
signals:
    void connectionStatusChanged(bool connected);
    void serverAddressChanged(const QString &address);
    void serverPortChanged(int port);
    void messageReceived(const QString &message);
    void errorOccurred(const QString &errorMessage);
    
private slots:
    void onConnected();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError socketError);
    void onDataReceived();
    
private:
    QTcpSocket *m_socket;
    QString m_serverAddress;
    int m_serverPort;
    bool m_connected;
};

#endif // NETWORKMANAGER_H
