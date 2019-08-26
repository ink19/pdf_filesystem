#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    
    auto file_list = this->pdflist.get_pdf_list(QString("default"));
    for(auto item : file_list) {
        this->ThumbList.push_back(new FilePDFFile(item, 360, 240, this));
    }
    
    this->resize(1280, 720);
    
    this->mainWidget = new QWidget(this);
    
    this->mainWidget->resize(1280, 720);
    
    this->_layout = new QGridLayout;
    m_scroll_area = new QScrollArea(this->mainWidget);
    
    
    //this->centralWidget()->resize(1280, 720);
    
    m_area_widget = new QWidget(m_scroll_area);
    //m_area_widget->resize(1280, 720);
    
    //this->setCentralWidget(m_scroll_area);
    //this->menuCreator();
    this->draw();
    m_area_widget->setLayout(this->_layout);
    
    m_scroll_area->setWidget(m_area_widget);
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    this->m_scroll_area->resize(this->size());
    this->mainWidget->resize(this->size());
    this->intoDir(this->m_now_path);
}

void MainWindow::menuCreator()
{
    QMenu *test_menu = new QMenu("Test");
    QAction *actions = test_menu->addAction("Clear");
    //this->menuBar()->addMenu(test_menu);
    connect(actions, SIGNAL(triggered()), this, SLOT(on_clear_click()));
}

void MainWindow::clearAllItem()
{
    for(auto item : this->ThumbList) {
        this->_layout->removeWidget(item);
        delete item;
    }
    this->ThumbList.clear();
    this->_layout->update();
}

void MainWindow::delete_slots()
{
    qDebug() << "delete mouse";
    FilePDFConfig::remove_collection(this->m_contextMenu_Op->m_filepath);
    this->intoDir("default");
}

void MainWindow::open_slots()
{
    if(this->m_contextMenu_Op->isPDF) {
        qDebug() << this->m_contextMenu_Op->m_filepath;
    } else {
        if(this->m_contextMenu_Op->m_filename == "add_collection") {
            QString file_path = QFileDialog::getExistingDirectory(this, "请选择文件路径...", QDir::homePath());
            if(file_path.isEmpty()) return;
            FilePDFConfig::add_collection(file_path);
            this->intoDir("default");
        } else {
            this->intoDir(this->m_contextMenu_Op->m_filepath);
        }
    }
}

void MainWindow::initList(QString dirpath)
{
    this->m_now_path = dirpath;
    
    if(this->m_now_path == "default") {
        // 主菜单
        this->m_contextMenu = new QMenu(this);
        //主菜单的 子项
        QAction *open_button = new QAction(this->m_contextMenu);
        open_button->setText("打开");
        
        connect(open_button, SIGNAL(triggered()), this, SLOT(open_slots()));
        
        QAction *delete_button = new QAction(this->m_contextMenu);
        delete_button->setText("删除");
        
        connect(delete_button, SIGNAL(triggered()), this, SLOT(delete_slots()));
        
        QList<QAction*> actionList;
        actionList<< open_button\
                 << delete_button;
        //添加子项到主菜单
        this->m_contextMenu->addActions(actionList);
    } else {
        // 主菜单
        this->m_contextMenu = new QMenu(this);
        //主菜单的 子项
        QAction *open_button = new QAction(this->m_contextMenu);
        open_button->setText("打开");
        
        connect(open_button, SIGNAL(triggered()), this, SLOT(open_slots()));        
        
        QList<QAction*> actionList;
        actionList<< open_button;
        //添加子项到主菜单
        this->m_contextMenu->addActions(actionList);
    }
    qDebug() << "now path: " << dirpath;
    auto file_list = this->pdflist.get_pdf_list(dirpath);
    for(auto item : file_list) {
        this->ThumbList.push_back(new FilePDFFile(item, 360, 240, this));
    }
}

void MainWindow::intoDir(QString dirpath)
{
    this->clearAllItem();
    
    this->initList(dirpath);
    this->draw();
}

void MainWindow::on_clear_click()
{
    for(auto item : this->ThumbList) {
        this->_layout->removeWidget(item);
        delete item;
    }
    this->ThumbList.clear();
    this->_layout->update();
}



int MainWindow::draw()
{
    
    int length = this->size().width() / 300;
    
    int loop_i = 0, loop_j = 0, min_width = 0;
    
    for(auto item : this->ThumbList) {
        if(loop_i == 0) ++loop_j;
        item->resize(240, 360);
        this->_layout->addWidget(item, loop_j - 1, loop_i);
        loop_i++;
        loop_i %= length;
    }
    
    if(loop_j == 0) {
        min_width = loop_i * 300;
    } else {
        min_width = length * 300;
    }
    qDebug() << min_width;
    m_area_widget->resize(min_width, 360 * (loop_j));
    return 0;
}
