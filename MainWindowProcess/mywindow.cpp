#include "mywindow.h"

mywindow::mywindow(QQuickWindow *parent) : QQuickWindow(parent)
{

}

void mywindow::resizeEvent(QResizeEvent *ev)
{
    qDebug() << "Event size: "<< ev->size();
    //QQuickWindow::resizeEvent(ev);
    return;
}
