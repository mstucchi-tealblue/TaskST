#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QWindow>
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    Client mClient;
    mClient.connect();

    QString passedMainHeight = argv[1];
    QString passedHeight = argv[2];
    QString passedWidth = argv[3];

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("pid",QCoreApplication::applicationPid());
    engine.rootContext()->setContextProperty("receivedText",mClient.getReceivedText());
    engine.rootContext()->setContextProperty("passedMainHeight",passedMainHeight);
    engine.rootContext()->setContextProperty("passedHeight",passedHeight);
    engine.rootContext()->setContextProperty("passedWidth",passedWidth);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);



    return app.exec();
}
