#include "roofu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Toploengineering-VV Ltd.");
    QCoreApplication::setOrganizationDomain("hvac-bg.com");
    QCoreApplication::setApplicationName("roofU");
    QCoreApplication::setApplicationVersion("1.0.0");

    roofU w;
    w.show();

    return a.exec();
}
