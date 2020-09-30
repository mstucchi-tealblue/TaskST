#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QLocalSocket>
#include <QDataStream>
#include <QTimer>
#include <typeinfo>


class client : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString receivedFromSever READ getReceivedFromServer WRITE setReceivedFromServer NOTIFY receivedFromServerChanged)
    Q_PROPERTY(int windowHeight READ getWindowHeight WRITE setWindowHeight NOTIFY windowHeightChanged)
    Q_PROPERTY(int windowWidth READ getWindowWidth WRITE setWindowWidth NOTIFY windowWidthChanged)
    Q_PROPERTY(int windowVisibility READ getWindowVisibility WRITE setWindowVisibility NOTIFY windowVisibilityChanged)
    Q_PROPERTY(int initialHeight READ getInitialHeight WRITE setInitialHeight)
    Q_PROPERTY(int initialWidth READ getInitialWidth WRITE setInitialWidth)
    Q_PROPERTY(int wrapperWindowHeight READ getWrapperWindowHeight WRITE setWrapperWindowHeight)

public:
    explicit client(QString initialHeight, QString  initialWidth, QString  wrapperWindowHeight, QObject *parent = nullptr);
    explicit client(QObject *parent = nullptr);

    // Getter and setter of the properties
    QString getReceivedFromServer() ;
    void setReceivedFromServer(QString fromServer) ;
    qint64 getWindowHeight() const;
    void setWindowHeight(const qint64 &value);
    qint64 getWindowWidth() const;
    void setWindowWidth(const qint64 &value);
    int getInitialHeight() const;
    void setInitialHeight(int value);
    int getInitialWidth() const;
    void setInitialWidth(int value);
    int getWrapperWindowHeight() const;
    void setWrapperWindowHeight(int value);
    bool getWindowVisibility() const;
    void setWindowVisibility(bool value);

signals:
    void receivedFromServerChanged();
    void windowHeightChanged();
    void windowWidthChanged();
    void windowVisibilityChanged();

public slots:
    void readWelcome();

private:
    QLocalSocket *socket;
    QString receivedFromSever;

    //Real-time dimension parameters
    qint64 windowHeight;
    qint64 windowWidth;
    bool windowVisibility = false;

    //Positioning parameters
    int initialHeight;
    int initialWidth;
    int wrapperWindowHeight;
};

#endif // CLIENT_H

