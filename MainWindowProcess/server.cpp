#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    server = new QLocalServer(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(connection()));

    //connect(server,SIGNAL(Server::disconnect()),this,SLOT(sendSomethingDifferent()));

    if(!server->listen("mainWindowServer"))
    {
        qDebug() << "Server could not start!";
        qDebug() << server->errorString();
    } else {
        qDebug() << "Server started";
        if(!server->isListening())
            emit disconnect();
    }
}

void Server::connection(){
    socket = server->nextPendingConnection();
    qDebug() << "A client is connected";

//    socket->write("Hello client");
//    socket->flush();

//    socket->waitForBytesWritten(3000);

//    socket->close();

}

void Server::sendSomethingDifferent(){}

void Server::heightHandler()
{
    socket->write("sasasa");
    socket->flush();
}


