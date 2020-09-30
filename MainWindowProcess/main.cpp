#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QProcess>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQuickWindow>
#include <QObject>
#include <QSignalMapper>
#include <Windows.h>
#include "process.h"
#include "server.h"



int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    server *mServer = new server(&app);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QQmlContext* context = engine.rootContext();

    Process browserProcess(QString("browserProcess"));

    context->setContextProperty("mServer",mServer);
    context->setContextProperty("pid",QCoreApplication::applicationPid());


    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    //It is for managing the Qml window from c++
    auto topLevelObject = engine.rootObjects().value(0);
    auto window = qobject_cast<QQuickWindow *>(topLevelObject);
    window->show();

    //Start the process unvisible
    browserProcess.startProcess(window->height(),window->height()-50, window->width());

    QObject::connect(window, &QQuickWindow::heightChanged, [&](){
    mServer->heightChangedHandler(window->height()-50);
    });

    QObject::connect(window, &QQuickWindow::widthChanged, [&](){
    mServer->widthChangedHandler(window->width());
    });


    return app.exec();
}
