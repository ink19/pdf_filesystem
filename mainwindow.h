#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filepdflist.h"
#include "filepdfimagebuffer.h"
#include <QList>
#include "filepdfthumbitem.h"
#include <QGridLayout>
#include <QScrollArea>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include "filepdffile.h"

namespace Ui {
class MainWindow;
}
class FilePDFFile;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void intoDir(QString dirpath);
    QString m_now_path = "default";
    QWidget *mainWidget;
private:
    int draw();
    void resizeEvent(QResizeEvent *event);
    void menuCreator();
    void clearAllItem();
    void initList(QString dirpath);
    
    FilePDFList pdflist;
    QList<FilePDFFile *> ThumbList;
    QGridLayout *_layout;
    QScrollArea *m_scroll_area;
    QWidget *m_area_widget;
    
private slots:
    void on_clear_click();
};

#endif // MAINWINDOW_H
