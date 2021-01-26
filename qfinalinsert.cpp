#include "qfinalinsert.h"

qfinalinsert::qfinalinsert(int x){
    //this->setWindowFlags ( Qt::CustomizeWindowHint | Qt::WindowTitleHint); //

    QString tipo;
    if(x==0)            tipo="E-Bike";
    else if (x==1)      tipo="BMX";
    else if(x==2)       tipo="Mountain-Bike";
    else if(x==3)       tipo="Monopattino Elettrico";

    this->setWindowTitle(tipo);
    QVBoxLayout *mainVertical= new QVBoxLayout ();
    this->setLayout(mainVertical);

    QString titleString="<h4>"+tipo+"</h4>";
    QLabel *Title= new QLabel(titleString);
    mainVertical->addWidget(Title);

    QGroupBox *generalInfo= new QGroupBox ("Informazioni Generali: ");
    mainVertical->addWidget(generalInfo);
    //Informazioni Generali
    QFormLayout  *generalLayout=new QFormLayout (generalInfo);
    QLineEdit *Marca=new QLineEdit();
    QLineEdit *Modello=new QLineEdit();
    QLineEdit *Telaio=new QLineEdit();
    QLineEdit *Manubrio=new QLineEdit();
    QDoubleSpinBox *Prezzo= new QDoubleSpinBox();
    Prezzo->setSingleStep(10);
    Prezzo->setValue(0);
    Prezzo->setMaximum(1000000);
    QSpinBox *Quantita= new QSpinBox();
    Quantita->setSingleStep(5);
    Quantita->setValue(1);
    Quantita->setMaximum(1000000);

    generalLayout->addRow(tr("&Marca:"), Marca);
    generalLayout->addRow(tr("&Modello:"), Modello);
    generalLayout->addRow(tr("&Telaio:"), Telaio);
    generalLayout->addRow(tr("&Manubrio:"), Manubrio);
    generalLayout->addRow(tr("&Prezzo:"), Prezzo);
    generalLayout->addRow(tr("&Quantità:"), Quantita);

    //Informazioni specifiche
    QGroupBox *specificInfo= new QGroupBox ("Informazioni Specifiche: ");
    mainVertical->addWidget(specificInfo);
    QFormLayout  *specificLayout=new QFormLayout (specificInfo);

    if(x==0 || x==1 || x==2){
        // sella , diametro, corona
        QLineEdit *Sella=new QLineEdit();
        QSpinBox *Diametro=new QSpinBox();
       // Diametro->setFixedSize(50,20);
        QLineEdit *Corona=new QLineEdit();

        specificLayout->addRow(tr("&Sella:"), Sella);
        specificLayout->addRow(tr("&Diametro:"), Diametro);
        specificLayout->addRow(tr("&Corona:"), Corona);

        if(x==0){
            //2 sensori, watt e ampere
            QLineEdit *sensorePedalata=new QLineEdit();
            QLineEdit *sensoreSforzo=new QLineEdit();
            QSpinBox *Watt=new QSpinBox();
            QDoubleSpinBox *Ampere=new QDoubleSpinBox();

            specificLayout->addRow(tr("&Sensore Pedalata:"), sensorePedalata);
            specificLayout->addRow(tr("&Sensore Sforzo:"), sensoreSforzo);
            specificLayout->addRow(tr("&Watt:"), Watt);
            specificLayout->addRow(tr("&Ampere:"), Ampere);
        }else if(x==1){
            QLineEdit *Pad=new QLineEdit();
            specificLayout->addRow(tr("&Pad:"), Pad);
        }else if(x==2){
            QSpinBox *numMarce=new QSpinBox();
            QLineEdit *Ammortizzatori=new QLineEdit();

            specificLayout->addRow(tr("&Num Marce:"), numMarce);
            specificLayout->addRow(tr("&Ammortizzatori:"), Ammortizzatori);
        }
    }else if(x==3){
        //Deck Collarino gripTape Watt Ampere
        QLineEdit *Deck=new QLineEdit();
        QLineEdit *Collarino=new QLineEdit();
        QLineEdit *gripTape=new QLineEdit();
        QSpinBox *Watt=new QSpinBox();
        QDoubleSpinBox *Ampere=new QDoubleSpinBox();

        specificLayout->addRow(tr("&Deck:"), Deck);
        specificLayout->addRow(tr("&Collarino:"), Collarino);
        specificLayout->addRow(tr("&Tessuto Grup(?):"), gripTape);
        specificLayout->addRow(tr("&Watt:"), Watt);
        specificLayout->addRow(tr("&Ampere:"), Ampere);

    }
    QCheckBox *Used=new QCheckBox();
    specificLayout->addRow(tr("&Usato:"), Used);

    //Bottono finali
    QHBoxLayout *buttonsLayout=new QHBoxLayout();
    mainVertical->addLayout(buttonsLayout);

    QPushButton *confirm=new QPushButton("Conferma");
    QPushButton *abort=new QPushButton("Annulla");

    confirm->setFixedSize(80,30);
    abort->setFixedSize(80,30);

    buttonsLayout->addWidget(confirm);
    buttonsLayout->addWidget(abort);
    buttonsLayout->setAlignment(Qt::AlignRight);

    connect(abort, &QPushButton::clicked, [this](){
        this->close();

    });
}
