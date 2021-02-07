#include "qwidgetveicolo.h"
#include <QFrame>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
qwidgetveicolo::qwidgetveicolo(deepPtr<veicolo> toInsert, QString path, QWidget *parent) : QWidget(parent){
    QGridLayout* itemLayout = new QGridLayout; //Layout centrale del programma
    QFrame *item=new QFrame;
    QLabel* image = new QLabel;
    image->setFixedSize(70,70);

    QImage aaa=(new QImage(path))->scaled(image->width(),image->height());
    image->setPixmap(QPixmap::fromImage(aaa));
    image->setStyleSheet(" border:1px solid black");

    QLabel* nomeItem = new QLabel;
    nomeItem->setText(QString::fromStdString(toInsert->getModello()));

    QLabel* quantitaItem = new QLabel;
    quantitaItem-> setText(QString::number(toInsert->getQuantita()));

    QPushButton *deleteButton = new QPushButton("&Delete");
    QPushButton *moreInfoButton = new QPushButton("&More info");

    itemLayout->addWidget(image,0,1,0,1);
    itemLayout->addWidget(nomeItem,0,2);
    itemLayout->addWidget(quantitaItem,0,3);
    itemLayout->addWidget(deleteButton,0,4);
    itemLayout->addWidget(moreInfoButton,1,4);

    item->setLayout(itemLayout);
    QVBoxLayout *total=new QVBoxLayout;
    total->addWidget(item);
    total->setSpacing(10);
    this->setLayout(total);
    this->setFixedHeight(110);
    this->setStyleSheet("border:1px solid black");

}
