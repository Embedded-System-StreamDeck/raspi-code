#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <QVariant>
#include <QHostAddress>
#include <QUdpSocket>
#include <QTimer>

class NetworkManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool connected READ isConnected NOTIFY connectionStatusChanged)
    Q_PROPERTY(QString serverAddress READ serverAddress WRITE setServerAddress NOTIFY serverAddressChanged)
    Q_PROPERTY(int serverPort READ serverPort WRITE setServerPort NOTIFY serverPortChanged)
    Q_PROPERTY(bool discovering READ isDiscovering NOTIFY discoveringStatusChanged)

public:
    explicit NetworkManager(QObject *parent = nullptr);
    ~NetworkManager();
    
    bool isConnected() const;
    bool isDiscovering() const;
    
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
    Q_INVOKABLE void discoverServer();
    Q_INVOKABLE void stopDiscovery();
    
signals:
    void connectionStatusChanged(bool connected);
    void serverAddressChanged(const QString &address);
    void serverPortChanged(int port);
    void messageReceived(const QString &message);
    void errorOccurred(const QString &errorMessage);
    void discoveringStatusChanged(bool discovering);
    void serverDiscovered(const QString &address, int port);
    
private slots:
    void onConnected();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError socketError);
    void onDataReceived();
    void processPendingDatagrams();
    void sendDiscoveryRequest();
    
private:
    QTcpSocket *m_socket;
    QString m_serverAddress;
    int m_serverPort;
    bool m_connected;
    
    // Discovery related members
    QUdpSocket *m_discoverySocket;
    QTimer *m_discoveryTimer;
    bool m_discovering;
    static const int DISCOVERY_PORT = 5001;
    static const int DISCOVERY_INTERVAL = 1000; // milliseconds
};

#endif // NETWORKMANAGER_H
