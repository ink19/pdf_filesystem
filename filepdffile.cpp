#include "filepdffile.h"

FilePDFFile::FilePDFFile(QString filepath, int height, int width, MainWindow *mainw):
    m_filepath(filepath),
    mainw(mainw)
{
    QFont ft;
    ft.setPointSize(10);
    this->setMouseTracking(true);
    
    if(filepath == "default") {
        this->m_filename = "返回顶层";
        FilePDFImageBuffer filebu;
        this->m_image = new QLabel;
        this->isPDF = 0;
        this->m_cache_path = filebu.get_image_path(this->m_filepath, this->isPDF);
        this->m_image->setPixmap(QPixmap(this->m_cache_path).scaled(width, height));
        this->m_title = new QLabel;
        
        
        if(this->m_filename.size() > 20) {
            this->m_title->setText(this->m_filename.mid(0, 20));
        } else {
            
            this->m_title->setText(this->m_filename);
        }
        this->m_title->setFont(ft);
        //this->m_title->setAlignment(Qt::AlignHCenter);
        auto _layout = new QVBoxLayout(this);
        _layout->addWidget(this->m_image);
        _layout->addWidget(this->m_title);
        
        return;
    } else if(filepath == "add_collection") {
        this->m_filename = "添加收藏";
        FilePDFImageBuffer filebu;
        this->m_image = new QLabel;
        this->isPDF = 0;
        this->m_cache_path = filebu.get_image_path(this->m_filepath, this->isPDF);
        this->m_image->setPixmap(QPixmap(this->m_cache_path).scaled(width, height));
        this->m_title = new QLabel;
        
        
        this->m_title->setText(this->m_filename);
        this->m_title->setFont(ft);
        //this->m_title->setAlignment(Qt::AlignHCenter);
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
    
    
    if(this->m_filename.size() > 20) {
        this->m_title->setText(this->m_filename.mid(0, 20));
    } else {
        this->m_title->setText(this->m_filename);
    }
    this->m_title->setFont(ft);
    //this->m_title->setAlignment(Qt::AlignHCenter);
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
    if(this->isPDF) {
        qDebug() << this->m_filepath;
    } else {
        if(this->m_filepath == "add_collection") {
            QString file_path = QFileDialog::getExistingDirectory(this, "请选择文件路径...", QDir::homePath());
            if(file_path.isEmpty()) return;
            FilePDFConfig::add_collection(file_path);
            this->mainw->intoDir("default");
        } else {
            this->mainw->intoDir(this->m_filepath);
        }
    }
}

//void FilePDFFile::delete_slots()
//{
//    qDebug() << "delete mouse";
//    FilePDFConfig::remove_collection(this->m_filepath);
//    this->mainw->intoDir("default");
//}

//void FilePDFFile::open_slots()
//{
//    emit mouseClicked();
//}

void FilePDFFile::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mouse press";
    if(event->button() == Qt::LeftButton) emit mouseClicked();
    else if(event->button() == Qt::RightButton) {
        this->mainw->m_contextMenu_Op = this;
        this->mainw->m_contextMenu->exec(event->globalPos());
    }
}

void FilePDFFile::mouseMoveEvent(QMouseEvent *event)
{
    QPoint mousepos = event->pos(); 
    //在坐标（0 ~ width，0 ~ height）范围内改变鼠标形状
    if(mousepos.rx() > 0 
       && mousepos.rx() < this->width()
       && mousepos.ry() > 0
       && mousepos.ry() < this->height())
    {
           this->setCursor(Qt::PointingHandCursor);
    }
    else
    {
        this->setCursor(Qt::ArrowCursor);      //范围之外变回原来形状
    }
}
