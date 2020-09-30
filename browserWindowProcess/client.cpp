#include "client.h"

client::client(QObject *parent) : QObject(parent){ }

client::client(QString  initialHeight, QString  initialWidth, QString  wrapperWindowHeight, QString windowX, QString windowY, QObject *parent) : QObject(parent)
{
    socket = new QLocalSocket(this);
    connect(socket, &QLocalSocket::readyRead, this, &client::readWelcome);
    socket->connectToServer("ServerName");

    setInitialHeight(initialHeight.toInt());
    setInitialWidth(initialWidth.toInt());
    setWrapperWindowHeight(wrapperWindowHeight.toInt());
    setWindowHeight(initialHeight.toInt());
    setWindowWidth(initialWidth.toInt());
    setWindowX(windowX.toInt());
    setWindowY(windowY.toInt());
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

    //X Handler
    if(fromServer.at(0) == "x")
    {
        fromServer.remove(0,1);
        setWindowX(fromServer.toInt());
        return;
    }

    if(fromServer.at(0) == "y")
    {
        fromServer.remove(0,1);
        setWindowY(fromServer.toInt());
        return;
    }

    //Visibility handler
    if(fromServer.mid(0,4) == "Vis-")
    {
        fromServer.remove(0,4);
        if(fromServer == "true")
            setWindowVisibility(true);

        if(fromServer == "false")
            setWindowVisibility(false);
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

bool client::getWindowVisibility() const
{
    return windowVisibility;
}

void client::setWindowVisibility(bool value)
{
    windowVisibility = value;
    emit windowVisibilityChanged();
}

qint64 client::getWindowX() const
{
    return windowX;
}

void client::setWindowX(const qint64 &value)
{
    windowX = value;
    emit windowXChanged();
}

qint64 client::getWindowY() const
{
    return windowY;
}

void client::setWindowY(const qint64 &value)
{
    windowY = value;
    emit windowYChanged();
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


