#ifndef FILEPDFLIST_H
#define FILEPDFLIST_H
#include <QList>
#include <QString>
#include <QDir>
#include <QStringList>
#include <QDebug>
#include "filepdfdir.h"
class FilePDFList
{
public:
    FilePDFList();
    ~FilePDFList();
private:
    QList<QString> m_pdf_list;
    QList<QString> get_pdf_list_dir(QString dir_path);
    FilePDFDir m_pdf_dir_list;
};

#endif // FILEPDFLIST_H
