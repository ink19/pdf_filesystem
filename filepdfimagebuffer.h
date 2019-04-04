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
    ~FilePDFImageBuffer();
private:
    QString get_file_md5(QString &filepath);
    int make_image_cache(QString &filepath, QString &cache_path);
    QString m_cache_path;
    QString m_config_path = "/home/ink19/c++_qt/pdf_config/config.json";
    QString m_default_path;
    
};

#endif // FILEPDFIMAGEBUFFER_H
