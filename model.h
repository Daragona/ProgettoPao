#ifndef MODEL_H
#define MODEL_H
#include <QObject>

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
    void addVeicolo(QStringList*);
    //Bisogna passare Tipo veicolo e tutti gli attributi. Magari in un Container<deepPtr<QObject>>??

    void rimuoviVeicolo();
    void filtraVeicoloMarca(QString);
    void filtraVeicoloTipo(QString);
    Container<deepPtr<veicolo>> visualizzaVeicoli();

signals:

public slots:
    void importMezzi();

};

#endif // MODEL_H
