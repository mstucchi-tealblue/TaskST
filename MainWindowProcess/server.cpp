#include "server.h"

server::server(QObject *parent) : QObject(parent)
{
    mServer = new QLocalServer(this);

    if (!mServer->listen("ServerName")) {
        qDebug() << "Server could not start!";
        qDebug() << mServer->errorString();
        return;

    } else {
        qDebug() << "Server started";
    }

    connect(mServer, &QLocalServer::newConnection, this, &server::startCommunication);
}

void server::geometryHandler(QRect windowRect)
{
    QByteArray qByteX;
    QByteArray qByteY;
    QByteArray qByteWidth;
    QByteArray qByteHeight;

    QByteArray qByteGeoPrefix = "G";

    qByteX.setNum(windowRect.x());
    qByteY.setNum(windowRect.y()+50);
    qByteWidth.setNum(windowRect.width());
    qByteHeight.setNum(windowRect.height()-50);

    clientConnection->write(qByteGeoPrefix + qByteX + qByteGeoPrefix + qByteY + qByteGeoPrefix + qByteWidth + qByteGeoPrefix  + qByteHeight );
    clientConnection->flush();
}

void server::processVisibilityHandler(bool visibility)
{
    if(visibility)
        clientConnection->write("Vis-true");
    else
        clientConnection->write("Vis-false");

    clientConnection->flush();
}

//Slots:
void server::startCommunication()
{
    clientConnection = mServer->nextPendingConnection();
}



