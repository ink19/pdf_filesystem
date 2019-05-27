#include "filepdflist.h"

FilePDFList::FilePDFList()
{ 
    auto search_path_arr = FilePDFConfig::getValue("search_path").toArray();
    this->m_default_list.append("add_collection");
    for(auto item : search_path_arr) {
        this->m_default_list.append(item.toString());
    }
    qDebug() << this->m_pdf_list;
}

QList<QString> FilePDFList::get_pdf_list(QString dirpath)
{
    if(dirpath == "default") {
        this->m_default_list.clear();
        auto search_path_arr = FilePDFConfig::getValue("search_path").toArray();
        this->m_default_list.append("add_collection");
        for(auto item : search_path_arr) {
            this->m_default_list.append(item.toString());
        }
        return m_default_list;
    } else return get_pdf_list_dir(dirpath);
}

QList<QString> FilePDFList::get_default_list() {
    return m_default_list;
}

FilePDFList::~FilePDFList()
{
    
}

QList<QString> FilePDFList::get_pdf_list_dir(QString dir_path)
{
    QDir dir(dir_path);
    QStringList filter;
    filter << "*.pdf";
    QList<QString> result;
    QList<QFileInfo> all_files_info = dir.entryInfoList();
    
    result.append("default");
    
    for(auto item : all_files_info) {
        if(item.isDir() && item.fileName()[0] != '.') result.append(item.filePath());
    }
    
    QList<QString> files = dir.entryList(filter, QDir::Files|QDir::Readable, QDir::Name);
    for (int loop = 0; loop < files.size(); ++loop) {
        files[loop] = dir_path + "/" + files[loop];
    }
    result.append(files);
    return result;
}
