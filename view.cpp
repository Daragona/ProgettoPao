#include "view.h"
#include "mountainbike.h"
#include "container.h"
#include "controller.h"

#include <iostream>

#include <QLayout>
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





    //itemsList(screenLayout);
    // metodo per creare i box che contengono i mezzi


    QLabel* titoloVeicolo = new QLabel;
    QLabel* titoloVeicoloElettrico = new QLabel;

    titoloVeicolo->setText("VEICOLO");
    titoloVeicoloElettrico->setText("VEICOLO ELETTRICO");

    // i due box che contengono uno le bici e uno i monopattini
    QVBoxLayout* veicoloLayout = new QVBoxLayout;
    QVBoxLayout* veicoloElettricoLayout = new QVBoxLayout;

    veicoloList = new QFrame;
    veicoloElettricoList = new QFrame;

    veicoloLayout->addWidget(titoloVeicolo);
    veicoloElettricoLayout->addWidget(titoloVeicoloElettrico);

    veicoloList->setLayout(veicoloLayout);
    veicoloElettricoList->setLayout(veicoloElettricoLayout);


    veicoloList->setStyleSheet("background-color:white; border:1px solid black");
    veicoloElettricoList->setStyleSheet("background-color:white;border:1px solid black");

    screenLayout->addWidget(titoloVeicolo,1,0);
    screenLayout->addWidget(titoloVeicoloElettrico,1,1);


    //showMezzi(5);







    //showMezzi(veicoloLayout, veicoloElettricoLayout); // creazione dell'item

    //showMoreInfo();


    screenLayout->addWidget(veicoloList,2,0);
    screenLayout->addWidget(veicoloElettricoList,2,1);

    //footer dove sono contenuti i pulsanti per l'inserimento e per vedere l'usato

    Usato = new QPushButton("&Usato", this);
    Inserisci = new QPushButton("&Inserisci", this);


    screenLayout->addWidget(Usato,3,0);
    screenLayout->addWidget(Inserisci,3,1);


    Importa = new QPushButton("Importa");
    screenLayout->addWidget(Importa,1,3);

    setLayout(screenLayout);
    resize(QSize(1024, 720));

    //showInsertDialog();

}

//FUNZIONI ------------------

// setter per collegare la vista agli eventi
void view::setController(Controller *c)
{
    controller = c;
    connect(Importa, SIGNAL(clicked()), controller, SLOT(importaMezziController()));
    connect(Inserisci, &QPushButton::released, this, &view::showInsertDialog);

}


// metodo per la creazione dell'oggetto
void view::showMezzi()
{

    QFrame* item = new QFrame;
    QGridLayout* itemLayout = new QGridLayout; //Layout centrale del programma

    QFrame* image = new QFrame;
    QVBoxLayout* imageItemLayout = new QVBoxLayout;
    imageItemLayout->addWidget(new QLabel());
    image->setStyleSheet(" border:1px solid black");

    QLabel* nomeItem = new QLabel;
    nomeItem->setText("Grazziella");

    QLabel* quantitaItem = new QLabel;
    quantitaItem-> setText("22");

    QPushButton *deleteButton = new QPushButton("&Delete");
    QPushButton *moreInfoButton = new QPushButton("&More info");

    itemLayout->addWidget(image,0,1,0,1);
    itemLayout->addWidget(nomeItem,0,2);
    itemLayout->addWidget(quantitaItem,0,3);
    itemLayout->addWidget(deleteButton,0,4);
    itemLayout->addWidget(moreInfoButton,1,4);

    item->setLayout(itemLayout);

    veicoloList->layout()->addWidget(item);
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



