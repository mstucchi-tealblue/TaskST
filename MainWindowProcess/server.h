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
    void geometryHandler(QRect windowRect);

    QByteArray getQByteX() const;
    void setQByteX(const int value);
    QByteArray getQByteY() const;
    void setQByteY(const int value);
    QByteArray getQByteWidth() const;
    void setQByteWidth(const int value);
    QByteArray getQByteHeight() const;
    void setQByteHeight(const int value);

public slots:
    void startCommunication();
    void processVisibilityHandler(bool visibility);

private:
    QLocalServer *mServer;
    QLocalSocket *clientConnection;    
    QByteArray qByteX;
    QByteArray qByteY;
    QByteArray qByteWidth;
    QByteArray qByteHeight;
    const QByteArray qByteGeoPrefix = "G";

};

#endif // SERVER_H
