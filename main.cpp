#include "qreadmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QReadMain w;
    w.show();
    
    return a.exec();
}
