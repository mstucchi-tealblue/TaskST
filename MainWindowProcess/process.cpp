
#include "process.h"
#include<QDebug>

Process::Process(QString processName)
{
    name = processName;
}

void Process::startProcessFromQml(int mainWindowsHeight, int height, int width)
{
    QObject *parent = 0;
    process = new QProcess(parent);

    if(this->name == QString("browserProcess")){
        //Windows
        QString program = "C:\\Users\\Matteo\\Documents\\QtProjects\\TaskST\\build-browserWindowProcess-Desktop_Qt_5_15_1_MSVC2015_64bit-Debug\\browserWindowProcess.exe";
        QString workingDir = "C:\\Users\\Matteo\\Documents\\QtProjects\\SecondProcess";

        //Linux
        //QString program = "/home/matteo/build-browserWindowProcess-Desktop-Debug/browserWindowProcess";
        //QString workingDir = "/home/matteo/Desktop/InteractionBetweenTwoProcesses/SecondProcess";

        QStringList arguments;

        qDebug() << mainWindowsHeight << height << width;
        arguments << QString::number(mainWindowsHeight)<< QString::number(height) << QString::number(width);

        qint64 pid;
        process->startDetached(program, arguments, workingDir, &pid);
    }


}
