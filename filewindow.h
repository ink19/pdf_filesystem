#ifndef FILEWINDOW_H
#define FILEWINDOW_H

#include <QWidget>

class FileWindow : public QWidget
{
    Q_OBJECT
public:
    explicit FileWindow(QWidget *parent = nullptr);
    int mresize(const QSize &size);
signals:
    
public slots:
};

#endif // FILEWINDOW_H
