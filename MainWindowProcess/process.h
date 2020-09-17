#ifndef PROCESS_H
#define PROCESS_H

#include<QProcess>
#include<QDebug>


class Process : public QObject {
    Q_OBJECT

public:
    Process(QString processName);

public slots:
    void startProcessFromQml(int mainWindowHeight,int height, int width);
    void killProcessFromQml();

private:
    QProcess *process;
    QString name;
    int pid;
};

#endif // PROCESS_H
