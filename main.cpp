#include "roofu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    roofU w;
    w.show();

    return a.exec();
}
