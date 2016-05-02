#include "roofu.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Toploengineering-VV Ltd.");
    QCoreApplication::setOrganizationDomain("hvac-bg.com");
    QCoreApplication::setApplicationName("roofU");
    QCoreApplication::setApplicationVersion("1.0.0");

    QTranslator translator;
#if defined(Q_OS_MAC)
    translator.load(QApplication::applicationDirPath().append("/../Resources/roofu_bg"));
#else
    translator.load("roofu_bg");
#endif

    a.installTranslator(&translator);
    roofU w;
    w.show();

    return a.exec();
}
