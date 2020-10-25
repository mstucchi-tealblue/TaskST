
#include "process.h"

Process::Process(QString processName)
{
    name = processName;
}

void Process::startProcess(int mainWindowsHeight, int height, int width, int x, int y)
{
    QObject *parent = 0;
    process = new QProcess(parent);

    if(this->name == QString("browserProcess")){

        //Windows
        QString program = "C:\\Users\\Matteo\\Documents\\QtProjects\\TaskST\\build-browserWindowProcess-Desktop_Qt_5_15_1_MSVC2015_64bit-Debug\\browserWindowProcess.exe";

        //Linux
        //QString program = "/home/matteo/build-browserWindowProcess-Desktop-Debug/browserWindowProcess";

        // Give position to the client window
        QStringList arguments;
        arguments << QString::number(mainWindowsHeight)<< QString::number(height) << QString::number(width) << QString::number(x) << QString::number(y);
        process->start(program, arguments);
    }
}

void Process::closeProcessHandler()
{
    process->close();
}
