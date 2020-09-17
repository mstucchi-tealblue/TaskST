#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QLocalSocket>
#include <QDebug>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

    void connect();
    void setReceivedText(QString);
    QString getReceivedText();

signals:

public slots:

private:
    QLocalSocket *socket;
    QString receivedText;

};

#endif // CLIENT_H
