#ifndef PICTUREFORM_H
#define PICTUREFORM_H

#include <QWidget>
#include "pixmapitem.h"
namespace Ui {
class PictureForm;
}

class PictureForm : public QWidget
{
    Q_OBJECT
public:
    explicit PictureForm(QWidget *parent = 0);
    ~PictureForm();
    void setPixmapItem(PixmapItem *item);
    Ui::PictureForm *ui;
private slots:
    void on_fileAdd_clicked();
    void on_fileRemove_clicked();
};

#endif // PICTUREFORM_H
