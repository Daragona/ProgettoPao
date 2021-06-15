#include "model.h"
#include "mountainbike.h"
#include "bmx.h"
#include "monopattinoelettrico.h"
#include "container.h"
#include <QMessageBox>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QTextStream>
#include <QJsonArray>
#include <typeinfo>
#include <iostream>

Model::Model() {}

void Model::importMezzi(){

}

void Model::addVeicolo(deepPtr<veicolo> toInsert){
    veicoli.push_back(toInsert);

    //auto I=veicoli.inizio();
}

void Model::removeVeicolo(deepPtr<veicolo> toRemove){
    bool presente = false;
    Container<deepPtr<veicolo>>::Iteratore j;

    veicoli.deleteNodo(toRemove);

    j = veicoli.inizio();
    for(unsigned int i = 0; i < veicoli.size() && presente != true; i++){

        deepPtr<veicolo> z(*j);
        ++j;

    }


}

