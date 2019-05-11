#include "filepdfconfig.h"

FilePDFConfig::FilePDFConfig()
{
    QFile pfile(this->m_config_path);
    pfile.open(QIODevice::ReadWrite);
    this->m_config = QJsonDocument::fromJson(pfile.readAll()).object();
}

QJsonValue FilePDFConfig::getValue(QString path)
{
    FilePDFConfig self_conf;
    QStringList path_list = path.split(".");
    int loop_times = 0;
    QJsonValue temp_result;
    QJsonObject temp_object = self_conf.m_config;
    for(auto item : path_list) {
        loop_times++;
        temp_result = temp_object[item];
        if(loop_times != path_list.size()) temp_object = temp_result.toObject();
    }
    return temp_result;
}
