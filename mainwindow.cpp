#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    
    auto file_list = this->pdflist.get_default_list();
    for(auto item : file_list) {
        this->ThumbList.push_back(new FilePDFFile(item, 360, 240, this));
    }
    
    this->resize(1280, 720);
    
    this->_layout = new QGridLayout;
    m_scroll_area = new QScrollArea(this);
    
    
    //this->centralWidget()->resize(1280, 720);
    
    m_area_widget = new QWidget(m_scroll_area);
    //m_area_widget->resize(1280, 720);
    
    //this->setCentralWidget(m_scroll_area);
    this->menuCreator();
    this->draw();
    m_area_widget->setLayout(this->_layout);
    
    m_scroll_area->setWidget(m_area_widget);
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    this->m_scroll_area->resize(this->size());
}

void MainWindow::menuCreator()
{
    QMenu *test_menu = new QMenu("Test");
    QAction *actions = test_menu->addAction("Clear");
    this->menuBar()->addMenu(test_menu);
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

void MainWindow::initList(QString dirpath)
{
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
    
    int length = this->size().width() / 240;
    
    int loop_i = 0, loop_j = 0;
    
    for(auto item : this->ThumbList) {
        item->resize(240, 360);
        this->_layout->addWidget(item, loop_j, loop_i);
        loop_i++;
        loop_i %= length;
        if(loop_i == 0) ++loop_j;
    }
    
    m_area_widget->resize(this->size().width(), 360 * (loop_j + 1));
    return 0;
}
