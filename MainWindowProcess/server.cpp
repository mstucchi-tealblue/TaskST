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

    connect(mServer, &QLocalServer::newConnection, this, &server::startSocketCommunication);
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
void server::startSocketCommunication()
{
    clientConnection = mServer->nextPendingConnection();
}



