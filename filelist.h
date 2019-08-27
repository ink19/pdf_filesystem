#ifndef FILELIST_H
#define FILELIST_H

#include <QWidget>
#include "filethumlabel.h"
#include <QList>
#include <QGridLayout>
#include <QDir>
#include <QStringList>
#include <QFileInfo>
#include "fileconfigure.h"
#include <QFileDialog>
class FileList : public QWidget
{
    Q_OBJECT
public:
    explicit FileList(QWidget *parent = nullptr);
    QList<FileThumLabel *> m_pdf_list;
    QGridLayout *m_layout;
    int into_dir(QString path);
    int draw();
    int redraw();
    QString m_now_path = "default";
private:
    QList<QString> get_file_list(QString path);
    int add_collection();
signals:
    
public slots:
    void sizeChange(QSize size);
    void clickThum(FileThumLabel *item);
};

#endif // FILELIST_H
