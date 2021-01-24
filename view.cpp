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
    QWizardPage *page = new QWizardPage;
    page->setTitle("Introduction");



    QVBoxLayout *insertDialogLayout = new QVBoxLayout;

    QLabel* selectTypeLabel = new QLabel("Scegli il tipo di mezzo che vuoi inserire:");
    insertDialogLayout->addWidget(selectTypeLabel);

    QRadioButton *eBikeButton = new QRadioButton("e-Bike", this);
    QRadioButton *monopattinoElettricoButton = new QRadioButton("Monopattino Elettrico", this);
    QRadioButton *BMXButton = new QRadioButton("BMX", this);
    QRadioButton *mountainBikeButton = new QRadioButton("Mountain-Bike", this);

    insertDialogLayout->addWidget(eBikeButton);
    insertDialogLayout->addWidget(monopattinoElettricoButton);
    insertDialogLayout->addWidget(BMXButton);
    insertDialogLayout->addWidget(mountainBikeButton);

    QWizardPage *page2 = new QWizardPage;
    page->setTitle("Introduction");


    page->setLayout(insertDialogLayout);

     QWizard* wizard = new QWizard;
     wizard->addPage(page);
     wizard->addPage(page2);

     wizard->show();

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


