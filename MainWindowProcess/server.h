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
    void disconnect();

public slots:
    void connection();
    void sendSomethingDifferent();
    void heightHandler();

private:
    QLocalServer *server;
    QLocalSocket *socket;

};

#endif // SERVER_H
