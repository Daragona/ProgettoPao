#ifndef MODEL_H
#define MODEL_H
#include <QObject>

#include "mountainbike.h"
#include "container.h"
#include "veicolo.h"
#include "deepptr.h"
#include "bmx.h"

class Model : public QObject{
    Q_OBJECT
private:



public:
    Container<deepPtr<veicolo>> veicoli;
    Model();

signals:

public slots:
    void importMezzi();

};

#endif // MODEL_H
