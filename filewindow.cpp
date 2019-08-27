#include "filewindow.h"

FileWindow::FileWindow(QWidget *parent) : QWidget(parent)
{
    
}

int FileWindow::mresize(const QSize& size)
{
    this->resize(size);
}
