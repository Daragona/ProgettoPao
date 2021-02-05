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

void Model::importMezzi()
{
//    QString val;
//    QFile fileRead("C:/Users/Claudio/Documents/GitHub/ProgettoPao/test.json");

//    if(!fileRead.open(QIODevice::ReadOnly | QIODevice::Text)){  // apre il file e controlla se è riuscito ad aprirlo correttamente
//        std::cout << "file non aperto";
//    }

//    val = fileRead.readAll(); // legge il file e lo inserisce dentro la QString "val"
//    fileRead.close();   // chiude il file (importante)

//    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8()); // comando che permette di leggere o fole json

//    QJsonObject jObject = doc.object(); // comando che ottiene l'oggetto JSON

//    QJsonValue value = jObject.value("arrayMezzi");
//    QJsonArray JSONarray = value.toArray();

//    for(int i = 0; i < JSONarray.size(); i++){
//       QJsonObject arrayObject = JSONarray[i].toObject();

//       if(arrayObject["tipo"] == "mountainbike") // crea oggetto mountainbike
//           mountainbike bici(arrayObject["Sella"].toString().toStdString()
//                   , arrayObject["Corona"].toString().toStdString()
//                   , arrayObject["dimRuote"].toDouble()
//                   , arrayObject["Marca"].toString().toStdString()
//                   , arrayObject["Modello"].toString().toStdString()
//                   , arrayObject["Telaio"].toString().toStdString()
//                   , arrayObject["Manubrio"].toString().toStdString()
//                   , arrayObject["Price"].toDouble()
//                   , arrayObject["Quantity"].toInt()
//                   , arrayObject["Used"].toBool()
//                   , arrayObject["numMarce"].toInt()
//                   , arrayObject["Ammortizzatori"].toString().toStdString());

//       if(arrayObject["tipo"] == "bmx") // crea oggetto bmx
//           bmx bici(arrayObject["Sella"].toString().toStdString()
//                   , arrayObject["Corona"].toString().toStdString()
//                   , arrayObject["dimRuote"].toDouble()
//                   , arrayObject["Marca"].toString().toStdString()
//                   , arrayObject["Modello"].toString().toStdString()
//                   , arrayObject["Telaio"].toString().toStdString()
//                   , arrayObject["Manubrio"].toString().toStdString()
//                   , arrayObject["Price"].toDouble()
//                   , arrayObject["Quantity"].toInt()
//                   , arrayObject["Used"].toBool()
//                   , arrayObject["Pad"].toInt());
//    }


//    in alternativa si può scorrere così
//    foreach (const QJsonValue & v, JSONarray)
//        c

    //deepPtr<veicolo> prova;

    //c.push_back(c);
//    std::cout << typeid(prova).name();
//    //veicoli.push_back(prova);

}

void Model::addVeicolo(QStringList *Lista){
    QStringList::iterator i;

    i=Lista->begin();
    veicolo *Nuova;
    QString Tipo=*i++;

    if(Tipo=="E-Bike"){
        Nuova=new ebike(
                    (*i++).toStdString(),
                    (*i++).toStdString(),
                    (*i++).toStdString(),
                    (*i++).toStdString(),
                    (*i++).toDouble(),
                    (*i++).toInt(),
                    (*i++).toInt(),

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
                           (*i++).toStdString(),
                           (*i++).toStdString(),
                           (*i++).toDouble(),
                           (*i++).toInt(),
                           (*i++).toInt(),

                           (*i++).toStdString(),
                           (*i++).toStdString(),
                           (*i++).toDouble(),
                           (*i++).toInt()
                           );

    }else if(Tipo=="Mountain-Bike"){
        Nuova=new mountainbike((*i++).toStdString(),
                           (*i++).toStdString(),
                           (*i++).toStdString(),
                           (*i++).toStdString(),
                           (*i++).toDouble(),
                           (*i++).toInt(),
                           (*i++).toInt(),

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

    veicoli.push_back(Nuova);

    }

