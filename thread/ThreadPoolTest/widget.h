#ifndef WIDGET_H
#define WIDGET_H

#include <QObject>
#include <QRunnable>

namespace Ui {
class Widget;
}

class Widget : public QObject, public QRunnable
{
    Q_OBJECT

public:
    explicit Widget();
    ~Widget();

protected:
    void run();

signals:
    void mySignal();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
