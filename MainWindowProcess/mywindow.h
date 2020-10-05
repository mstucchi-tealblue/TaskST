#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QObject>
#include <QQuickWindow>
#include <QResizeEvent>
#include <QWindow>
#include <QEvent>


class mywindow : public QQuickWindow
{
    Q_OBJECT
public:
    explicit mywindow(QQuickWindow *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *ev) ;

signals:

};

#endif // MYWINDOW_H
