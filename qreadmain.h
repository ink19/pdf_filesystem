#ifndef QREADMAIN_H
#define QREADMAIN_H

#include <QMainWindow>
#include "mainwindow.h"

class QReadMain : public QMainWindow
{
    Q_OBJECT
public:
    explicit QReadMain(QWidget *parent = nullptr);
    MainWindow *main_win;
signals:
    
public slots:
};

#endif // QREADMAIN_H
