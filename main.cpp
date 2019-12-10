#include "mcawindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MCAWindow w;
    w.show();

    return a.exec();
}
