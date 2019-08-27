#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->resize(1280, 720);
    this->m_FileWindow = new FileWindow(this);
    //this->m_FileWindow->mresize(this->size());
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    if(this->m_FileWindow != nullptr) this->m_FileWindow->mresize(this->size());
}
