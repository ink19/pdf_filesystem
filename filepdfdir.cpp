#include "filepdfdir.h"

FilePDFDir::FilePDFDir()
{
//    QFile pfile(this->m_config_path);
//    pfile.open(QIODevice::ReadWrite);
//    auto config_json = QJsonDocument::fromJson(pfile.readAll()).object();
    auto search_path_arr = FilePDFConfig::getValue("search_path").toArray();
    for(auto item : search_path_arr) {
        this->m_search_path.append(item.toString());
        qDebug() << item.toString();
    }
    //pfile.close();
}

FilePDFDir::~FilePDFDir()
{
    
}

QList<QString> &FilePDFDir::search_path()
{
    return this->m_search_path;
}
