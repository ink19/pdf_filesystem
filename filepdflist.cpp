#include "filepdflist.h"

FilePDFList::FilePDFList()
{
    QList<QString> dirs = m_pdf_dir_list.search_path();
    for(auto item : dirs) {
        this->m_pdf_list.append(this->get_pdf_list_dir(item));
    }
    qDebug() << this->m_pdf_list;
}

QList<QString> &FilePDFList::get_pdf_list()
{
    return this->m_pdf_list;
}

FilePDFList::~FilePDFList()
{
    
}

QList<QString> FilePDFList::get_pdf_list_dir(QString dir_path)
{
    QDir dir(dir_path);
    QStringList filter;
    filter << "*.pdf";
    QList<QString> files = dir.entryList(filter, QDir::Files|QDir::Readable, QDir::Name);
    for (int loop = 0; loop < files.size(); ++loop) {
        files[loop] = dir_path + "/" + files[loop];
    }
    return files;
}
