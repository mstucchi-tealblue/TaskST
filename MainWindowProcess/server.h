#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QLocalServer>
#include <QLocalSocket>
#include <QDataStream>
#include <string>

class server : public QObject
{
    Q_OBJECT

public:
    explicit server(QObject *parent = nullptr);

    void heightChangedHandler(int height);
    void widthChangedHandler(int width);
    void xChangeHandler(int x);
    void yChangeHandler(int y);

    // Setters and getters
    qint64 getWindowHeight() const;
    void setWindowHeight(qint64 value);
    qint64 getWindowWidth() const;
    void setWindowWidth(qint64 value);

signals:


public slots:
    void sendWelcome();
    void processVisibilityHandler(bool visibility);

private:
    QLocalServer *mServer;
    QLocalSocket *clientConnection;
    qint64 windowHeight = 0;
    qint64 windowWidth = 0;

};

#endif // SERVER_H
