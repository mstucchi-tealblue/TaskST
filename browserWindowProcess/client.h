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
    Q_PROPERTY(int windowHeight READ getWindowHeight WRITE setWindowHeight NOTIFY windowHeightChanged)
    Q_PROPERTY(int windowWidth READ getWindowWidth WRITE setWindowWidth NOTIFY windowWidthChanged)
    Q_PROPERTY(int windowX READ getWindowX WRITE setWindowX NOTIFY windowXChanged)
    Q_PROPERTY(int windowY READ getWindowY WRITE setWindowY NOTIFY windowYChanged)
    Q_PROPERTY(int windowVisibility READ getWindowVisibility WRITE setWindowVisibility NOTIFY windowVisibilityChanged)
    Q_PROPERTY(int initialHeight READ getInitialHeight WRITE setInitialHeight)
    Q_PROPERTY(int initialWidth READ getInitialWidth WRITE setInitialWidth)
    Q_PROPERTY(int wrapperWindowHeight READ getWrapperWindowHeight WRITE setWrapperWindowHeight)
    Q_PROPERTY(int initialX READ getInitialX WRITE setInitialX)
    Q_PROPERTY(int initialY READ getInitialY WRITE setInitialY)

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
    QList<QByteArray> getDimensionsReceivedFromServer() const;
    void setDimensionsReceivedFromServer(const QList<QByteArray> &value);
    short getWindowHeight() const;
    void setWindowHeight(const short &value);
    short getWindowWidth() const;
    void setWindowWidth(const short &value);
    bool getWindowVisibility() const;
    void setWindowVisibility(bool value);
    short getWindowX() const;
    void setWindowX(const short &value);
    short getWindowY() const;
    void setWindowY(const short &value);
    int getInitialHeight() const;
    void setInitialHeight(int value);
    int getInitialWidth() const;
    void setInitialWidth(int value);
    int getWrapperWindowHeight() const;
    void setWrapperWindowHeight(int value);
    int getInitialX() const;
    void setInitialX(int value);
    int getInitialY() const;
    void setInitialY(int value);


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
    void windowHeightChanged();
    void windowWidthChanged();
    void windowXChanged();
    void windowYChanged();
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
    QList<QByteArray> dimensionsReceivedFromServer;

    //Real-time dimension parameters
    short windowHeight;
    short windowWidth;
    short windowX;
    short windowY;
    bool windowVisibility = false;


    //Initial positioning parameters
    int initialHeight;
    int initialWidth;
    int initialX;
    int initialY;
    int wrapperWindowHeight;


    QSharedPointer<SimpleSwitchReplica> reptr;// holds reference to replica

    QRect internalProcessWindow = QRect(50,50,300,300); //holds received server window size
    int internalProcessWindowHeight;
    int internalProcessWindowWidth;
    int internalProcessWindowX;
    int internalProcessWindowY;
};

#endif // CLIENT_H


