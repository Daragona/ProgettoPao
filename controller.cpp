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
    QString path ="test.json"; //Risolto così
    QFile fileRead(path);

    if(!fileRead.open(QIODevice::ReadOnly | QIODevice::Text)){  // apre il file e controlla se è riuscito ad aprirlo correttamente
        std::cout << "errore: non si apre i file";
        return;
    }
    val = fileRead.readAll(); // legge il file e lo inserisce dentro la QString "val"
    fileRead.close();   // chiude il file (importante)

    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8()); // comando che permette di leggere o fole json

    QJsonObject jObject = doc.object(); // comando che ottiene l'oggetto JSON

    QJsonValue value = jObject.value("arrayMezzi");
    QJsonArray JSONarray = value.toArray();

    for(int i = 0; i < JSONarray.size(); i++){
       QJsonObject arrayObject = JSONarray[i].toObject();
        veicolo *p;
       if(arrayObject["tipo"] == "mountainbike"){ // crea oggetto mountainbike
           p = new mountainbike(
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
       }else    if(arrayObject["tipo"] == "bmx"){ // crea oggetto bmx
          p= new bmx(
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
      }else if(arrayObject["tipo"] == "e-bike"){
           p=nullptr;
       }else{
           p=nullptr;
       }
       deepPtr<veicolo> *ptr=new deepPtr<veicolo>(p);

       if(!checkVeicolo(*ptr)){
           delete ptr; //Così non da un warning
             //controlla se esiste un veicolo uguale, se c'è somma le quantità *Nel model* , altrimenti l'aggiunge per la prima volta
           model->addVeicolo(p);
           viewMezzi->showMezzi(p,arrayObject["tipo"].toString(),arrayObject["Path"].toString());
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

    if(!checkVeicolo(*ptr)){//Funziona :)
        model->addVeicolo(Nuova);
        viewMezzi->showMezzi(*ptr,Tipo,*i++);
        delete ptr;
    }

}

//Controlla se esiste un veicolo con i campi uguali a Nuova, se esiste somma le quantità.
bool Controller::checkVeicolo(deepPtr<veicolo> &Nuova){
    Container<deepPtr<veicolo>>::Const_Iteratore j=model->veicoli.inizioc(); //fixare il copy-ctor (importante, credo)

    while(j!=model->veicoli.finec()){ //Scorre tutti i veicoli all'interno di model->veicoli e vede se ce n'è uno uguale a *Nuova
        deepPtr<veicolo> z(*j); //Puntatore al veicolo j
        if(*z==*Nuova ){
            z->setQuantita(Nuova->getQuantita()+z->getQuantita()); //somma quantità
            return true; //Se ha trovato un veicolo uguale, non serve che continua a cercare
        }
        j++;
    };

    return false;
}
//Ritorna false se non trova il veicolo Nuova nella lista veicoli. Se lo trova somma le quantità e ritorna true

void Controller::deleteVeicolo(deepPtr<veicolo> &toRemove){
    model->removeVeicolo(toRemove);

}
