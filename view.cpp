#include "view.h"
#include "mountainbike.h"
#include "container.h"
#include "controller.h"
#include "qsecondpage.h"

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
#include <QScrollBar>

//MAIN ---------------
view::view(QWidget *parent): QWidget(parent) {
    this->setFixedHeight(650);
    QGridLayout* screenLayout = new QGridLayout; //Layout centrale del programma

    QMenuBar* menuBar = new QMenuBar(this);
    QMenu* file = new QMenu("file", menuBar);
    menuBar->addMenu(file);

    QLabel* titoloInventario = new QLabel; // Titolo
    titoloInventario->setFixedHeight(30);
    titoloInventario->setText("<center><h1>INVENTARIO</h1></center>");
    screenLayout->addWidget(titoloInventario,0,0);

    //itemsList(screenLayout);
    // metodo per creare i box che contengono i mezzi

    QLabel* titoloVeicolo = new QLabel;
    QLabel* titoloVeicoloElettrico = new QLabel;
    titoloVeicolo->setFixedHeight(25);
    titoloVeicoloElettrico->setFixedHeight(25);

    titoloVeicolo->setText("<center><h2>VEICOLO</h2></center>");
    titoloVeicoloElettrico->setText("<center><h2>VEICOLO ELETTRICO</h2></center>");

    // i due box che contengono uno le bici e uno i monopattini
    QVBoxLayout *veicoloLayout=new QVBoxLayout;
    QVBoxLayout* veicoloElettricoLayout = new QVBoxLayout;

    veicoloList = new QScrollArea();
    veicoloList->setFixedSize(400,450);
    veicoloList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    veicoloList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    veicoloList->setWidgetResizable(0);
    veicoloList->setStyleSheet("background-color:white; border:1px solid black");
    veicoloElettricoList = new QScrollArea();
    veicoloElettricoList->setFixedSize(400,450);
    veicoloElettricoList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    veicoloElettricoList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    veicoloElettricoList->setWidgetResizable(0);
    veicoloElettricoList->setStyleSheet("background-color:white;border:1px solid black");

    QWidget *widgetLista=new QWidget;
    QWidget *widgetListaElettrico=new QWidget;
    widgetLista->setFixedSize(veicoloList->width()-20,0);
    widgetLista->setStyleSheet("background-color:grey");
    widgetListaElettrico->setFixedSize(veicoloElettricoList->width()-20, 0);
    widgetListaElettrico->setStyleSheet("background-color:grey");

    widgetLista->setLayout(veicoloLayout);
    veicoloList->setWidget(widgetLista);
    widgetListaElettrico->setLayout(veicoloElettricoLayout);
    veicoloElettricoList->setWidget(widgetListaElettrico);

    screenLayout->addWidget(titoloVeicolo,1,0);
    screenLayout->addWidget(titoloVeicoloElettrico,1,1);
    screenLayout->addWidget(veicoloList,2,0);
    screenLayout->addWidget(veicoloElettricoList,2,1);

    Usato = new QPushButton("&Usato", this);
    Inserisci = new QPushButton("&Inserisci", this);
    Importa = new QPushButton("Importa");
    Importa->setFixedSize(60,40);
    screenLayout->addWidget(Usato,3,0);
    screenLayout->addWidget(Inserisci,3,1);
    screenLayout->addWidget(Importa,1,3);

    setLayout(screenLayout);
}

//FUNZIONI ------------------

// setter per collegare la vista agli eventi
void view::setController(Controller *c)
{
    ctrl = c;
    connect(Importa, SIGNAL(clicked()), ctrl, SLOT(importaMezziController()));
    connect(Inserisci, &QPushButton::released, this, &view::showInsertDialog);

}

// metodo per la creazione dell'oggetto
void view::showMezzi(deepPtr<veicolo> toInsert, QString Tipo, QString path){

    qwidgetveicolo *item=new qwidgetveicolo(toInsert,path);
    item->setMaximumHeight(100);
    item->setStyleSheet("background-color:white; border:1px solid black");
    if(Tipo=="E-Bike" || Tipo =="Monopattino Elettrico"){
        veicoloElettricoList->widget()->layout()->addWidget(item);
        veicoloElettricoList->widget()->setFixedHeight(veicoloElettricoList->widget()->height()+item->height()+5);
    }else{
        veicoloList->widget()->layout()->addWidget(item);
        veicoloList->widget()->setFixedHeight(veicoloList->widget()->height()+item->height()+5);
    }

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
    if(!wdg || !wdg->isOpen()){
        wdg=new QSecondPage(ctrl);
        wdg->show();
    }
}



