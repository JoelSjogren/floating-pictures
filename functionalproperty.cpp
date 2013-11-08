#include "functionalproperty.h"
#include "exprtk.hpp"
#include <QTimer>
#include <QDateTime>
#include <QVariant>
class FunctionalProperty::Cheshire {
public:
    exprtk::symbol_table<float> symbols;
    exprtk::expression<float> expression;
};

qint64 FunctionalProperty::lastEdit = 0;

FunctionalProperty::FunctionalProperty(QObject *pparent,
                                       QString pproperty,
                                       int sleep)
    : parent(*pparent), property(pproperty),
      hasFunction(false), math(new Cheshire) {
    math->symbols.add_variable("t", t);
    math->symbols.add_constant("e", 2.718281828459045);
    math->symbols.add_constant("pi", 3.141592653589793);
    math->expression.register_symbol_table(math->symbols);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(sleep);
}
FunctionalProperty::~FunctionalProperty() {
    delete math;
}

void FunctionalProperty::setFunction(QString str) {
    exprtk::parser<float> parser;
    hasFunction = parser.compile(str.toStdString(), math->expression);
    lastEdit = QDateTime::currentMSecsSinceEpoch();
}

void FunctionalProperty::update() {
    if (hasFunction) {
        qint64 time = QDateTime::currentMSecsSinceEpoch();
        t = (time - lastEdit) / 1000.0;
        float value = math->expression.value();
        parent.setProperty(property.toStdString().c_str(), value);
    }
}
