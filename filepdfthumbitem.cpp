#include "filepdfthumbitem.h"

FilePDFThumbItem::FilePDFThumbItem(QString filepath, int height, int width)
    :m_filepath(filepath)
{
    QFileInfo filei(filepath);
    this->m_filename = filei.fileName();
    FilePDFImageBuffer filebu;
    this->m_cache_path = filebu.get_image_path(filepath);
    this->m_image = new QLabel;
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
    //this->m_title->setText();
}

FilePDFThumbItem::~FilePDFThumbItem()
{
    
}

void FilePDFThumbItem::mouseClicked()
{
    qDebug() << this->m_filename;
}

void FilePDFThumbItem::mousePressEvent(QMouseEvent *event) {
    emit mouseClicked();
}
