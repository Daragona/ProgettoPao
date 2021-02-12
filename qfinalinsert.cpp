#include "controller.h"
#include "qfinalinsert.h"

qfinalinsert::qfinalinsert(Controller *c, int x){
    ctrl=c;
    //this->setWindowFlags ( Qt::CustomizeWindowHint | Qt::WindowTitleHint); //
    this->setWindowTitle(tipo);

    if(x==0)            tipo="E-Bike";
    else if (x==1)      tipo="BMX";
    else if(x==2)       tipo="Mountain-Bike";
    else if(x==3)       tipo="Monopattino Elettrico";

    QVBoxLayout *mainVertical= new QVBoxLayout ();
    this->setLayout(mainVertical);
    mainVertical->setSizeConstraint(QVBoxLayout::SetFixedSize);


    QString titleString="<h4>"+tipo+"</h4>";
    QLabel *Title= new QLabel(titleString);
    mainVertical->addWidget(Title);

    QGroupBox *generalInfo= new QGroupBox ("Informazioni Generali: ");
    mainVertical->addWidget(generalInfo);
    //Informazioni Generali
    QFormLayout  *generalLayout=new QFormLayout (generalInfo);

    extra=new QList<QWidget*>;
    QList<QWidget*>::iterator I;

    extra->push_back(new QLineEdit("Marca"));
    extra->push_back(new QLineEdit("Modello"));
    extra->push_back(new QDoubleSpinBox());
    extra->push_back(new QSpinBox());
    extra->push_back(new QCheckBox());

    I=extra->begin();

    generalLayout->addRow(tr("&Marca:"), (*I++));
    generalLayout->addRow(tr("&Modello:"), (*I++));
    (dynamic_cast<QDoubleSpinBox*>(*I))->setSingleStep(10);
    (dynamic_cast<QDoubleSpinBox*>(*I))->setMaximum(100000);
    generalLayout->addRow(tr("&Prezzo:"), (*I++));
    (dynamic_cast<QSpinBox*>(*I))->setSingleStep(5);
    (dynamic_cast<QSpinBox*>(*I))->setMinimum(1);
    (dynamic_cast<QSpinBox*>(*I))->setMaximum(100000);
    generalLayout->addRow(tr("&Quantità:"), (*I++));
    generalLayout->addRow(tr("&Usato:"), (*I++));

    //Informazioni specifiche
    QGroupBox *specificInfo= new QGroupBox ("Informazioni Specifiche: ");
    mainVertical->addWidget(specificInfo);
    QFormLayout  *specificLayout=new QFormLayout (specificInfo);

    if(x==0 || x==1 || x==2){

        extra->push_back(new QLineEdit("Telaio"));
        extra->push_back(new QLineEdit("Manubrio"));
        extra->push_back(new QLineEdit("Sella"));
        extra->push_back(new QLineEdit("Corona"));
        extra->push_back(new QDoubleSpinBox());
        I=extra->begin();*I++;*I++;*I++;*I++;*I++;

        specificLayout->addRow(tr("&Telaio:"), (*I++));
        specificLayout->addRow(tr("&Manubrio:"), (*I++));
        specificLayout->addRow(tr("&Sella:"), (*I++));
        specificLayout->addRow(tr("&Corona:"), (*I++));
        specificLayout->addRow(tr("&Diametro:"), (*I++));
        //(*I)->setFixedSize(50,20);

        if(x==0){
            //2 sensori, watt e ampere
            extra->push_back(new QSpinBox());
            extra->push_back(new QDoubleSpinBox());
            extra->push_back(new QLineEdit("Pedalata"));
            extra->push_back(new QLineEdit("Sforzo"));

            specificLayout->addRow(tr("&Watt:"), (*I++));
            specificLayout->addRow(tr("&Ampere:"), (*I++));
            specificLayout->addRow(tr("&Sensore Pedalata:"), (*I++));
            specificLayout->addRow(tr("&Sensore Sforzo:"), (*I++));
        }else if(x==1){
            extra->push_back(new QCheckBox());
            specificLayout->addRow(tr("&Pad:"), (*I++));

        }else if(x==2){
            extra->push_back(new QSpinBox());
            extra->push_back(new QLineEdit("Ammortizzatori"));

            specificLayout->addRow(tr("&Num Marce:"), (*I++));
            specificLayout->addRow(tr("&Ammortizzatori:"), (*I++));
        }
    }else{
        //Deck Collarino gripTape Watt Ampere
        extra->push_back(new QLineEdit("Deck"));
        extra->push_back(new QLineEdit("Collarino"));
        extra->push_back(new QLineEdit("Grip"));
        extra->push_back(new QSpinBox());
        extra->push_back(new QDoubleSpinBox());
        extra->push_back(new QLineEdit("Accelleratore"));
        I=extra->begin();*I++;*I++;*I++;*I++;*I++;

        specificLayout->addRow(tr("&Deck:"), (*I++));
        specificLayout->addRow(tr("&Collarino:"), (*I++));
        specificLayout->addRow(tr("&Tessuto Grup(?):"), (*I++));
        specificLayout->addRow(tr("&Watt:"), (*I++));
        specificLayout->addRow(tr("&Ampere:"), (*I++));
        specificLayout->addRow(tr("&Accelleratore:"), (*I++));

    }

    QPushButton *fileB=new QPushButton("Select Image");
    connect(fileB, &QPushButton::clicked, [this]{
        Path=this->pickfile();
    });
    specificLayout->addRow("Immagine:", fileB);

    QPushButton *back=new QPushButton("Indietro");
    QPushButton *abort=new QPushButton("Annulla");
    QPushButton *confirm=new QPushButton("Conferma");

    back->setFixedSize(80,25);
    abort->setFixedSize(80,25);
    confirm->setFixedSize(80,25);

    QHBoxLayout *buttonsLayout=new QHBoxLayout();
    buttonsLayout->addWidget(back);
    buttonsLayout->addWidget(abort);
    buttonsLayout->addWidget(confirm);
    mainVertical->addLayout(buttonsLayout);


    connect(back, &QPushButton::clicked, [this]{ this->back(); });
    connect(abort, &QPushButton::clicked, [this]{ this->close(); });
    connect(confirm, &QPushButton::clicked, [this]{ this->confirm(); });

}

void qfinalinsert::confirm(){
    QList<QWidget*>::iterator I;

    QStringList *StringaLista=new QStringList;
    StringaLista->append(tipo);
    for(I=extra->begin();I!=extra->end();I++){
        if(dynamic_cast<QLineEdit*>(*I))            StringaLista->append((dynamic_cast<QLineEdit*>(*I))->text());
        else if(dynamic_cast<QDoubleSpinBox*>(*I))  StringaLista->append(QString::number((dynamic_cast<QDoubleSpinBox*>(*I))->value()));
        else if(dynamic_cast<QSpinBox*>(*I))        StringaLista->append((dynamic_cast<QSpinBox*>(*I))->text());
        else if(dynamic_cast<QCheckBox*>(*I))       StringaLista->append(QString::number((dynamic_cast<QCheckBox*>(*I))->isChecked()));
     }
    StringaLista->append(Path);
    ctrl->createVeicolo(StringaLista);
    this->close();
}
void qfinalinsert::back(){
    QSecondPage *Choice=new QSecondPage(ctrl);
    Choice->show();
    this->close();
}

QString qfinalinsert::pickfile(){
    QString fileName = QFileDialog::getOpenFileName(this,
           tr("Seleziona foto"), "",
           tr("*.png;*.jpeg;*.gif ;;All Files (*)"));
    return fileName;
}
