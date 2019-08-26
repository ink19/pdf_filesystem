#include "qreadmain.h"

QReadMain::QReadMain(QWidget *parent) : QMainWindow(parent)
{
    this->main_win = new MainWindow(this);
    this->resize(this->main_win->size());
}
