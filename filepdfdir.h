#ifndef FILEPDFDIR_H
#define FILEPDFDIR_H

#include <QString>
#include <QList>
#include <QJsonDocument>
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QtDebug>
#include "filepdfconfig.h"
class FilePDFDir
{
public:
    FilePDFDir();
    ~FilePDFDir();
    QList<QString> &search_path();
private:
    QString m_config_path = "/home/ink19/c++_qt/pdf_config/config.json";
    QList<QString> m_search_path;
};

#endif // FILEPDFDIR_H
