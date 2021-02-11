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
    auto I=veicoli.inizio();
}
void Model::removeVeicolo(deepPtr<veicolo> toRemove){
    /*auto I=veicoli.inizio();
    while(I!=veicoli.fine() && (*I==toRemove)){
        if(*I==toRemove){
            I->~deepPtr<veicolo>();
        }
    }
*/
}

