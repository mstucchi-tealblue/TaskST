#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QLocalSocket>
#include <QDataStream>
#include <typeinfo>


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

public:
    explicit client(QString initialHeight, QString  initialWidth, QString  wrapperWindowHeight, QString windowX, QString windowY, QObject *parent = nullptr);

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

signals:
    void receivedFromServerChanged();
    void windowHeightChanged();
    void windowWidthChanged();
    void windowXChanged();
    void windowYChanged();
    void windowVisibilityChanged();

public slots:
    inline void readContentFromServer();

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
};

#endif // CLIENT_H

