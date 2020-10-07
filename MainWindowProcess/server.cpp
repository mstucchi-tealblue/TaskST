#include "server.h"

server::server(QObject *parent) : QObject(parent)
{
    mServer = new QLocalServer(this);

    if (!mServer->listen("ServerName")) {
        qDebug() << "Server could not start!";
        qDebug() << mServer->errorString();
        return;
    }
    else {
        qDebug() << "Server started";
    }

    connect(mServer, &QLocalServer::newConnection, this, &server::startCommunication);
}


void server::geometryHandler(QRect windowRect)
{
    setQByteX(windowRect.x());
    qByteY.setNum(windowRect.y()+50);
    qByteWidth.setNum(windowRect.width());
    qByteHeight.setNum(windowRect.height()-50);

    clientConnection->write(qByteGeoPrefix + qByteX + qByteGeoPrefix + qByteY + qByteGeoPrefix + qByteWidth + qByteGeoPrefix  + qByteHeight );
    clientConnection->flush();

    return;
}

void server::processVisibilityHandler(bool visibility)
{
    if(visibility)
        clientConnection->write("Vis-true");
    else
        clientConnection->write("Vis-false");

    clientConnection->flush();
}

QByteArray server::getQByteHeight() const
{
    return qByteHeight;
}

void server::setQByteHeight(const int value)
{
    qByteHeight.setNum(value);
}

QByteArray server::getQByteWidth() const
{
    return qByteWidth;
}

void server::setQByteWidth(const int value)
{
    qByteWidth.setNum(value);
}

QByteArray server::getQByteY() const
{
    return qByteY;
}

void server::setQByteY(const int value)
{
    qByteY.setNum(value);
}

QByteArray server::getQByteX() const
{
    return qByteX;
}

void server::setQByteX(const int value)
{
    qByteX.setNum(value);
}

//Slots:
void server::startCommunication()
{
    clientConnection = mServer->nextPendingConnection();
}



