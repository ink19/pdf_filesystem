#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filepdflist.h"
#include "filepdfimagebuffer.h"
#include <QList>
#include "filepdfthumbitem.h"
#include <QGridLayout>
#include <QScrollArea>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
private:
    int draw();
    void resizeEvent(QResizeEvent *event);
    FilePDFList pdflist;
    QList<FilePDFThumbItem *> ThumbList;
    QGridLayout *_layout;
    QScrollArea *m_scroll_area;
    QWidget *m_area_widget;
};

#endif // MAINWINDOW_H
