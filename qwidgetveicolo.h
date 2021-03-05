#ifndef QWIDGETVEICOLO_H
#define QWIDGETVEICOLO_H

#include <QWidget>

#include "deepptr.h"
#include "veicolo.h"
#include "view.h"
#include "controller.h"
class qwidgetveicolo : public QWidget
{
    Q_OBJECT
private:
    deepPtr<veicolo> ptrVeicolo;
    bool moreInfo=false;
    QWidget *moreInfoPage;
    Controller *ctrl;

public:
    view vista;
    qwidgetveicolo(deepPtr<veicolo>, QString=nullptr,view *parent=nullptr, Controller *c= nullptr);

signals:

public slots:
    void deleteSlot();
    void moreInfoSlot();

};

#endif // QWIDGETVEICOLO_H
