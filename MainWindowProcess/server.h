#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QLocalServer>
#include <QLocalSocket>
#include <Windows.h>


class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void heightHandler(int height);
    void simpleMessage(int height);



signals:
    void disconnect();

public slots:
    void connection();


private:
    QLocalServer *server;
    QLocalSocket *socket;

    int oldHeight = 0;
    bool checkHeight(int newHeight);

};

#endif // SERVER_H
