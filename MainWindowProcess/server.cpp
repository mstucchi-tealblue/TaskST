#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    server = new QLocalServer(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(sendSomething()));

    if(!server->listen("mainWindowServer"))
    {
        qDebug() << "Server could not start!";
    } else {
        qDebug() << "Server started";
    }

}

void Server::sendSomething(){
    QLocalSocket *socket = server->nextPendingConnection();
    qDebug() << "Socket accettata";

    // qDebug() << server->serverError();

    socket->write("Hello client");
    socket->flush();

    socket->waitForBytesWritten(3000);

    socket->close();
}
