#ifndef BUTTONCONFIGURATION_H
#define BUTTONCONFIGURATION_H

#include <QObject>
#include <QString>

class ButtonConfiguration : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int buttonId READ buttonId WRITE setButtonId NOTIFY buttonIdChanged)
    Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged)
    Q_PROPERTY(QString commandId READ commandId WRITE setCommandId NOTIFY commandIdChanged)
    Q_PROPERTY(QString iconPath READ iconPath WRITE setIconPath NOTIFY iconPathChanged)
    
public:
    explicit ButtonConfiguration(QObject *parent = nullptr);
    
    int buttonId() const;
    void setButtonId(int buttonId);
    
    QString label() const;
    void setLabel(const QString &label);
    
    QString commandId() const;
    void setCommandId(const QString &commandId);
    
    QString iconPath() const;
    void setIconPath(const QString &iconPath);
    
signals:
    void buttonIdChanged(int buttonId);
    void labelChanged(const QString &label);
    void commandIdChanged(const QString &commandId);
    void iconPathChanged(const QString &iconPath);
    
private:
    int m_buttonId;
    QString m_label;
    QString m_commandId;
    QString m_iconPath;
};

#endif // BUTTONCONFIGURATION_H
