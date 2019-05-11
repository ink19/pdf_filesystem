#include "filepdffile.h"

FilePDFFile::FilePDFFile(QString filepath, int height, int width, MainWindow *mainw):
    m_filepath(filepath),
    mainw(mainw)
{
    if(filepath == "default") {
        this->m_filename = "返回顶层";
        FilePDFImageBuffer filebu;
        this->m_image = new QLabel;
        this->isPDF = 0;
        this->m_cache_path = filebu.get_image_path(this->m_filepath, this->isPDF);
        this->m_image->setPixmap(QPixmap(this->m_cache_path).scaled(width, height));
        this->m_title = new QLabel;
        
        
        if(this->m_filename.size() > 15) {
            this->m_title->setText(this->m_filename.mid(0, 15));
        } else {
            this->m_title->setText(this->m_filename);
        }
        auto _layout = new QVBoxLayout(this);
        _layout->addWidget(this->m_image);
        _layout->addWidget(this->m_title);
        
        return;
    }
    QFileInfo filei(filepath);
    this->m_filename = filei.fileName();
    FilePDFImageBuffer filebu;
    this->m_image = new QLabel;
    this->isPDF = filei.isFile();
    this->m_cache_path = filebu.get_image_path(this->m_filepath, this->isPDF);
    this->m_image->setPixmap(QPixmap(this->m_cache_path).scaled(width, height));
    this->m_title = new QLabel;
    
    
    if(this->m_filename.size() > 15) {
        this->m_title->setText(this->m_filename.mid(0, 15));
    } else {
        this->m_title->setText(this->m_filename);
    }
    auto _layout = new QVBoxLayout(this);
    _layout->addWidget(this->m_image);
    _layout->addWidget(this->m_title);
}

FilePDFFile::~FilePDFFile()
{
    delete this->m_title;
    delete this->m_image;
}

void FilePDFFile::mouseClicked()
{
    qDebug() << "Test";
    if(this->isPDF) {
        qDebug() << this->m_filepath;
    } else {
        this->mainw->intoDir(this->m_filepath);
    }
}

void FilePDFFile::mousePressEvent(QMouseEvent *event)
{
    emit mouseClicked();
}
