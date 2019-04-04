#ifndef FILEPDFTHUMBITEM_H
#define FILEPDFTHUMBITEM_H

#include <QLabel>
#include <QImage>
#include <QString>
#include <QFileInfo>
#include <filepdfimagebuffer.h>
#include <QPixmap>
#include <QVBoxLayout>

class FilePDFThumbItem : public QWidget
{
public:
    FilePDFThumbItem(QString filepath, int height, int width);
    ~FilePDFThumbItem();
private:
    QString m_filepath;
    QString m_filename;
    QString m_cache_path;
    QLabel *m_image;
    QLabel *m_title;
public slots:
    void mouseClicked();
protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // FILEPDFTHUMBITEM_H
