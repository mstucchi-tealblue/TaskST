
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
        //QString program = "C:\\Users\\Matteo\\Documents\\QtProjects\\build-SecondProcess-Desktop_Qt_5_15_0_MSVC2019_64bit-Release\\SecondProcess.exe";
        //QString workingDir = "C:\\Users\Matteo\\Documents\\QtProjects\\SecondProcess";

        //Linux
        QString program = "/home/matteo/build-browserWindowProcess-Desktop-Debug/browserWindowProcess";
        QString workingDir = "/home/matteo/Desktop/InteractionBetweenTwoProcesses/SecondProcess";

        QStringList arguments;

        qDebug() << mainWindowsHeight << height << width;
        arguments << QString::number(mainWindowsHeight)<< QString::number(height) << QString::number(width);

        qint64 pid;
        process->startDetached(program, arguments, workingDir, &pid);
    }


}
