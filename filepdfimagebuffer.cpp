#include "filepdfimagebuffer.h"

FilePDFImageBuffer::FilePDFImageBuffer()
{
    //QFile pfile(this->m_config_path);
    //pfile.open(QIODevice::ReadWrite);
    //auto config_json = QJsonDocument::fromJson(pfile.readAll()).object();
    this->m_cache_path = FilePDFConfig::getValue("image_cache_dir").toString();
    qDebug() << this->m_cache_path;
}

QString FilePDFImageBuffer::get_image_path(QString &filepath)
{
    QString cache_md5 = this->get_file_md5(filepath);
    cache_md5 = this->m_cache_path + "/" + cache_md5 + ".jpg";
    QFileInfo cache_info(cache_md5);
    if(cache_info.exists()) {
        return cache_md5;
    } else {
        this->make_image_cache(filepath, cache_md5);
        return cache_md5;
    }
}

QString FilePDFImageBuffer::get_image_path(QString &filepath, int isPDF)
{
    if(!isPDF) return this->m_default_path;
    QString cache_md5 = this->get_file_md5(filepath);
    cache_md5 = this->m_cache_path + "/" + cache_md5 + ".jpg";
    QFileInfo cache_info(cache_md5);
    if(cache_info.exists()) {
        return cache_md5;
    } else {
        this->make_image_cache(filepath, cache_md5);
        return cache_md5;
    }
}

FilePDFImageBuffer::~FilePDFImageBuffer()
{
    
}

QString FilePDFImageBuffer::get_file_md5(QString &filepath)
{
    QString md5;
    QByteArray bb;
    bb = QCryptographicHash::hash ( filepath.toUtf8(), QCryptographicHash::Md5 );
    md5.append(bb.toHex());
    return md5;
}

int FilePDFImageBuffer::make_image_cache(QString &filepath, QString &cache_path)
{
    auto temp_doc = Poppler::Document::load(filepath);
    if(!temp_doc) {
        qDebug() << "No this File";
        return -1;
    }
    if(temp_doc->isLocked()) {
        cache_path = this->m_default_path;
        return 0;
    } 
    temp_doc->setRenderHint(Poppler::Document::TextAntialiasing, 1);
    temp_doc->setRenderHint(Poppler::Document::Antialiasing, 1);
    auto temp_page = temp_doc->page(0);
    temp_page->renderToImage().save(cache_path);
    delete temp_page;
    delete temp_doc;
    return 0;
}
