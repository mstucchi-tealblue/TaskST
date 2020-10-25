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
    Q_PROPERTY(int internalProcessWindowHeight READ getInternalProcessWindowHeight WRITE setInternalProcessWindowHeight NOTIFY internalProcessWindowHeightChanged)
    Q_PROPERTY(int internalProcessWindowWidth READ getInternalProcessWindowWidth WRITE setInternalProcessWindowWidth NOTIFY internalProcessWindowWidthChanged)
    Q_PROPERTY(int internalProcessWindowX READ getInternalProcessWindowX WRITE setInternalProcessWindowX NOTIFY internalProcessWindowXChanged)
    Q_PROPERTY(int internalProcessWindowY READ getInternalProcessWindowY WRITE setInternalProcessWindowY NOTIFY internalProcessWindowYChanged)

public:
    explicit client(QString initialHeight, QString  initialWidth, QString  wrapperWindowHeight, QString windowX, QString windowY, QObject *parent = nullptr);

    client(QSharedPointer<SimpleSwitchReplica> ptr);
    ~client();

    // Getter and setter of the properties
    QByteArray getReceivedFromServer();
    inline void setReceivedFromServer(QByteArray fromServer) ;

    bool getWindowVisibility() const;
    void setWindowVisibility(bool value);


    void initConnections();// Function to connect signals and slots of source and client
    QRect getInternalProcessWindow() const;
    void setInternalProcessWindow(const QRect &value);
    int getInternalProcessWindowHeight() const;
    void setInternalProcessWindowHeight(int value);
    int getInternalProcessWindowWidth() const;
    void setInternalProcessWindowWidth(int value);
    int getInternalProcessWindowX() const;
    void setInternalProcessWindowX(int value);
    int getInternalProcessWindowY() const;
    void setInternalProcessWindowY(int value);


signals:
    void receivedFromServerChanged();
    void windowVisibilityChanged();

    void internalProcessWindowHeightChanged();
    void internalProcessWindowWidthChanged();
    void internalProcessWindowXChanged();
    void internalProcessWindowYChanged();

public slots:
    inline void readContentFromServer();

    void setLocalGeometry_slot(QRect windowGeometry); // slot to receive window size

private:
    QLocalSocket *socket;
    QByteArray receivedFromSever;

    //Real-time parameters
    bool windowVisibility = false;


    QSharedPointer<SimpleSwitchReplica> reptr;// holds reference to replica

    QRect internalProcessWindow = QRect(); //holds received server window size
    int internalProcessWindowHeight;
    int internalProcessWindowWidth;
    int internalProcessWindowX;
    int internalProcessWindowY;


};

#endif // CLIENT_H


