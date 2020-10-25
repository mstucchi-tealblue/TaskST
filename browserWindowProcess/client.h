#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QLocalSocket>
#include <QDataStream>
#include <typeinfo>
#include <QSharedPointer>
#include <QRect>

#include "../build-browserWindowProcess-Desktop_Qt_5_15_1_MSVC2015_64bit-Debug/rep_simpleswitch_replica.h"

class client : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QByteArray receivedFromSever READ getReceivedFromServer WRITE setReceivedFromServer NOTIFY receivedFromServerChanged)
    Q_PROPERTY(int windowVisibility READ getWindowVisibility WRITE setWindowVisibility NOTIFY windowVisibilityChanged)
    Q_PROPERTY(QRect internalProcessWindow READ getInternalProcessWindow WRITE setInternalProcessWindow NOTIFY internalProcessWindowChanged)
    Q_PROPERTY(int internalProcessWindowHeight READ getInternalProcessWindowHeight WRITE setInternalProcessWindowHeight NOTIFY internalProcessWindowHeightChanged)
    Q_PROPERTY(int internalProcessWindowWidth READ getInternalProcessWindowWidth WRITE setInternalProcessWindowWidth NOTIFY internalProcessWindowWidthChanged)
    Q_PROPERTY(int internalProcessWindowX READ getInternalProcessWindowX WRITE setInternalProcessWindowX NOTIFY internalProcessWindowXChanged)
    Q_PROPERTY(int internalProcessWindowY READ getInternalProcessWindowY WRITE setInternalProcessWindowY NOTIFY internalProcessWindowYChanged)

public:
    explicit client(QString initialHeight, QString  initialWidth, QString  wrapperWindowHeight, QString windowX, QString windowY, QObject *parent = nullptr);

    client(QSharedPointer<SimpleSwitchReplica> ptr);
    ~client();

    void initConnections();// Function to connect signals and slots of source and client

    // Getter and setter of the properties
    QByteArray getReceivedFromServer();
    inline void setReceivedFromServer(QByteArray fromServer) ;
    bool getWindowVisibility() const;
    void setWindowVisibility(bool value);    
    QRect getInternalProcessWindow() ;
    void setInternalProcessWindow( QRect &value);
    int getInternalProcessWindowX() const;
    void setInternalProcessWindowX(int value);
    int getInternalProcessWindowY() const;
    void setInternalProcessWindowY(int value);
    int getInternalProcessWindowHeight() const;
    void setInternalProcessWindowHeight(int value);
    int getInternalProcessWindowWidth() const;
    void setInternalProcessWindowWidth(int value);


signals:
    void receivedFromServerChanged();
    void windowVisibilityChanged();
    void internalProcessWindowChanged();
    void internalProcessWindowHeightChanged();
    void internalProcessWindowWidthChanged();
    void internalProcessWindowXChanged();
    void internalProcessWindowYChanged();

public slots:
    //Client is connect via socket to server, the only thing that comes from it is visibility property, we handle this with the following method:
    inline void readContentFromServer();

    //This method is for updating the window geometry every time the external one changes size or position
    void setLocalGeometry_slot(QRect windowGeometry); // slot to receive window size

private:
    //Component for visibility update via socket
    QLocalSocket *socket;
    QByteArray receivedFromSever;

    //Component for QtRO, window size and position update
    QSharedPointer<SimpleSwitchReplica> reptr;// holds reference to replica

    //Real-time parameters
    bool windowVisibility = false;
    QRect internalProcessWindow; //holds received server window size
    int internalProcessWindowHeight;
    int internalProcessWindowWidth;
    int internalProcessWindowX;
    int internalProcessWindowY;
};

#endif // CLIENT_H


