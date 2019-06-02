#include "filepdffile.h"

FilePDFFile::FilePDFFile(QString filepath, int height, int width, MainWindow *mainw):
    m_filepath(filepath),
    mainw(mainw)
{
    QFont ft;
    ft.setPointSize(20);
    if(filepath == "default") {
        this->m_filename = "返回顶层";
        FilePDFImageBuffer filebu;
        this->m_image = new QLabel;
        this->isPDF = 0;
        this->m_cache_path = filebu.get_image_path(this->m_filepath, this->isPDF);
        this->m_image->setPixmap(QPixmap(this->m_cache_path).scaled(width, height));
        this->m_title = new QLabel;
        
        
        if(this->m_filename.size() > 7) {
            this->m_title->setText(this->m_filename.mid(0, 7));
        } else {
            this->m_title->setText(this->m_filename);
        }
        this->m_title->setFont(ft);
        this->m_title->setAlignment(Qt::AlignHCenter);
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
        this->m_title->setAlignment(Qt::AlignHCenter);
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
    
    
    if(this->m_filename.size() > 7) {
        this->m_title->setText(this->m_filename.mid(0, 7));
    } else {
        this->m_title->setText(this->m_filename);
    }
    this->m_title->setFont(ft);
    this->m_title->setAlignment(Qt::AlignHCenter);
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

void FilePDFFile::delete_slots()
{
    qDebug() << "delete mouse";
    FilePDFConfig::remove_collection(this->m_filepath);
    this->mainw->intoDir("default");
}

void FilePDFFile::open_slots()
{
    emit mouseClicked();
}

void FilePDFFile::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mouse press";
    if(event->button() == Qt::LeftButton) emit mouseClicked();
}

void FilePDFFile::contextMenuEvent(QContextMenuEvent *event)
{
    if(this->mainw->m_now_path == "default") {
        // 主菜单
        QMenu *MainMenu = new QMenu(this);
        //主菜单的 子项
        QAction *open_button = new QAction(MainMenu);
        open_button->setText("打开");
        
        connect(open_button, SIGNAL(triggered()), this, SLOT(open_slots()));
        
        QAction *delete_button = new QAction(MainMenu);
        delete_button->setText("删除");
        
        connect(delete_button, SIGNAL(triggered()), this, SLOT(delete_slots()));
        
        QList<QAction*> actionList;
        actionList<< open_button\
                 << delete_button;
        //添加子项到主菜单
        MainMenu->addActions(actionList);
        
        
        
        // 移动到当前鼠标所在位置
        MainMenu->exec(QCursor::pos());
    } else {
        // 主菜单
        QMenu *MainMenu = new QMenu(this);
        //主菜单的 子项
        QAction *open_button = new QAction(MainMenu);
        open_button->setText("打开");
        
        connect(open_button, SIGNAL(triggered()), this, SLOT(open_slots()));        
        
        QList<QAction*> actionList;
        actionList<< open_button;
        //添加子项到主菜单
        MainMenu->addActions(actionList);
        
        
        
        // 移动到当前鼠标所在位置
        MainMenu->exec(QCursor::pos());
    }
}
