#include "commandmanager.h"
#include "moc_commandmanager.cpp"
#include <QDebug>

CommandManager::CommandManager(NetworkManager *networkManager, QObject *parent)
    : QObject(parent), m_networkManager(networkManager)
{
}

void CommandManager::executeCommand(const QString &commandId, const QVariant &parameters)
{
    qDebug() << "Executing command:" << commandId << "with parameters:" << parameters;
    
    // Burada komutu işleyip Network Manager'a gönderebilirsiniz
    bool success = m_networkManager->sendCommand(commandId, parameters);
    
    emit commandExecuted(commandId, success);
}

void CommandManager::saveButtonConfig(int buttonId, const QString &commandId, const QString &label, const QString &iconPath)
{
    qDebug() << "Saving button config:" << buttonId << commandId << label << iconPath;
    // Burada buton yapılandırmasını kaydetme işlemini gerçekleştirebilirsiniz
}

void CommandManager::sendCommand(const QString &command)
{
    qDebug() << "Sending command:" << command;
    m_networkManager->sendRawCommand(command);
}
