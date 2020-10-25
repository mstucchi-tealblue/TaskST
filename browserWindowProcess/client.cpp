#include "client.h"

client::client(QSharedPointer<SimpleSwitchReplica> ptr) :
    QObject(nullptr),reptr(ptr)
{
    initConnections();
}

client::client(QString  initialHeight, QString  initialWidth, QString  wrapperWindowHeight, QString windowX, QString windowY, QObject *parent) : QObject(parent)
{
    socket = new QLocalSocket(this);
    connect(socket, &QLocalSocket::readyRead, this, &client::readContentFromServer);
    socket->connectToServer("ServerName");

    setInternalProcessWindow(QRect(windowX.toInt(),windowY.toInt(),initialWidth.toInt(),initialHeight.toInt()));
    setInternalProcessWindowHeight(initialHeight.toInt()-50);
    setInternalProcessWindowWidth(initialWidth.toInt());
    setInternalProcessWindowX(windowX.toInt());
    setInternalProcessWindowY(windowY.toInt()+50);

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

int client::getInternalProcessWindowWidth() const
{
    return internalProcessWindowWidth;
}

void client::setInternalProcessWindowWidth(int value)
{
    internalProcessWindowWidth = value;
    Q_EMIT internalProcessWindowWidthChanged();
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

QRect client::getInternalProcessWindow() const
{
    return internalProcessWindow;
}

void client::setInternalProcessWindow(const QRect &value)
{
    internalProcessWindow = value;
}



//Server incoming contents handlers
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

//Getters and setters implementation


bool client::getWindowVisibility() const
{
    return windowVisibility;
}

void client::setWindowVisibility(bool value)
{
    windowVisibility = value;
    emit windowVisibilityChanged();
}


QByteArray client::getReceivedFromServer()
{
    return receivedFromSever;
}



