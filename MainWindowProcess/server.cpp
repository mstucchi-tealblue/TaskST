#include "server.h"

server::server(QObject *parent) : QObject(parent)
{
    mServer = new QLocalServer(this);

    if (!mServer->listen("ServerName")) {
        qDebug() << "Server could not start!";
        qDebug() << mServer->errorString();
        return;

    } else {
        qDebug() << "Server started";
    }

    connect(mServer, &QLocalServer::newConnection, this, &server::sendWelcome);
}

// Height and width updaters
void server::heightChangedHandler(int height)
{
    //setWindowHeight(height);
    qDebug() << "External height:" << height;

    QByteArray qByteHeight;
    QByteArray qBytePrefix;

    qByteHeight.setNum(height);
    qBytePrefix = "h";
    clientConnection->write(qBytePrefix + qByteHeight);
    clientConnection->flush();

}

void server::widthChangedHandler(int width)
{
    //setWindowWidth(width);

    qDebug() << "External width:" << width;

    QByteArray qByteWidth;
    QByteArray qBytePrefix;

    qByteWidth.setNum(width);
    qBytePrefix = "w";
    clientConnection->write(qBytePrefix + qByteWidth);
    clientConnection->flush();
}

void server::xChangeHandler(int x)
{

    qDebug() << "External x:" << x;
    QByteArray qByteX;
    QByteArray qBytePrefix;

    qByteX.setNum(x);
    qBytePrefix = "x";
    clientConnection->write(qBytePrefix + qByteX);
    clientConnection->flush();
}

void server::yChangeHandler(int y)
{

    qDebug() << "External y" << y;
    QByteArray qByteY;
    QByteArray qBytePrefix;

    qByteY.setNum(y);
    qBytePrefix = "y";
    clientConnection->write(qBytePrefix + qByteY);
    clientConnection->flush();
}

void server::geometryHandler(QRect windowRect)
{
    QByteArray qByteX;
    QByteArray qByteY;
    QByteArray qByteWidth;
    QByteArray qByteHeight;

    QByteArray qByteGeoPrefix = "G";


    qByteX.setNum(windowRect.x());
    qByteY.setNum(windowRect.y());
    qByteWidth.setNum(windowRect.width());
    qByteHeight.setNum(windowRect.height());

    qDebug()<<qByteGeoPrefix + qByteX + qByteGeoPrefix + qByteY + qByteGeoPrefix + qByteWidth + qByteGeoPrefix  + qByteHeight  ;
    clientConnection->write(qByteGeoPrefix + qByteX + qByteGeoPrefix + qByteY + qByteGeoPrefix + qByteWidth + qByteGeoPrefix  + qByteHeight );
    clientConnection->flush();
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
void server::sendWelcome()
{
    clientConnection = mServer->nextPendingConnection();
    //    connect(clientConnection, &QLocalSocket::disconnected, clientConnection, &QLocalSocket::deleteLater);
    clientConnection->write("Welcome client");
    clientConnection->flush();
}

// Getters and setters implementation
qint64 server::getWindowWidth() const
{
    return windowWidth;
}

void server::setWindowWidth(qint64 value)
{
    windowWidth = value;
}

qint64 server::getWindowHeight() const
{
    return windowHeight;
}

void server::setWindowHeight(qint64 value)
{
    if (value != windowHeight) {
        windowHeight = value;
    }
}


