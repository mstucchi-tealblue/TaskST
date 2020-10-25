#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QProcess>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQuickWindow>
#include <QObject>
#include <QCoreApplication>
#include "process.h"
#include "server.h"
#include "simpleswitch.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    server *mServer = new server(&app);
    Process browserProcess(QString("browserProcess"));

    SimpleSwitch srcSwitch; // create the object to share
    QRemoteObjectHost srcNode(QUrl(QStringLiteral("local:switch"))); // create host node to share it
    srcNode.enableRemoting(&srcSwitch); // enable remoting/sharing

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QQmlContext* context = engine.rootContext();    

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

    //Start the process invisible
    browserProcess.startProcess(window->height(),window->height()-50, window->width(), window->x(), window->y()+50);


    //Change the share window size and position
    QObject::connect(window, &QQuickWindow::heightChanged, [&](){
    srcSwitch.setGeometry(window->geometry());
    });

    QObject::connect(window, &QQuickWindow::widthChanged, [&](){
    srcSwitch.setGeometry(window->geometry());
    });

    QObject::connect(window, &QQuickWindow::xChanged, [&](){
    srcSwitch.setGeometry(window->geometry());
    });

    QObject::connect(window, &QQuickWindow::yChanged, [&](){
    srcSwitch.setGeometry(window->geometry());
    });

    QObject::connect(context, &QQmlContext::destroyed, [&](){
    browserProcess.closeProcessHandler();
    });










    return app.exec();
}
