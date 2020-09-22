#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    server = new QLocalServer(this);

    //Every time a socket connects to the server, it executes connection() slot.
    connect(server,SIGNAL(newConnection()),this,SLOT(connection()));

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
    //That establish a socket that we use to communicate with client.
    socket = server->nextPendingConnection();
    qDebug() << "A client is connected";

        socket->write("Hello client");
        socket->flush();
        socket->waitForBytesWritten(3000);

}

//Triggered when signals are emitted
void Server::heightHandler(int height)
{
    bool permissionToWrite = checkHeight(height);
    if(permissionToWrite)
    {
        socket->write("sasasa");
        socket->flush();
    }
}

void Server::simpleMessage(int height)
{
    socket->write("xaxaxaxa");
    socket->flush();
    //socket->waitForBytesWritten(3000);
}

bool Server::checkHeight(int newHeight)
{
    qDebug() << newHeight;
    if(oldHeight == 0)
    {
        oldHeight = newHeight;
        return false;
    }

    if(newHeight-oldHeight > 100)
        return true;
    return false;
}


