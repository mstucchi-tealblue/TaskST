#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QLocalServer>
#include <QLocalSocket>
#include <QRect>

class server : public QObject
{
    Q_OBJECT

public:
    explicit server(QObject *parent = nullptr);

public slots:
    void startSocketCommunication();
    void processVisibilityHandler(bool visibility);

private:
    QLocalServer *mServer;
    QLocalSocket *clientConnection;

};

#endif // SERVER_H
