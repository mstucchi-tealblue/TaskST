#include "client.h"

client::client(QSharedPointer<SimpleSwitchReplica> ptr) :
    QObject(nullptr),reptr(ptr)
{
    initConnections();
}

client::client(QString  initialHeight, QString  initialWidth, QString  wrapperWindowHeight, QString windowX, QString windowY, QObject *parent) : QObject(parent)
{
    QRect* initialWindow = new QRect(windowX.toInt(),windowY.toInt(),initialWidth.toInt(),initialHeight.toInt());
    setInternalProcessWindow(*initialWindow);

    socket = new QLocalSocket(this);
    connect(socket, &QLocalSocket::readyRead, this, &client::readContentFromServer);
    socket->connectToServer("ServerName");
}

inline void client::readContentFromServer()
{
    setReceivedFromServer(socket->readAll());
}

inline void client::setReceivedFromServer(QByteArray fromServer)
{
    if(fromServer.at(0) == 'V') {
        fromServer.remove(0,4);

        if(fromServer == "true")
            setWindowVisibility(true);
        if(fromServer == "false")
            setWindowVisibility(false);
        return;
    }
    emit receivedFromServerChanged();
}

//destructor
client::~client()
{
}

void client::initConnections()
{
    // initialize connections between signals and slots
    // connect source replica signal currStateChanged() with client's recSwitchState() slot to receive source's current state
    QObject::connect(reptr.data(), &SimpleSwitchReplica::geometryChanged, [&](){
        setLocalGeometry_slot(reptr.data()->geometry());
    });
}

void client::setLocalGeometry_slot(QRect windowGeometry)
{
    qDebug() << "Geometria arrivata";
    setInternalProcessWindow(windowGeometry);
    setInternalProcessWindowHeight(getInternalProcessWindow().height()-50);
    setInternalProcessWindowWidth(getInternalProcessWindow().width());
    setInternalProcessWindowX(getInternalProcessWindow().x());
    setInternalProcessWindowY(getInternalProcessWindow().y()+50);

}

QByteArray client::getReceivedFromServer()
{
    return receivedFromSever;
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

QRect client::getInternalProcessWindow()
{
    return internalProcessWindow;
}

void client::setInternalProcessWindow(QRect &value)
{
    internalProcessWindow = value;
    Q_EMIT internalProcessWindowChanged();
}

int client::getInternalProcessWindowX() const
{
    return internalProcessWindowX;
}

void client::setInternalProcessWindowX(int value)
{
    internalProcessWindowX = value;
    Q_EMIT internalProcessWindowXChanged();
}

int client::getInternalProcessWindowY() const
{
    return internalProcessWindowY;
}

void client::setInternalProcessWindowY(int value)
{
    internalProcessWindowY = value;
    Q_EMIT internalProcessWindowYChanged();
}

int client::getInternalProcessWindowHeight() const
{
    return internalProcessWindowHeight;
}

void client::setInternalProcessWindowHeight(int value)
{
    internalProcessWindowHeight = value;
    Q_EMIT internalProcessWindowHeightChanged();
}

int client::getInternalProcessWindowWidth() const
{
    return internalProcessWindowWidth;
}

void client::setInternalProcessWindowWidth(int value)
{
    internalProcessWindowWidth = value;
    Q_EMIT internalProcessWindowWidthChanged();
}












