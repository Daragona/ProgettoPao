#include "view.h"
#include "mountainbike.h"
#include "container.h"
#include "controller.h"
#include "qsecondpage.h"
#include "qwidgetveicolo.h"

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
    this->setStyleSheet("background:#f8fff0");
    this->setStyleSheet("QPushButton {border: 1px solid black;border-radius: 5px;background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde)}"
        "QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}"
    );



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

    titoloVeicolo->setText("<center><h2>VEICOLI</h2></center>");
    titoloVeicoloElettrico->setText("<center><h2>VEICOLI ELETTRICI</h2></center>");

    // i due box che contengono uno le bici e uno i monopattini
    QVBoxLayout *veicoloLayout=new QVBoxLayout;
    veicoloLayout->setAlignment(Qt::AlignTop);
    QVBoxLayout* veicoloElettricoLayout = new QVBoxLayout;
    veicoloElettricoLayout->setAlignment(Qt::AlignTop);

    veicoloList = new QScrollArea();
    veicoloList->setFixedSize(400,450);
    veicoloList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    veicoloList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    veicoloList->setWidgetResizable(0);
    veicoloList->setStyleSheet("background:#f9ffbf;border:1px solid black");
    veicoloList->verticalScrollBar()->setStyleSheet("background: #f9ffbf;");
    veicoloElettricoList = new QScrollArea();
    veicoloElettricoList->setFixedSize(400,450);
    veicoloElettricoList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    veicoloElettricoList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    veicoloElettricoList->setWidgetResizable(0);
    veicoloElettricoList->setStyleSheet("background:#d1ffd9;border:1px solid black");
    veicoloElettricoList->verticalScrollBar()->setStyleSheet("background: #d1ffd9;");

    QWidget *widgetLista=new QWidget;
    QWidget *widgetListaElettrico=new QWidget;
    widgetLista->setFixedSize(veicoloList->width()-20,0);
    widgetLista->setStyleSheet("background-color:#fbffd9");
    widgetListaElettrico->setFixedSize(veicoloElettricoList->width()-20, 0);
    widgetListaElettrico->setStyleSheet("background-color:#e8ffec");

    widgetLista->setLayout(veicoloLayout);
    veicoloList->setWidget(widgetLista);
    widgetListaElettrico->setLayout(veicoloElettricoLayout);
    veicoloElettricoList->setWidget(widgetListaElettrico);

    screenLayout->addWidget(titoloVeicolo,1,0);
    screenLayout->addWidget(titoloVeicoloElettrico,1,1);
    screenLayout->addWidget(veicoloList,2,0);
    screenLayout->addWidget(veicoloElettricoList,2,1);

    Inserisci = new QPushButton("&Inserisci", this);
    Inserisci->setFixedHeight(35);

    Importa = new QPushButton("Importa");
    Importa->setFixedSize(60,40);
    screenLayout->addWidget(Inserisci,3,1);
    screenLayout->addWidget(Importa,1,2);
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
    qwidgetveicolo *item=new qwidgetveicolo(toInsert,path,this,ctrl,Tipo);
    item->setMaximumHeight(140);
    item->setStyleSheet("background-color:white; border:1px solid black");
    if(Tipo=="E-Bike" || Tipo =="Monopattino Elettrico"){
        veicoloElettricoList->widget()->layout()->addWidget(item);
        veicoloElettricoList->widget()->setFixedHeight(veicoloElettricoList->widget()->layout()->count()*140+10);

    }else{
        veicoloList->widget()->layout()->addWidget(item);
        veicoloList->widget()->setFixedHeight(veicoloList->widget()->layout()->count()*140+10);
    }
}



// quando clicchi sul bottone inserisci
void view::showInsertDialog(){
    if(!wdg || !wdg->isOpen()){
        wdg=new QSecondPage(ctrl);
        wdg->show();
    }
}



Controller* view::getCtrl(){
    return ctrl;
}
