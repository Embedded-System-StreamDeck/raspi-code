#include "buttonconfiguration.h"
#include "moc_buttonconfiguration.cpp"

ButtonConfiguration::ButtonConfiguration(QObject *parent)
    : QObject(parent)
    , m_buttonId(-1)
{
}

int ButtonConfiguration::buttonId() const
{
    return m_buttonId;
}

void ButtonConfiguration::setButtonId(int buttonId)
{
    if (m_buttonId != buttonId) {
        m_buttonId = buttonId;
        emit buttonIdChanged(buttonId);
    }
}

QString ButtonConfiguration::label() const
{
    return m_label;
}

void ButtonConfiguration::setLabel(const QString &label)
{
    if (m_label != label) {
        m_label = label;
        emit labelChanged(label);
    }
}

QString ButtonConfiguration::commandId() const
{
    return m_commandId;
}

void ButtonConfiguration::setCommandId(const QString &commandId)
{
    if (m_commandId != commandId) {
        m_commandId = commandId;
        emit commandIdChanged(commandId);
    }
}

QString ButtonConfiguration::iconPath() const
{
    return m_iconPath;
}

void ButtonConfiguration::setIconPath(const QString &iconPath)
{
    if (m_iconPath != iconPath) {
        m_iconPath = iconPath;
        emit iconPathChanged(iconPath);
    }
}
