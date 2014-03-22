#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setApplicationName("floating-pictures");
    //QCoreApplication::setOrganizationName("");
    Window w;
    w.show();
    
    return a.exec();
}
