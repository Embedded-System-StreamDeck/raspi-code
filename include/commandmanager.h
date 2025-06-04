#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include <QObject>
#include <QString>
#include <QVariant>
#include "networkmanager.h"

class CommandManager : public QObject
{
    Q_OBJECT
    
public:
    explicit CommandManager(NetworkManager *networkManager, QObject *parent = nullptr);
    
public slots:
    void executeCommand(const QString &commandId, const QVariant &parameters = QVariant());
    void saveButtonConfig(int buttonId, const QString &commandId, const QString &label, const QString &iconPath);
    Q_INVOKABLE void sendCommand(const QString &command);
    
signals:
    void commandExecuted(const QString &commandId, bool success);
    
private:
    NetworkManager *m_networkManager;
};

#endif // COMMANDMANAGER_H
