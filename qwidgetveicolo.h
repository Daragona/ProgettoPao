#ifndef QWIDGETVEICOLO_H
#define QWIDGETVEICOLO_H

#include <QWidget>

#include "deepptr.h"
#include "veicolo.h"
class qwidgetveicolo : public QWidget
{
    Q_OBJECT
public:
    explicit qwidgetveicolo(deepPtr<veicolo>, QString=nullptr,QWidget *parent = nullptr);

signals:

};

#endif // QWIDGETVEICOLO_H
