#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QScreen>
#include <QProcess>
#include "commandmanager.h"
#include "networkmanager.h"
#include "buttonconfiguration.h"

int main(int argc, char *argv[])
{
    // Qt6'da High DPI her zaman etkindir, bu ayar artık gerekmez
    // QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    
    QGuiApplication app(argc, argv);
    
    qmlRegisterType<ButtonConfiguration>("StreamDeck", 1, 0, "ButtonConfiguration");
    
    NetworkManager networkManager;
    CommandManager commandManager(&networkManager);
    
    QQmlApplicationEngine engine;
    
    // Set screen size information to be accessed from QML
    QScreen *screen = QGuiApplication::primaryScreen();
    engine.rootContext()->setContextProperty("screenWidth", screen->size().width());
    engine.rootContext()->setContextProperty("screenHeight", screen->size().height());
    
    engine.rootContext()->setContextProperty("commandManager", &commandManager);
    engine.rootContext()->setContextProperty("networkManager", &networkManager);
    
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    
    engine.load(url);
    
    return app.exec();
}
