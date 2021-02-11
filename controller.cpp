#include <iostream>
#include "controller.h"
#include "container.h"

#include "mountainbike.h"
#include "bmx.h"
#include "monopattinoelettrico.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QTextStream>
#include <QJsonArray>
#include <typeinfo>
#include <QFile>
#include <QString>
#include <QCoreApplication>
#include <QDir>
Controller::Controller(QObject *parent) : QObject(parent)
{
//    std::cout << "funziona";
//    viewMezzi->showMezzi();

}

void Controller::setModel(Model* m){ model = m;}

void Controller::setView(view* v){viewMezzi = v;}

void Controller::importaMezziController()
{

    // INSERIMENTO DA FILE (VEDERE SE TENERLO QUA O SE FARE UN METODO NEL MODEL )
    QString val;
    QString path = QDir::currentPath();
    //Prende però il path della build, non del progetto. Quindi su qt creator bisogna andare su Projects > run > e in working directory mettere la directory del progetto
    path.append("/test.json");
    QFile fileRead(path);

    if(!fileRead.open(QIODevice::ReadOnly | QIODevice::Text)){  // apre il file e controlla se è riuscito ad aprirlo correttamente
        std::cout << "errore: non si apre i file";
    }
    val = fileRead.readAll(); // legge il file e lo inserisce dentro la QString "val"
    fileRead.close();   // chiude il file (importante)

    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8()); // comando che permette di leggere o fole json

    QJsonObject jObject = doc.object(); // comando che ottiene l'oggetto JSON

    QJsonValue value = jObject.value("arrayMezzi");
    QJsonArray JSONarray = value.toArray();

    for(int i = 0; i < JSONarray.size(); i++){
       QJsonObject arrayObject = JSONarray[i].toObject();

       if(arrayObject["tipo"] == "mountainbike"){ // crea oggetto mountainbike

           mountainbike* p = new mountainbike(
                       arrayObject["Marca"].toString().toStdString()
                     , arrayObject["Modello"].toString().toStdString()
                     , arrayObject["Price"].toDouble()
                     , arrayObject["Quantity"].toInt()
                     , arrayObject["Used"].toBool()
                     , arrayObject["Telaio"].toString().toStdString()
                     , arrayObject["Manubrio"].toString().toStdString()
                     , arrayObject["Sella"].toString().toStdString()
                     , arrayObject["Corona"].toString().toStdString()
                     , arrayObject["dimRuote"].toDouble()
                     , arrayObject["numMarce"].toInt()
                     , arrayObject["Ammortizzatori"].toString().toStdString());
           model->addVeicolo(p);
           viewMezzi->showMezzi(p,arrayObject["tipo"].toString());
       }

      if(arrayObject["tipo"] == "bmx"){ // crea oggetto bmx
          bmx* s = new bmx(
                      arrayObject["Marca"].toString().toStdString()
                    , arrayObject["Modello"].toString().toStdString()
                    , arrayObject["Price"].toDouble()
                    , arrayObject["Quantity"].toInt()
                    , arrayObject["Used"].toBool()
                    , arrayObject["Telaio"].toString().toStdString()
                    , arrayObject["Manubrio"].toString().toStdString()
                    , arrayObject["Sella"].toString().toStdString()
                    , arrayObject["Corona"].toString().toStdString()
                    , arrayObject["dimRuote"].toDouble()
                    , arrayObject["Pad"].toInt());
          model->addVeicolo(s);
          viewMezzi->showMezzi(s,arrayObject["tipo"].toString());
      }
    }
}


void Controller::showMezzi(){
    //viewMezzi->showMezzi();
};

void Controller::createVeicolo(QStringList *Lista){
    QStringList::iterator i;

    i=Lista->begin();
    veicolo *Nuova;
    QString Tipo=*i++;

    if(Tipo=="E-Bike"){
        Nuova=new ebike(
                    (*i++).toStdString(),
                    (*i++).toStdString(),
                    (*i++).toDouble(),
                    (*i++).toInt(),
                    (*i++).toInt(),

                    (*i++).toStdString(),
                    (*i++).toStdString(),
                    (*i++).toStdString(),
                    (*i++).toStdString(),
                    (*i++).toDouble(),
                    (*i++).toInt(),
                    (*i++).toDouble(),
                    (*i++).toStdString(),
                    (*i++).toStdString()
                    );
    }else if(Tipo=="BMX"){
        Nuova=new bmx((*i++).toStdString(),
                           (*i++).toStdString(),
                           (*i++).toDouble(),
                           (*i++).toInt(),
                           (*i++).toInt(),

                           (*i++).toStdString(),
                           (*i++).toStdString(),
                           (*i++).toStdString(),
                           (*i++).toStdString(),
                           (*i++).toDouble(),
                           (*i++).toInt()
                           );

    }else if(Tipo=="Mountain-Bike"){
        Nuova=new mountainbike((*i++).toStdString(),
                           (*i++).toStdString(),
                           (*i++).toDouble(),
                           (*i++).toInt(),
                           (*i++).toInt(),

                           (*i++).toStdString(),
                           (*i++).toStdString(),
                           (*i++).toStdString(),
                           (*i++).toStdString(),
                           (*i++).toDouble(),
                           (*i++).toInt(),
                           (*i++).toStdString()
                           );

    }else /*if(Tipo=="Monopattino Elettrico")*/{
        Nuova=new monopattinoElettrico(
                           (*i++).toStdString(),
                           (*i++).toStdString(),
                           (*i++).toDouble(),
                           (*i++).toInt(),
                           (*i++).toInt(),

                           (*i++).toStdString(),
                           (*i++).toStdString(),
                           (*i++).toStdString(),
                           (*i++).toInt(),
                           (*i++).toDouble(),
                           (*i++).toStdString());
    }
    deepPtr<veicolo> *ptr=new deepPtr<veicolo>(Nuova);
    model->addVeicolo(Nuova);

    viewMezzi->showMezzi(*ptr,Tipo,*i++);


}

void Controller::deleteVeicolo(deepPtr<veicolo> toRemove){
    //model->removeVeicolo(toRemove);
}
