#ifndef FILEPDFCONFIG_H
#define FILEPDFCONFIG_H

#include <QString>
#include <QFile>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QStringList>

class FilePDFConfig
{
public:
    FilePDFConfig();
    static QJsonValue getValue(QString path);
private:
    //static FilePDFConfig self_conf;
    QString m_config_path = "/home/ink19/c++_qt/pdf_config/config.json";
    QJsonObject m_config;
};

#endif // FILEPDFCONFIG_H
