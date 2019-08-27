#include "filethumlabel.h"

FileThumLabel::FileThumLabel(QString filepath, int height, int width, QWidget *parent):
    QWidget(parent),
    m_filepath(filepath)
{
    QFont ft;
    ft.setPointSize(10);
    this->setMouseTracking(true);
    
    if(filepath == "default") {
        this->m_filename = "返回顶层";
        this->isPDF = 0;
    } else if(filepath == "add_collection") {
        this->m_filename = "添加收藏";
        this->isPDF = 0;
    } else {
        QFileInfo filei(filepath);
        this->m_filename = filei.fileName();
        this->isPDF = filei.isFile();
    }
    FileImageBuffer filebuff;
    this->m_image_cache_path = filebuff.get_image_path(this->m_filepath, this->isPDF);
    this->m_image = new QLabel;
    qDebug() << this->m_image_cache_path;
    this->m_image->setPixmap(QPixmap(this->m_image_cache_path).scaled(width, height));
    this->m_title = new QLabel;
    
    if(this->m_filename.size() > 20) {
        this->m_title->setText(this->m_filename.mid(0, 20));
    } else {
        this->m_title->setText(this->m_filename);
    }
    this->m_title->setFont(ft);
    auto _layout = new QVBoxLayout(this);
    _layout->addWidget(this->m_image);
    _layout->addWidget(this->m_title);
}

void FileThumLabel::mouseMoveEvent(QMouseEvent *event)
{
    QPoint mousepos = event->pos(); 
    //在坐标（0 ~ width，0 ~ height）范围内改变鼠标形状
    if(mousepos.rx() > 0 
       && mousepos.rx() < this->width()
       && mousepos.ry() > 0
       && mousepos.ry() < this->height())
    {
        this->setCursor(Qt::PointingHandCursor);
    } else {
        this->setCursor(Qt::ArrowCursor);      //范围之外变回原来形状
    }
}

void FileThumLabel::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) emit click_left(this);
    else emit click_right(this, event->globalPos());
}
