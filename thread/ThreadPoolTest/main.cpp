#include "widget.h"
#include <QApplication>

#include <QThreadPool>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QThreadPool pool;
    pool.setMaxThreadCount(5);

    for (int i = 0; i < 20; i++)
    {
        pool.start(new Widget());
    }

    return a.exec();
}
