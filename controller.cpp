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
    QFile fileRead("C:/Users/Claudio/Documents/GitHub/ProgettoPao/test.json");

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

           mountainbike* p = new mountainbike(arrayObject["Sella"].toString().toStdString()
                   , arrayObject["Corona"].toString().toStdString()
                   , arrayObject["dimRuote"].toDouble()
                   , arrayObject["Marca"].toString().toStdString()
                   , arrayObject["Modello"].toString().toStdString()
                   , arrayObject["Telaio"].toString().toStdString()
                   , arrayObject["Manubrio"].toString().toStdString()
                   , arrayObject["Price"].toDouble()
                   , arrayObject["Quantity"].toInt()
                   , arrayObject["Used"].toBool()
                   , arrayObject["numMarce"].toInt()
                   , arrayObject["Ammortizzatori"].toString().toStdString());
           model->veicoli.push_back(p);
       }

      if(arrayObject["tipo"] == "bmx"){ // crea oggetto bmx

          bmx* s = new bmx(arrayObject["Sella"].toString().toStdString()
                  , arrayObject["Corona"].toString().toStdString()
                  , arrayObject["dimRuote"].toDouble()
                  , arrayObject["Marca"].toString().toStdString()
                  , arrayObject["Modello"].toString().toStdString()
                  , arrayObject["Telaio"].toString().toStdString()
                  , arrayObject["Manubrio"].toString().toStdString()
                  , arrayObject["Price"].toDouble()
                  , arrayObject["Quantity"].toInt()
                  , arrayObject["Used"].toBool()
                  , arrayObject["Pad"].toInt());
          model->veicoli.push_back(s);
      }
    }

    // FUNZIONA, BISOGNA TROVARE UN MODO MIGLIORE PER ITERARE PERCHE' ALTRIMENTI L'ULTIMO MEMBRO VA FATTO FUORI DAL CICLO

    Container<deepPtr<veicolo>>::Iteratore j;
    for(j = model->veicoli.inizio(); j != model->veicoli.fine(); ++j) {
        deepPtr<veicolo> z(*j);

        QString immagine = "";
        QString Modello = QString::fromStdString(z->getModello());
        QString Quantita = QString::number(z->getQuantita());
        QString Prezzo = QString::number(z->getPrezzo());

        viewMezzi->showMezzi(immagine, Modello,Quantita,Prezzo);

    }
    j= model->veicoli.fine();
    deepPtr<veicolo> z(*j);

    QString immagine = "";
    QString Modello = QString::fromStdString(z->getModello());
    QString Quantita = QString::number(z->getQuantita());
    QString Prezzo = QString::number(z->getPrezzo());

    viewMezzi->showMezzi(immagine, Modello,Quantita,Prezzo);


}



void Controller::showMezzi(){


    //viewMezzi->showMezzi();
};
