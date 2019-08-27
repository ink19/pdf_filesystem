#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filewindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    FileWindow* m_FileWindow = nullptr;
    
private:
    Ui::MainWindow *ui;
    void resizeEvent(QResizeEvent *event);
};

#endif // MAINWINDOW_H
