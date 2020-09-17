#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{

}

void Client::connect()
{

    socket = new QLocalSocket();

    socket->connectToServer("mainWindowServer");

    if(socket->waitForConnected(3000))
    {
        qDebug() << "Connected";

        socket->write("Hello server \r\n\r\n\r\n\r\n");

        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);

        //qDebug() << "Reading: " << socket->bytesAvailable();

        setReceivedText(socket->readAll());

        socket->close();
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
