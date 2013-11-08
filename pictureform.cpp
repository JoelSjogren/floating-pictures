#include "pictureform.h"
#include "ui_pictureform.h"
#include "pixmapitem.h"
#include <QSize>
#include <QResizeEvent>
#include <QStyle>

PictureForm::PictureForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PictureForm)
{
    ui->setupUi(this);
}

void PictureForm::setPixmapItem(PixmapItem *item) {
    connect(ui->file, SIGNAL(currentIndexChanged(QString)), item, SLOT(setImg(QString)));
    connect(ui->x, SIGNAL(textChanged(QString)), item, SLOT(setXFunction(QString)));
    connect(ui->y, SIGNAL(textChanged(QString)), item, SLOT(setYFunction(QString)));
    connect(ui->s, SIGNAL(textChanged(QString)), item, SLOT(setSFunction(QString)));
}

PictureForm::~PictureForm()
{
    delete ui;
}

void PictureForm::on_fileAdd_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Open Image"), ".",
         tr("Image Files (*.png *.jpg *.bmp *.svg);;All files(*.*)"));
    if (fileName == "") return;
    ui->file->addItem(fileName);
    ui->file->setCurrentIndex(ui->file->count() - 1);
}

void PictureForm::on_fileRemove_clicked()
{
    ui->file->removeItem(ui->file->currentIndex());
}
