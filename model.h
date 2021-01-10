#ifndef MODEL_H
#define MODEL_H
#include <QObject>

#include "container.h"
#include "veicolo.h"
class Model : public QObject{
    Q_OBJECT
private:
    Container<deepPtr<veicolo>> *veicoli;

public:
    Model();

signals:

public slots:


};

#endif // MODEL_H
