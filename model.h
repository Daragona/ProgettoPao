#ifndef MODEL_H
#define MODEL_H
#include <QObject>
#include <QMap>

#include "mountainbike.h"
#include "container.h"
#include "veicolo.h"
#include "deepptr.h"
#include "bmx.h"
#include "ebike.h"
#include "monopattinoelettrico.h"

class Model : public QObject{
    Q_OBJECT
private:

public:
    Container<deepPtr<veicolo>> veicoli;

    Model();
    void addVeicolo(deepPtr<veicolo>);
    void removeVeicolo(deepPtr<veicolo>);
    //void filtraVeicoloMarca(QString);
    //void filtraVeicoloTipo(QString);
    Container<deepPtr<veicolo>> visualizzaVeicoli();

signals:

public slots:
    void importMezzi();

};

#endif // MODEL_H
