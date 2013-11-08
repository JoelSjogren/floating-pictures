#ifndef PIXMAPITEM_H
#define PIXMAPITEM_H

#include <QObject>
#include <QtWidgets>
#include <QDebug>
#include "functionalproperty.h"
class PixmapItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(float x READ x WRITE setX)
    Q_PROPERTY(float y READ y WRITE setY)
    Q_PROPERTY(float s READ s WRITE setS)
    typedef FunctionalProperty anim_t;
    anim_t xAnim, yAnim, sAnim;
    static const int sleep = 30; // before refreshing position; in ms
public:
    PixmapItem() :
        xAnim(this, "x", sleep),
        yAnim(this, "y", sleep),
        sAnim(this, "s", sleep) {}
public slots:
    void setImg(QString img) {
        setPixmap(QPixmap(img));
    }

    void setXFunction(QString f) {
        xAnim.setFunction(f);
    }

    void setYFunction(QString f) {
        yAnim.setFunction(f);
    }

    void setSFunction(QString f) {
        sAnim.setFunction(f);
    }

    float x() { return boundingRect().left() + boundingRect().width() / 2; }
    float y() { return boundingRect().top() + boundingRect().height() / 2; }
    float s() { return scale(); }
    void setX(float val) {
        QPointF newpos = pos();
        newpos.setX(val - boundingRect().width() / 2 * scale());
        setPos(newpos);
    }
    void setY(float val) {
        QPointF newpos = pos();
        newpos.setY(val - boundingRect().height() / 2 * scale());
        setPos(newpos);
    }
    void setS(float val) {
        QPointF center = pos() + (boundingRect().bottomRight()
                                  - boundingRect().topLeft()) / 2 * scale();
        setScale(val);
        setX(center.x());
        setY(center.y());
    }
};

#endif // PIXMAPITEM_H
