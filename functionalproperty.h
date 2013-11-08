#ifndef FUNCTIONALPROPERTY_H
#define FUNCTIONALPROPERTY_H

#include <QObject>

class FunctionalProperty : public QObject {
    Q_OBJECT
    QObject &parent;
    QString property;
    bool hasFunction;
    class Cheshire;
    Cheshire *math;
    static qint64 lastEdit;
    float t; // time
    static void initTime();
    FunctionalProperty(const FunctionalProperty& hidden);
    void operator=(const FunctionalProperty& hidden);
public:
    FunctionalProperty(QObject *pparent, QString pproperty,
                       int sleep);
    ~FunctionalProperty();
    void setFunction(QString str);
public slots:
    void update();
};

#endif // FUNCTIONALPROPERTY_H
