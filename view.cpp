#include "view.h"
#include "mountainbike.h"
#include <QMessageBox>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QTextStream>
#include <QJsonArray>
#include <typeinfo>

//MAIN ---------------

view::view(QWidget *parent): QWidget(parent) {

    QGridLayout* screenLayout = new QGridLayout; //Layout centrale del programma

    QMenuBar* menuBar = new QMenuBar(this);
    QMenu* file = new QMenu("file", menuBar);
    menuBar->addMenu(file);

    QLabel* titoloInventario = new QLabel; // Titolo
    titoloInventario->setText("INVENTARIO");
    screenLayout->addWidget(titoloInventario,0,0);


    // metodo per creare i box che contengono i mezzi
    itemsList(screenLayout);

    //footer dove sono contenuti i pulsanti per l'inserimento e per vedere l'usato

    QPushButton *Usato = new QPushButton("&Usato", this);
    QPushButton *Inserisci = new QPushButton("&Inserisci", this);

    connect(Inserisci, &QPushButton::released, this, &view::showInsertDialog);


    screenLayout->addWidget(Usato,3,0);
    screenLayout->addWidget(Inserisci,3,1);


    QPushButton *Importa = new QPushButton("&Importa", this);

    connect(Importa, &QPushButton::released, this, &view::importMezzi);

    screenLayout->addWidget(Importa,1,3);






    setLayout(screenLayout);
    resize(QSize(1024, 720));

    //showInsertDialog();

}

//FUNZIONI ------------------

//Body del programma

void view::itemsList(QGridLayout* screenLayout)
{
    QLabel* titoloVeicolo = new QLabel;
    QLabel* titoloVeicoloElettrico = new QLabel;

    titoloVeicolo->setText("VEICOLO");
    titoloVeicoloElettrico->setText("VEICOLO ELETTRICO");

    // i due box che contengono uno le bici e uno i monopattini
    QVBoxLayout* veicoloLayout = new QVBoxLayout;
    QVBoxLayout* veicoloElettricoLayout = new QVBoxLayout;

    QFrame* veicoloList = new QFrame;
    QFrame* veicoloElettricoList = new QFrame;

    veicoloLayout->addWidget(titoloVeicolo);
    veicoloElettricoLayout->addWidget(titoloVeicoloElettrico);

    veicoloList->setLayout(veicoloLayout);
    veicoloElettricoList->setLayout(veicoloElettricoLayout);


    veicoloList->setStyleSheet("background-color:white; border:1px solid black");
    veicoloElettricoList->setStyleSheet("background-color:white;border:1px solid black");

    screenLayout->addWidget(titoloVeicolo,1,0);
    screenLayout->addWidget(titoloVeicoloElettrico,1,1);

    for(int i = 0; i < 9; i++)
        createItem(veicoloLayout, veicoloElettricoLayout); // creazione dell'item

    //showMoreInfo();


    screenLayout->addWidget(veicoloList,2,0);
    screenLayout->addWidget(veicoloElettricoList,2,1);

}

// metodo per la creazione dell'oggetto
void view::createItem(QVBoxLayout* veicoloLayout, QVBoxLayout* veicoloElettricoLayout)
{

    QFrame* item = new QFrame;
    QGridLayout* itemLayout = new QGridLayout; //Layout centrale del programma

    QFrame* image = new QFrame;
    QVBoxLayout* imageItemLayout = new QVBoxLayout;
    imageItemLayout->addWidget(new QLabel(this));
    image->setStyleSheet(" border:1px solid black");

    QLabel* nomeItem = new QLabel;
    nomeItem->setText("Grazziella");

    QLabel* quantitaItem = new QLabel;
    quantitaItem-> setText("22");

    QPushButton *deleteButton = new QPushButton("&Delete", this);
    QPushButton *moreInfoButton = new QPushButton("&More info", this);

    itemLayout->addWidget(image,0,1,0,1);
    itemLayout->addWidget(nomeItem,0,2);
    itemLayout->addWidget(quantitaItem,0,3);
    itemLayout->addWidget(deleteButton,0,4);
    itemLayout->addWidget(moreInfoButton,1,4);

    item->setLayout(itemLayout);

    veicoloLayout->addWidget(item);
}

// finestra che si apre quando clicchi il pulsante more info sul singolo item
void view::showMoreInfo()
{
    QDialog* moreInfo = new QDialog(this);

    QVBoxLayout* moreInfoLayout = new QVBoxLayout();

    QLabel* dettagliMezzo = new QLabel;
    dettagliMezzo-> setText("Dettagli mezzo");

    // qua ci va la lista

    moreInfoLayout->addWidget(dettagliMezzo);

    // anzichè avere l'array avremo la nostra classe container

    for(int i = 0; i < 9 ; i++){
        QLabel* prova = new QLabel;
        prova-> setText("item");
        moreInfoLayout->addWidget(prova);
    }


    moreInfo->resize(400,600);
    moreInfo->setLayout(moreInfoLayout);
    moreInfo->show();
}

// quando clicchi sul bottone inserisci
void view::showInsertDialog(){
    QSecondPage *wdg=new QSecondPage();
    wdg->show();

}

void view::importMezzi()
{
    QString val;
    QFile fileRead("C:/Users/Claudio/Documents/GitHub/ProgettoPao/test.json");

    if(!fileRead.open(QIODevice::ReadOnly | QIODevice::Text)){  // apre il file e controlla se è riuscito ad aprirlo correttamente
        QMessageBox msgBox;
        msgBox.setText("File non aperto");
        msgBox.exec();
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

       if(arrayObject["tipo"] == "mountainbike") // crea oggetto mountainbike
           qDebug() << arrayObject["tipo"].toString();

       if(arrayObject["tipo"] == "bmx") // crea oggetto bmx
           qDebug() << arrayObject["tipo"].toString();

       if(arrayObject["tipo"] == "monopattinoElettrico") // crea oggetto monopattinoElettrico
           qDebug() << arrayObject["tipo"].toString();
    }
    QMessageBox msgBox;
    msgBox.setText("Inserimento completato");
    msgBox.exec();
//    in alternativa si può scorrere così
//    foreach (const QJsonValue & v, JSONarray)
//        c

    // questo è un pattern su come inserire effettivamente gli oggetti
//    mountainbike bici(arrayObject["Sella"].toString().toStdString()
//            , "Corona", arrayObject["dimRuote"].toDouble()
//            , arrayObject["Marca"].toString().toStdString()
//            , arrayObject["Modello"].toString().toStdString()
//            , arrayObject["Telaio"].toString().toStdString()
//            , arrayObject["Manubrio"].toString().toStdString()
//            , arrayObject["Price"].toDouble()
//            , arrayObject["Quantity"].toInt()
//            , arrayObject["Used"].toBool()
//            , arrayObject["numMarce"].toInt()
//            , arrayObject["Ammortizzatori"].toString().toStdString());


    mountainbike bici("Sella", "Corona", 12.2, "Marca","Modello", "Telaio", "Manubrio",650.50, 4, 0, 5,"Ammortizzatori");

    deepPtr<veicolo> prova(mountainbike bici);

    QString s = typeid(*prova).name() ;
}


