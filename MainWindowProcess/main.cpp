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

    Server *mServer = new Server(&app);



    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QQmlContext* context = engine.rootContext();

    Process browserProcess(QString("browserProcess"));
    context->setContextProperty("browserProcess",&browserProcess);
    context->setContextProperty("localServer",mServer);
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
    //qDebug() << window->width() << window->height();
    QRect defaultGeom = window->geometry();
    qDebug()<<defaultGeom;

    QObject::connect(window, &QQuickWindow::heightChanged, [&](){
        mServer->heightHandler(window->height());
    });

    QObject::connect(window, &QQuickWindow::colorChanged, [&](){
        mServer->simpleMessage(window->height());
    });

    //QObject::connect(window, &QQuickWindow::close, &browserProcess, &Process::killProcess);



//    while(defaultGeom != window->geometry())
//    qDebug()<<window->x() <<window->y();







    return app.exec();
}
