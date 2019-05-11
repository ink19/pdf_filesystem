#ifndef FILEPDFFILE_H
#define FILEPDFFILE_H

#include <QWidget>
#include <QLabel>
#include <QFileInfo>
#include "filepdfimagebuffer.h"
#include <QVBoxLayout>
#include <mainwindow.h>

class MainWindow;

class FilePDFFile : public QWidget
{
public:
    FilePDFFile(QString filepath, int height, int width, MainWindow *mainw);
    ~FilePDFFile();
    int isPDF;
    QString m_filepath;
    QString m_filename;
    QString m_cache_path;
    QLabel *m_image;
    QLabel *m_title;
    MainWindow *mainw;
public slots:
    void mouseClicked();
protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // FILEPDFFILE_H
