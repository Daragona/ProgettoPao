#include "qwidgetveicolo.h"
#include <QFrame>
#include <QFormLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

qwidgetveicolo::qwidgetveicolo(deepPtr<veicolo> toInsert, QString path, view *parent, Controller *c) : QWidget(dynamic_cast<QWidget*>(parent)), ptrVeicolo(toInsert), vista(parent), ctrl(c){
    QGridLayout* itemLayout = new QGridLayout; //Layout centrale del programma
    QFrame *item=new QFrame;
    QLabel *imageLabel = new QLabel;
    imageLabel->setFixedSize(70,70);

    QImage image=(new QImage(path))->scaled(imageLabel->width(),imageLabel->height());
    imageLabel->setPixmap(QPixmap::fromImage(image));
    imageLabel->setStyleSheet(" border:1px solid black");

    QLabel* marcaItem = new QLabel;
    marcaItem->setText(QString::fromStdString(ptrVeicolo->getMarca()));

    QLabel* modelloItem = new QLabel;
    modelloItem->setText(QString::fromStdString(ptrVeicolo->getModello()));

    QLabel* quantitaItem = new QLabel;
    quantitaItem-> setText("Stock: "+QString::number(ptrVeicolo->getQuantita()));
    QLabel* prezzoItem = new QLabel;
    prezzoItem-> setText(QString::number(ptrVeicolo->getPrezzo())+"€");

    QPushButton *deleteButton = new QPushButton("&Delete");
    QPushButton *moreInfoButton = new QPushButton("&More info");
    connect(deleteButton, &QPushButton::released, this, &qwidgetveicolo::deleteSlot);
    connect(moreInfoButton, &QPushButton::released, this, &qwidgetveicolo::moreInfoSlot);


    itemLayout->addWidget(imageLabel,0,0,0,0);
    itemLayout->addWidget(marcaItem,0,1);
    itemLayout->addWidget(modelloItem,0,2);
    itemLayout->addWidget(quantitaItem,1,1);
    itemLayout->addWidget(prezzoItem,1,2);

    itemLayout->addWidget(deleteButton,0,3);
    itemLayout->addWidget(moreInfoButton,1,3);

    item->setLayout(itemLayout);
    QVBoxLayout *total=new QVBoxLayout;
    total->addWidget(item);
    total->setSpacing(10);

    this->setLayout(total);
    this->setFixedHeight(110);
    this->setStyleSheet("border:1px solid black");

}

void qwidgetveicolo::deleteSlot(){
    //vista.getCtrl()->deleteVeicolo(ptrVeicolo);
    ctrl->deleteVeicolo(ptrVeicolo);
    this->~qwidgetveicolo();
}

void qwidgetveicolo::moreInfoSlot(){
    if(moreInfo) return;
    moreInfo=true;
    moreInfoPage=new QWidget();
    moreInfoPage->setWindowFlags ( Qt::CustomizeWindowHint | Qt::WindowTitleHint);

    QVBoxLayout *mainLayout=new QVBoxLayout(moreInfoPage);

    QGroupBox *groupBox= new QGroupBox ("Informazioni: ");
    QGridLayout *boxLayout=new QGridLayout(groupBox);
    mainLayout->addWidget(groupBox);

    Container<string> values=ptrVeicolo->GetInfo();
    Container<string>::Iteratore I;
    for(I=values.inizio();I!=values.fine();I++){
        QLabel *label=new QLabel(QString::fromStdString(*I));
        boxLayout->addWidget(label);
    }
    //QLabel *label=new QLabel(QString::fromStdString(*I));
    //boxLayout->addWidget(label);


    QPushButton *chiudi=new QPushButton("Chiudi");
    mainLayout->addWidget(chiudi);
    connect(chiudi, &QPushButton::clicked, [this]{moreInfo=0; moreInfoPage->close();});
    chiudi->setFixedWidth(100);

    mainLayout->setSizeConstraint(QVBoxLayout::SetFixedSize);
    moreInfoPage->setStyleSheet("QLabel{ font-size: 10pt;}");
    moreInfoPage->show();
}


