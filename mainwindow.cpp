#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    auto file_list = this->pdflist.get_pdf_list();
    for(auto item : file_list) {
        this->ThumbList.push_back(new FilePDFThumbItem(item, 360, 240));
    }
    
    this->resize(1280, 720);
    this->_layout = new QGridLayout;
    m_scroll_area = new QScrollArea(this);
    this->m_scroll_area->resize(1280, 720);
    
    //this->centralWidget()->resize(1280, 720);
    
    QWidget *m_area_widget = new QWidget(this);
    //m_area_widget->resize(1280, 720);
    
    //this->setCentralWidget(m_scroll_area);
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

int MainWindow::draw()
{
    
    int loop_i = 0, loop_j = 0;
    for(auto item : this->ThumbList) {
        item->resize(240, 360);
        this->_layout->addWidget(item, loop_j, loop_i);
        loop_i++;
        loop_i %= 4;
        if(loop_i == 0) ++loop_j;
    }
    //m_area_widget->resize(1280, 360 * (loop_j + 1));
    return 0;
}
