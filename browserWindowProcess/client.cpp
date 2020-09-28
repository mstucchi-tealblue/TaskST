#include "client.h"

client::client(QObject *parent) : QObject(parent){ }

client::client(QString  initialHeight, QString  initialWidth, QString  wrapperWindowHeight, QObject *parent) : QObject(parent)
{
    socket = new QLocalSocket(this);
    connect(socket, &QLocalSocket::readyRead, this, &client::readWelcome);
    socket->connectToServer("ServerName");

    setInitialHeight(initialHeight.toInt());
    setInitialWidth(initialWidth.toInt());
    setWrapperWindowHeight(wrapperWindowHeight.toInt());
    setWindowHeight(initialHeight.toInt());
    setWindowWidth(initialWidth.toInt());
}

//Server incoming contents handlers
void client::readWelcome()
{
    setReceivedFromServer(socket->readAll());
    qDebug() << receivedFromSever;
}

void client::setReceivedFromServer(QString fromServer)
{
    //Height handler
    if(fromServer.at(0) == "h")
    {
        fromServer.remove(0,1);
        setWindowHeight(fromServer.toInt());
        return;
    }

    //Width handler
    if(fromServer.at(0) == "w")
    {
        fromServer.remove(0,1);
        setWindowWidth(fromServer.toInt());
        return;
    }

    //Textual content handler (Patient...)
    if (fromServer != receivedFromSever) {
        receivedFromSever = fromServer;
        emit receivedFromServerChanged();
    }
}



//Getters and setters implementation

int client::getInitialWidth() const
{
    return initialWidth;
}

void client::setInitialWidth(int value)
{
    initialWidth = value;
}

int client::getInitialHeight() const
{
    return initialHeight;
}

void client::setInitialHeight(int value)
{
    initialHeight = value;
}

int client::getWrapperWindowHeight() const
{
    return wrapperWindowHeight;
}

void client::setWrapperWindowHeight(int value)
{
    wrapperWindowHeight = value;
}

qint64 client::getWindowWidth() const
{
    return windowWidth;
}

void client::setWindowWidth(const qint64 &value)
{
    windowWidth = value;
    emit windowWidthChanged();
}

qint64 client::getWindowHeight() const
{
    return windowHeight;
}

void client::setWindowHeight(const qint64 &value)
{
    windowHeight = value;
    emit windowHeightChanged();
}

QString client::getReceivedFromServer()
{
    return receivedFromSever;
}


