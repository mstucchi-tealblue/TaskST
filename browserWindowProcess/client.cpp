#include "client.h"

client::client(QObject *parent) : QObject(parent){ }

client::client(QString  initialHeight, QString  initialWidth, QString  wrapperWindowHeight, QString windowX, QString windowY, QObject *parent) : QObject(parent)
{
    socket = new QLocalSocket(this);
    connect(socket, &QLocalSocket::readyRead, this, &client::readContentFromServer);
    socket->connectToServer("ServerName");

    setInitialHeight(initialHeight.toInt());
    setInitialWidth(initialWidth.toInt());
    setWrapperWindowHeight(wrapperWindowHeight.toInt());
    setInitialX(windowX.toInt());
    setInitialY(windowY.toInt());

    setWindowHeight(initialHeight.toInt());
    setWindowWidth(initialWidth.toInt());
    setWindowX(windowX.toInt());
    setWindowY(windowY.toInt());
}

//Server incoming contents handlers
void client::readContentFromServer()
{
    setReceivedFromServer(socket->readAll());
    qDebug() << receivedFromSever;
}

void client::setReceivedFromServer(QByteArray fromServer)
{
    if(fromServer.at(0) == 'G')
    {
        QList<QByteArray> dims = fromServer.split('G');
        setWindowX(dims.at(1).toInt());
        setWindowY(dims.at(2).toInt());
        setWindowWidth(dims.at(3).toInt());
        setWindowHeight(dims.at(4).toInt());
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
    }

    emit receivedFromServerChanged();
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

QByteArray client::getReceivedFromServer()
{
    return receivedFromSever;
}

int client::getInitialY() const
{
    return initialY;
}

void client::setInitialY(int value)
{
    initialY = value;
}

int client::getInitialX() const
{
    return initialX;
}

void client::setInitialX(int value)
{
    initialX = value;
}


