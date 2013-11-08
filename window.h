#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QtWidgets>
#include "pixmapitem.h"
#include "pictureform.h"

namespace Ui {
class Window;
}

class Window : public QWidget
{
    Q_OBJECT

protected:
    void closeEvent(QCloseEvent *event);

public:
    explicit Window(QWidget *parent = 0);
    ~Window();
public slots:
    void fileSend0to1();
    void fileSend1to0();
private:
    Ui::Window *ui;
    QGraphicsScene scene;
    PixmapItem *items[2];
    PictureForm *forms[2];

};

#endif // WINDOW_H
