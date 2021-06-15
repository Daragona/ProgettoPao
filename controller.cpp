#include <iostream>
#include "controller.h"
#include "container.h"
#include "ebike.h"
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

}

void Controller::setModel(Model* m){ model = m;}

void Controller::setView(view* v){viewMezzi = v;}

void Controller::importaMezziController()
{

    QString val;
    QString path ="file.json";
    QFile fileRead(path);

    if(!fileRead.open(QIODevice::ReadOnly | QIODevice::Text)){  // apre il file e controlla se è riuscito ad aprirlo correttamente
        //std::cout << "errore: non si apre i file";
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

       if(arrayObject["Tipo"] == "Mountain-Bike"){ // crea oggetto mountainbike
           p = new mountainbike(
                       arrayObject["Marca"].toString().toStdString()
                     , arrayObject["Modello"].toString().toStdString()
                     , arrayObject["Prezzo"].toDouble()
                     , arrayObject["Quantita"].toInt()
                     , arrayObject["Usata"].toBool()
                     , arrayObject["Telaio"].toString().toStdString()
                     , arrayObject["Manubrio"].toString().toStdString()
                     , arrayObject["Sella"].toString().toStdString()
                     , arrayObject["Corona"].toString().toStdString()
                     , arrayObject["Diametro"].toDouble()
                     , arrayObject["Marce"].toInt()
                     , arrayObject["Ammortizzatori"].toString().toStdString());
       }else    if(arrayObject["Tipo"] == "BMX"){ // crea oggetto bmx
          p= new bmx(
                      arrayObject["Marca"].toString().toStdString()
                    , arrayObject["Modello"].toString().toStdString()
                    , arrayObject["Prezzo"].toDouble()
                    , arrayObject["Quantita"].toInt()
                    , arrayObject["Usata"].toBool()
                    , arrayObject["Telaio"].toString().toStdString()
                    , arrayObject["Manubrio"].toString().toStdString()
                    , arrayObject["Sella"].toString().toStdString()
                    , arrayObject["Corona"].toString().toStdString()
                    , arrayObject["Diametro"].toDouble()
                    , arrayObject["Pad"].toInt());
      }else if(arrayObject["Tipo"] == "E-Bike"){
           p= new ebike(
                       arrayObject["Marca"].toString().toStdString()
                     , arrayObject["Modello"].toString().toStdString()
                     , arrayObject["Prezzo"].toDouble()
                     , arrayObject["Quantita"].toInt()
                     , arrayObject["Usata"].toBool()
                     , arrayObject["Telaio"].toString().toStdString()
                     , arrayObject["Manubrio"].toString().toStdString()
                     , arrayObject["Sella"].toString().toStdString()
                     , arrayObject["Corona"].toString().toStdString()
                     , arrayObject["Diametro"].toDouble()
                     , arrayObject["Watt"].toInt()
                     , arrayObject["Ampere"].toDouble()
                   , arrayObject["Sens. Pedalata"].toString().toStdString()
                   , arrayObject["Sens. Sforzo"].toString().toStdString());

       }else if(arrayObject["Tipo"] == "Monopattino Elettrico"){
           p = new monopattinoElettrico(
                arrayObject["Marca"].toString().toStdString()
                , arrayObject["Modello"].toString().toStdString()
                , arrayObject["Prezzo"].toDouble()
                , arrayObject["Quantita"].toInt()
                , arrayObject["Usata"].toBool()
                , arrayObject["Deck"].toString().toStdString()
                , arrayObject["Collarino"].toString().toStdString()
                , arrayObject["Grip"].toString().toStdString()
                , arrayObject["Watt"].toInt()
                , arrayObject["Ampere"].toDouble()
                , arrayObject["Accelleratore"].toString().toStdString());
       }else return;

       deepPtr<veicolo> *ptr=new deepPtr<veicolo>(p);

       if(!checkVeicolo(*ptr)){
           delete ptr;
             //controlla se esiste un veicolo uguale, se c'è somma le quantità *Nel model* , altrimenti l'aggiunge per la prima volta
           model->addVeicolo(p);
           viewMezzi->showMezzi(p,arrayObject["Tipo"].toString(),arrayObject["Path"].toString());
       }
    }
}

void Controller::esportaMezziController(){
    QString val;
    QString path ="file.json";
    QFile exportFile(path);

    exportFile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&exportFile);   // serve a gestire i flussi di testo siccome il metodo file.write non accetta le stringhe (out << String --> scrive sul file)

    val = "{\n \"arrayMezzi\": [";

    Container<deepPtr<veicolo>>::Const_Iteratore j=model->veicoli.inizioc();

    Container<deepPtr<veicolo>>::Const_Iteratore fine; // usato per simulare null nella condizione

    while(j!=fine){
        out << val;

        deepPtr<veicolo> z(*j); //Puntatore al veicolo j-esimo

        Container<string> values=z->GetInfoExport();

        Container<string>::Const_Iteratore I;
        Container<string>::Const_Iteratore fineStringa;

        val = "\n{\n";
        for(I=values.inizioc(); I!=fineStringa; I++){
            QString toInsert=QString::fromStdString(*I);
            toInsert.replace(",", ".");

            val = val + toInsert;
            if(I != values.finec())
                val = val + ",\n";
            else
                val = val + "\n";
        }

        val = val + "},";


        j++;
    };
    val.remove(val.length()-1,1); //rimuove l'ultima virgola :)

    val = val+"\n] \n }";
    out << val;

    exportFile.close();

}


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

    if(!checkVeicolo(*ptr)){
        model->addVeicolo(Nuova);
        viewMezzi->showMezzi(*ptr,Tipo,*i++);
        delete ptr;
    }

}

//Controlla se esiste un veicolo con i campi uguali a Nuova, se esiste somma le quantità.
bool Controller::checkVeicolo(deepPtr<veicolo> &Nuova) const {
    Container<deepPtr<veicolo>>::Const_Iteratore j=model->veicoli.inizioc();

    Container<deepPtr<veicolo>>::Const_Iteratore fine; // usato per simulare null nella condizione
    while(j!=fine){
        deepPtr<veicolo> z(*j); //Puntatore al veicolo j-esimo
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
