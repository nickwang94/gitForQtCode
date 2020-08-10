#include "widget.h"
#include <QApplication>
#include "shellprocess.h"

#define THREAD_SIZE 10

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.show();

    return a.exec();
}
