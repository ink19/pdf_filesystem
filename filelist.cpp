#include "filelist.h"

FileList::FileList(QWidget *parent) : QWidget(parent)
{
    if(parent != nullptr) this->resize(parent->size());
    this->m_layout = new QGridLayout(this);
    //this->m_pdf_list = new QList<FileThumLabel>;
    this->setLayout(m_layout);
    this->into_dir("default");
}

int FileList::into_dir(QString path)
{
    this->m_now_path = path;
    for (auto item : this->m_pdf_list) {
        item->disconnect();
        item->setVisible(false);
        this->m_layout->removeWidget(item);
    }
    this->m_pdf_list.clear();
    auto file_paths = this->get_file_list(path);
    for (auto item : file_paths) {
        auto thum_item = new FileThumLabel(item, 360, 240, this);
        this->m_pdf_list.append(thum_item);
        connect(thum_item, SIGNAL(click_right(FileThumLabel *)), this, SLOT(clickThum(FileThumLabel*)));
    }
    this->draw();
    return 0;
}

int FileList::draw()
{
    int length = this->size().width() / 300;
    if (length < 1) length = 1;
    int loop_i = 0, loop_j = 0, min_width;
    for (auto item : this->m_pdf_list) {
        if(loop_i == 0) ++loop_j;
        item->resize(240, 360);
        
        this->m_layout->addWidget(item, loop_j - 1, loop_i);
        item->setVisible(true);
        loop_i ++;
        loop_i %= length;
    }
    
    if (loop_j == 0) {
        min_width = loop_i * 300;
    } else {
        min_width = length * 300;
    }
    
    this->resize(min_width, 360 * loop_j);
    this->update();
    this->m_layout->update();
    return 0;
}

int FileList::redraw()
{
    for (auto item : this->m_pdf_list) {
        item->setVisible(false);
        this->m_layout->removeWidget(item);
    }
    this->draw();
    return 0;
}

QList<QString> FileList::get_file_list(QString path)
{
    QList<QString> result;
    if(path == "default") {
        result.append("add_collection");
        auto search_path_arr = FileConfigure::getValue("search_path").toArray();
        for(auto item : search_path_arr) {
            result.append(item.toString());
        }
    } else {
        result.append("default");
        QDir dir(path);
        QStringList filter;
        filter << "*.pdf";
        QList<QFileInfo> all_files_info = dir.entryInfoList();
        for (auto item : all_files_info) {
            if(item.isDir() && item.fileName()[0] != '.') result.append(item.filePath());
        }
        
        QList<QString> files = dir.entryList(filter, QDir::Files|QDir::Readable, QDir::Name);
        for (auto item : files) {
            result.append(path + "/" + item);
        }
    }
    return result;
}

int FileList::add_collection()
{
    QString file_path = QFileDialog::getExistingDirectory(this, "请选择文件路径...", QDir::homePath());
    if(file_path.isEmpty()) return 0;
    FileConfigure::add_collection(file_path);
    this->into_dir("default");
    return 0;
}

void FileList::sizeChange(QSize size)
{
    this->resize(size);
    this->redraw();
}

void FileList::clickThum(FileThumLabel *item)
{
    if(item->isPDF) {
        qDebug() << item->m_filepath;
    } else {
        if(item->m_filepath == "add_collection") {
            this->add_collection();
        } else {
            into_dir(item->m_filepath);
        }
    }
}

