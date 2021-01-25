#include "view.h"

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
void view::showInsertDialog()
{
    QDialog *wdg = new QDialog;
    //wdg->setWindowFlags ( Qt::CustomizeWindowHint | Qt::WindowTitleHint); //
    view::setDisabled(1);
    QVBoxLayout *insertDialogLayout = new QVBoxLayout;
    insertDialogLayout->setSizeConstraint(QVBoxLayout::SetFixedSize);
    wdg->setLayout(insertDialogLayout);

    QLabel* selectTypeLabel = new QLabel("<H3>Scegli il tipo di mezzo che si vuole registrare:</H3>");
    insertDialogLayout->addWidget(selectTypeLabel);

    QGroupBox *groupBox=new QGroupBox;
    QVBoxLayout *groupLayout = new QVBoxLayout;
    groupLayout->setAlignment(Qt::AlignCenter);

    QPushButton *eBikeButton = new QPushButton("e-Bike", this);
    QPushButton *BMXButton = new QPushButton("BMX", this);
    QPushButton *mountainBikeButton = new QPushButton("Mountain-Bike", this);
    QPushButton *monopattinoElettricoButton = new QPushButton("Monopattino Elettrico", this);

    eBikeButton->setFixedSize(200,50);
    BMXButton->setFixedSize(200,50);
    mountainBikeButton->setFixedSize(200,50);
    monopattinoElettricoButton->setFixedSize(200,50);

    groupLayout->addWidget(eBikeButton);
    groupLayout->addWidget(BMXButton);
    groupLayout->addWidget(mountainBikeButton);
    groupLayout->addWidget(monopattinoElettricoButton);
    groupLayout->addStretch(5);

    connect(eBikeButton, &QPushButton::clicked, [this]{view::showFinalInsert(0);  });
    connect(BMXButton, &QPushButton::clicked, [this]{view::showFinalInsert(1);  });
    connect(mountainBikeButton, &QPushButton::clicked, [this]{view::showFinalInsert(2);  });
    connect(monopattinoElettricoButton, &QPushButton::clicked, [this]{view::showFinalInsert(3);  });


    groupBox->setLayout(groupLayout);
    insertDialogLayout->addWidget(groupBox);



    QPushButton *abort = new QPushButton("Annulla", this);
    insertDialogLayout->addWidget(abort);
    connect(abort, &QPushButton::clicked, [this](){
        view::setDisabled(0);
        //Dovrebbe chiudere la finestra, ma non riesco :p
    });

    wdg->show();


     //Qui sotto un alternativa ma non so come implementare il pulsante next

     /*QDialog* insertDialog = new QDialog(this);

     QVBoxLayout* insertDialogLayout = new QVBoxLayout();

     QLabel* inserimentoMezzo = new QLabel;
     inserimentoMezzo-> setText("Inserimento mezzo");

     insertDialogLayout->addWidget(inserimentoMezzo);

     QRadioButton *eBikeButton = new QRadioButton("e-Bike", this);
     QRadioButton *monopattinoElettricoButton = new QRadioButton("Monopattino Elettrico", this);
     QRadioButton *BMXButton = new QRadioButton("BMX", this);
     QRadioButton *mountainBikeButton = new QRadioButton("Mountain-Bike", this);

     insertDialogLayout->addWidget(eBikeButton);
     insertDialogLayout->addWidget(monopattinoElettricoButton);
     insertDialogLayout->addWidget(BMXButton);
     insertDialogLayout->addWidget(mountainBikeButton);



     insertDialog->setModal(true);
     insertDialog->setLayout(insertDialogLayout);

     insertDialog->resize(500,200);
     insertDialog->show();*/

}



void view::showFinalInsert(int x){
    QWidget *widget = new QWidget();
    QString tipo;
    if(x==0)            tipo="E-Bike";
    else if (x==1)      tipo="BMX";
    else if(x==2)       tipo="Mountain-Bike";
    else if(x==3)       tipo="Monopattino Elettrico";

    widget->setWindowTitle(tipo);
    QVBoxLayout *mainVertical= new QVBoxLayout (widget);

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
            QLineEdit *Watt=new QLineEdit();
            QLineEdit *Ampere=new QLineEdit();
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
        QLineEdit *Watt=new QLineEdit();
        QLineEdit *Ampere=new QLineEdit();

        specificLayout->addRow(tr("&Deck:"), Deck);
        specificLayout->addRow(tr("&Collarino:"), Collarino);
        specificLayout->addRow(tr("&Tessuto Grup(?):"), gripTape);

        specificLayout->addRow(tr("&Watt:"), Watt);
        specificLayout->addRow(tr("&Ampere:"), Ampere);

    }

    QCheckBox *Used=new QCheckBox();
    specificLayout->addRow(tr("&Usato:"), Used);

    /*
     //All'interno di Informazioni Generali:
    QVBoxLayout *generalLayout=new QVBoxLayout(generalInfo);

    //Campi Marca e Modello:
        QWidget *marcaModelloW = new QWidget(generalInfo);
        generalLayout->addWidget(marcaModelloW);

        QLineEdit *Marca=new QLineEdit(marcaModelloW);
        QLineEdit *Modello=new QLineEdit(marcaModelloW);
        QHBoxLayout *marcaModelloLayout = new QHBoxLayout(marcaModelloW);
        marcaModelloLayout->addWidget(new QLabel("Marca: "));
        marcaModelloLayout->addWidget(Marca);
        marcaModelloLayout->addWidget(new QLabel("Modello: "));
        marcaModelloLayout->addWidget(Modello);

    //Campi telaio e manubrio
        QWidget *telaioManubrioW = new QWidget(generalInfo);
        generalLayout->addWidget(telaioManubrioW);

        QLineEdit *Telaio=new QLineEdit(telaioManubrioW);
        QLineEdit *Manubrio=new QLineEdit(telaioManubrioW);
        QHBoxLayout *telaioManubrioLayout = new QHBoxLayout(telaioManubrioW);
        telaioManubrioLayout->addWidget(new QLabel("Telaio: "));
        telaioManubrioLayout->addWidget(Telaio);
        telaioManubrioLayout->addWidget(new QLabel("Manubrio: "));
        telaioManubrioLayout->addWidget(Manubrio);

    //Campi prezzo e Quantità :
        QWidget *quantitaPrezzoW = new QWidget(generalInfo);
        generalLayout->addWidget(quantitaPrezzoW);

        QDoubleSpinBox *Prezzo= new QDoubleSpinBox();
        Prezzo->setSingleStep(10);
        Prezzo->setValue(0);
        Prezzo->setMaximum(1000000);
        QSpinBox *Quantita= new QSpinBox();
        Quantita->setSingleStep(5);
        Quantita->setValue(1);
        Quantita->setMaximum(1000000);

        QHBoxLayout *quantitaPrezzoLayout = new QHBoxLayout(quantitaPrezzoW);
        QHBoxLayout *quantita=new QHBoxLayout();
        quantitaPrezzoLayout->addLayout(quantita);
        quantita->addWidget(new QLabel("Quantità: "));
        quantita->addWidget(Quantita);
        quantita->setAlignment(Qt::AlignLeft);
        QHBoxLayout *prezzo=new QHBoxLayout();
        quantitaPrezzoLayout->addLayout(prezzo);
        prezzo->addWidget(new QLabel("Prezzo: "));
        prezzo->addWidget(Prezzo);
        prezzo->setAlignment(Qt::AlignLeft);

    //Campo Usato:
        QCheckBox* usatoW = new QCheckBox("Usato", generalInfo);
        generalLayout->addWidget(usatoW);


    //Fine informazioni generali
    //Inizio informazioni specifiche
    QGroupBox *specificInfo= new QGroupBox ("Informazioni Specifiche: ");
    mainVertical->addWidget(specificInfo);

    QVBoxLayout *specificLayout=new QVBoxLayout(specificInfo);

    if(x==0 || x==1 || x==2){
        // sella , diametro, corona
        QWidget *campiBiciW = new QWidget(specificInfo);
        specificLayout->addWidget(campiBiciW);
        QLineEdit *Sella=new QLineEdit(campiBiciW);
        QSpinBox *Diametro=new QSpinBox(campiBiciW);
        Diametro->setFixedSize(50,20);
        QLineEdit *Corona=new QLineEdit(campiBiciW);
        QHBoxLayout *campiBiciLayout = new QHBoxLayout(campiBiciW);
        campiBiciLayout->addWidget(new QLabel("Sella: "));
        campiBiciLayout->addWidget(Sella);
        campiBiciLayout->addWidget(new QLabel("Diametro (cm): "));
        campiBiciLayout->addWidget(Diametro);
        campiBiciLayout->addWidget(new QLabel("Corona: "));
        campiBiciLayout->addWidget(Corona);

        if(x==0){
            QWidget *sensoriW = new QWidget(specificInfo);
            specificLayout->addWidget(sensoriW);
            //2 sensori
            QLineEdit *sensorePedalata=new QLineEdit(sensoriW);
            QLineEdit *sensoreSforzo=new QLineEdit(sensoriW);
            QHBoxLayout *sensoriLayout = new QHBoxLayout(sensoriW);
            sensoriLayout->addWidget(new QLabel("Sensore di Pedalata : "));
            sensoriLayout->addWidget(sensorePedalata);
            sensoriLayout->addWidget(new QLabel("Sensore di Sforzo: "));
            sensoriLayout->addWidget(sensoreSforzo);
            //Ampere w Watt
            QWidget *ValoriW = new QWidget(specificInfo);
            specificLayout->addWidget(ValoriW);
            QLineEdit *Watt=new QLineEdit(sensoriW);
            QLineEdit *Ampere=new QLineEdit(sensoriW);
            QHBoxLayout *valoriLayout = new QHBoxLayout(ValoriW);
            valoriLayout->addWidget(new QLabel("Watt : "));
            valoriLayout->addWidget(Watt);
            valoriLayout->addWidget(new QLabel("Ampere: "));
            valoriLayout->addWidget(Ampere);

        }else if(x==1){
            QWidget *bmxW = new QWidget(specificInfo);
            specificLayout->addWidget(bmxW);
            QLineEdit *Pad=new QLineEdit(bmxW);
            QHBoxLayout *bmxLayout = new QHBoxLayout(bmxW);
            bmxLayout->addWidget(new QLabel("Pad: "));
            bmxLayout->addWidget(Pad);

        }else if(x==2){
            QWidget *mbW = new QWidget(specificInfo);
            specificLayout->addWidget(mbW);
            QSpinBox *numMarce=new QSpinBox(mbW);
            numMarce->setFixedSize(70,20);
            QLineEdit *Ammortizzatori=new QLineEdit(mbW);
            QHBoxLayout *mbLayout = new QHBoxLayout(mbW);
            mbLayout->addWidget(new QLabel("Numero Marce: "));
            mbLayout->addWidget(numMarce);
            mbLayout->addWidget(new QLabel("Ammortizzatori: "));
            mbLayout->addWidget(Ammortizzatori);


        }
    }


*/



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


    widget->show();






}
