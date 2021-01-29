#include "controller.h"
#include "iostream"
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QTextStream>
#include <QJsonArray>
#include <typeinfo>
#include <QFile>
#include <container.h>


Controller::Controller(QObject *parent) : QObject(parent)
{
//    std::cout << "funziona";
//    viewMezzi->showMezzi();

}
void Controller::setModel(Model* m){ model = m;}

void Controller::setView(view* v){viewMezzi = v;}



void Controller::importaMezziController()
{
//    int i = 10;
//    deepPtr<int> p(&i);

//    Container<deepPtr<int>> v;
//    v.push_back(p);



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

       if(arrayObject["tipo"] == "mountainbike") // crea oggetto mountainbike
           qDebug() << arrayObject["tipo"].toString();

       if(arrayObject["tipo"] == "bmx") // crea oggetto bmx
           qDebug() << arrayObject["tipo"].toString();

       if(arrayObject["tipo"] == "monopattinoElettrico") // crea oggetto monopattinoElettrico
           qDebug() << arrayObject["tipo"].toString();
    }



//    mountainbike bici("Sella", "Corona", 12.2, "Marca","Modello", "Telaio", "Manubrio",650.50, 4, 0, 5,"Ammortizzatori");

//    deepPtr<veicolo> prova(mountainbike bici);

//    QString s = typeid(*prova).name() ;

}



void Controller::showMezzi(){
    viewMezzi->showMezzi();
};
