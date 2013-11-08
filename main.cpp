#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setApplicationName("Lazy eye trainer");
    //QCoreApplication::setOrganizationName("");
    Window w;
    w.show();
    
    return a.exec();
}
