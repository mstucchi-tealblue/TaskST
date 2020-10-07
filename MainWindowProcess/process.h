#ifndef PROCESS_H
#define PROCESS_H

#include<QProcess>

class Process : public QObject {
    Q_OBJECT

public:
    Process(QString processName);

public slots:
    void startProcess(int mainWindowHeight,int height, int width,  int x, int y);
    void closeProcessHandler();

private:
    QProcess *process;
    QString name;
    int pid;
};

#endif // PROCESS_H
