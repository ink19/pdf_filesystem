#ifndef FILECONFIGURE_H
#define FILECONFIGURE_H

#include <QString>
#include <QFile>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QStringList>


class FileConfigure
{
public:
    FileConfigure();
    static QJsonValue getValue(QString path);
    static int add_collection(QString path);
    static int remove_collection(QString path);
private:
    QString m_config_path = "/home/ink19/c++_qt/pdf_filesystem/pdf_config/config.json";
    QJsonObject m_config;
};

#endif // FILECONFIGURE_H
