#include "client.h"

Client::Client(QObject *parent) : QObject(parent){
    socket = new QLocalSocket();
    socket->connectToServer("mainWindowServer");
    connect(socket, &QLocalSocket::readyRead, this, &Client::readText);
}



void Client::readText(){

    if(socket->waitForConnected(3000))
    {
        qDebug() << "Connected";
        socket->waitForReadyRead(3000);

        //qDebug() << "Reading: " << socket->bytesAvailable();

        setReceivedText(socket->readAll());
    } else
    {
        qDebug() << "Not connected";
    }
}

void Client::setReceivedText(QString textFromServer)
{
    receivedText = textFromServer;
}

QString Client::getReceivedText()
{
    return receivedText;
}
