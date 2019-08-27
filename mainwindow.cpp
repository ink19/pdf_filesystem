#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->m_FileWindow = new FileWindow(this);
    
}



MainWindow::~MainWindow()
{
    delete ui;
}
