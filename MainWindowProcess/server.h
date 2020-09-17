#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QLocalServer>
#include <QLocalSocket>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);


signals:

public slots:
    void sendSomething();

private:
    QLocalServer *server;

};

#endif // SERVER_H
