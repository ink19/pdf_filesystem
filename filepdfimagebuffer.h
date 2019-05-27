#ifndef FILEPDFIMAGEBUFFER_H
#define FILEPDFIMAGEBUFFER_H

#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QCryptographicHash>
#include <poppler/qt5/poppler-qt5.h>
#include <QImage>
#include <QFileInfo>
#include "filepdfconfig.h"


class FilePDFImageBuffer
{
public:
    FilePDFImageBuffer();
    QString get_image_path(QString &filepath);
    QString get_image_path(QString &filepath, int isPDF);
    ~FilePDFImageBuffer();
private:
    QString get_file_md5(QString &filepath);
    int make_image_cache(QString &filepath, QString &cache_path);
    QString m_cache_path;
    QString m_default_path = "/home/ink19/c++_qt/pdf_filesystem/pdf_config/pdf.png";
    QString m_dir_image = "/home/ink19/c++_qt/pdf_filesystem/pdf_config/dir.png";
};

#endif // FILEPDFIMAGEBUFFER_H
