#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QLocalServer>
#include <QLocalSocket>
#include <QDataStream>
#include <string>
#include <QRect>

class server : public QObject
{
    Q_OBJECT

public:
    explicit server(QObject *parent = nullptr);
    void geometryHandler(QRect windowRect);

    QByteArray qByteX;
    QByteArray qByteY;
    QByteArray qByteWidth;
    QByteArray qByteHeight;
    QByteArray qByteGeoPrefix = "G";


signals:


public slots:
    void startCommunication();
    void processVisibilityHandler(bool visibility);


private:
    QLocalServer *mServer;
    QLocalSocket *clientConnection;


};

#endif // SERVER_H
