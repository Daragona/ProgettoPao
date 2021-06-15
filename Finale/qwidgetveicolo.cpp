#include "qwidgetveicolo.h"
#include <QFrame>
#include <QFormLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

qwidgetveicolo::qwidgetveicolo(deepPtr<veicolo>& toInsert, QString path, view *parent, Controller *c, QString Tipo) :
    QWidget(dynamic_cast<QWidget*>(parent)), ptrVeicolo(toInsert), ctrl(c),vista(parent){
    QVBoxLayout* itemLayout= new QVBoxLayout;//Layout centrale del programma
    QFrame *itemFrame=new QFrame;
    QLabel *imageLabel = new QLabel;
    imageLabel->setFixedSize(70,70);

    QImage image=(new QImage(path))->scaled(imageLabel->width(),imageLabel->height());

    imageLabel->setPixmap(QPixmap::fromImage(image));
    imageLabel->setStyleSheet(" border:1px solid black");

    QLabel* marcaItem = new QLabel;
    marcaItem->setText(QString::fromStdString(ptrVeicolo->getMarca()));

    QLabel* modelloItem = new QLabel;
    modelloItem->setText(QString::fromStdString(ptrVeicolo->getModello()));

    QLabel* tipoItem = new QLabel;
    tipoItem-> setText(Tipo);
    QLabel* prezzoItem = new QLabel;
    prezzoItem-> setText(QString::number(ptrVeicolo->getPrezzo())+"€");

    QPushButton *deleteButton = new QPushButton("&Delete");
    deleteButton->setFixedWidth(70);
    QPushButton *moreInfoButton = new QPushButton("&More info");
    moreInfoButton->setFixedWidth(70);
    connect(deleteButton, &QPushButton::released, this, &qwidgetveicolo::deleteSlot);
    connect(moreInfoButton, &QPushButton::released, this, &qwidgetveicolo::moreInfoSlot);

    itemLayout->addWidget(tipoItem);
    QHBoxLayout *riga2L=new QHBoxLayout;

    QVBoxLayout *contenutoL=new QVBoxLayout();

    QHBoxLayout *riga1CL=new QHBoxLayout;
    riga1CL->addWidget(marcaItem);
    riga1CL->addWidget(modelloItem);

    contenutoL->addLayout(riga1CL);
    contenutoL->addWidget(prezzoItem);

    QVBoxLayout *bottoniLayout=new QVBoxLayout;
    bottoniLayout->addWidget(deleteButton);
    bottoniLayout->addWidget(moreInfoButton);


    riga2L->addWidget(imageLabel);
    riga2L->addLayout(contenutoL);
    riga2L->addLayout(bottoniLayout);


    itemLayout->addLayout(riga2L);


    itemFrame->setLayout(itemLayout);

    QVBoxLayout *layoutFinale=new QVBoxLayout;
    layoutFinale->addWidget(itemFrame);

    this->setLayout(layoutFinale);
    this->setFixedHeight(140);
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
    Container<string>::Const_Iteratore I;
    Container<string>::Const_Iteratore fine;
    for(I=values.inizioc(); I!=fine; I++){
        QLabel *label=new QLabel(QString::fromStdString(*I));
        boxLayout->addWidget(label);
    }
    QLabel *label =new QLabel("Tassazione: "+QString::number(ptrVeicolo->calcolaTax())+"€");
    boxLayout->addWidget(label);

    QPushButton *chiudi=new QPushButton("Chiudi");
    mainLayout->addWidget(chiudi);
    connect(chiudi, &QPushButton::clicked, [this]{moreInfo=0; moreInfoPage->close();});
    chiudi->setFixedWidth(100);

    mainLayout->setSizeConstraint(QVBoxLayout::SetFixedSize);
    moreInfoPage->setStyleSheet("QLabel{ font-size: 10pt;}");
    moreInfoPage->show();
}


