#include "window.h"
#include "ui_window.h"
#include "pixmapitem.h"
#include "pictureform.h"
#include "ui_pictureform.h"
#include <QVariant>
Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    setWindowTitle("Lazy eye 0.1");
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setSceneRect(-10, 10, 20, 20);
    forms[0] = ui->form1;
    forms[1] = ui->form2;
    QSettings settings;
    QString prefix = "form%1/";
    for (int i = 0; i < 2; i++) {
        Ui::PictureForm *pfui = forms[i]->ui;
        QString p = prefix.arg(i);
        PixmapItem *item = new PixmapItem();
        scene.addItem(item);
        forms[i]->setPixmapItem(item);
        QStringList items = settings.value(p + "fileList").toStringList();
        if (items.size() == 0) items << ":/pixmaps/fractal_alpha.png";
        forms[i]->ui->file->addItems(items);
        int index = settings.value(p + "fileIndex", 0).toInt();
        pfui->file->setCurrentIndex(index);
        pfui->x->setText(settings.value(p).toString());
        item->setImg(pfui->file->currentText()); // TODO reroute
        QString xstr = settings.value(p + "x", "0").toString();
        QString ystr = settings.value(p + "y", "0").toString();
        QString sstr = settings.value(p + "s", "1").toString();
        pfui->x->setText(xstr);
        pfui->y->setText(ystr);
        pfui->s->setText(sstr);
        item->setXFunction(xstr);
        item->setYFunction(ystr);
        item->setSFunction(sstr);
    }
    connect(forms[0]->ui->fileSend, SIGNAL(clicked()), this, SLOT(fileSend0to1()));
    connect(forms[1]->ui->fileSend, SIGNAL(clicked()), this, SLOT(fileSend1to0()));
}

Window::~Window()
{
    delete ui;
}

void Window::fileSend0to1()
{
    QString file = forms[0]->ui->file->currentText();
    for (int i = 0; i < forms[1]->ui->file->count(); i++) {
        if (forms[1]->ui->file->itemText(i) == file) {
            forms[1]->ui->file->setCurrentIndex(i);
            return;
        }
    }
    forms[1]->ui->file->addItem(file);
    forms[1]->ui->file->setCurrentIndex(forms[1]->ui->file->count() - 1);
}

void Window::fileSend1to0()
{
    QString file = forms[1]->ui->file->currentText();
    for (int i = 0; i < forms[1]->ui->file->count(); i++) {
        if (forms[0]->ui->file->itemText(i) == file) {
            forms[0]->ui->file->setCurrentIndex(i);
            return;
        }
    }
    forms[0]->ui->file->addItem(file);
    forms[0]->ui->file->setCurrentIndex(forms[1]->ui->file->count() - 1);
}

QStringList getItems(QComboBox* box) {
    QStringList result;
    for (int i = 0; i < box->count(); i++)
        result << box->itemText(i);
    result.removeDuplicates();
    return result;
}

void Window::closeEvent(QCloseEvent *event)
{
    QSettings settings;
    QString prefix = "form%1/";
    for (int i = 0; i < 2; i++) {
        QString iPrefix = prefix.arg(i);
        settings.setValue(iPrefix + "fileIndex",
                          forms[i]->ui->file->currentIndex());
        settings.setValue(iPrefix + "fileList",
                          getItems(forms[i]->ui->file));
        settings.setValue(iPrefix + "x", forms[i]->ui->x->text());
        settings.setValue(iPrefix + "y", forms[i]->ui->y->text());
        settings.setValue(iPrefix + "s", forms[i]->ui->s->text());
    }
    event->accept();
}






