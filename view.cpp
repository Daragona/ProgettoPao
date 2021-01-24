#include "view.h"
#include "ui_view.h"

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

    showInsertDialog();

}

//FUNZIONI ------------------

//Body del programma

void view::itemsList(QGridLayout* screenLayout)
{
    QLabel* titoloBici = new QLabel;
    QLabel* titoloMonopattino = new QLabel;

    titoloBici->setText("BICI");
    titoloMonopattino->setText("MONOPATTINO ELETTRICO");

    // i due box che contengono uno le bici e uno i monopattini
    QVBoxLayout* biciLayout = new QVBoxLayout;
    QVBoxLayout* monopattinoLayout = new QVBoxLayout;

    QFrame* biciList = new QFrame;
    QFrame* monopattinoList = new QFrame;

    biciLayout->addWidget(titoloBici);
    monopattinoLayout->addWidget(titoloMonopattino);

    biciList->setLayout(biciLayout);
    monopattinoList->setLayout(monopattinoLayout);


    biciList->setStyleSheet("background-color:white; border:1px solid black");
    monopattinoList->setStyleSheet("background-color:white;border:1px solid black");

    screenLayout->addWidget(titoloBici,1,0);
    screenLayout->addWidget(titoloMonopattino,1,1);


    // OGGETTO ITEM

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



    biciLayout->addWidget(item);

    screenLayout->addWidget(biciList,2,0);
    screenLayout->addWidget(monopattinoList,2,1);
}

// quando clicchi sul bottone inserisci
void view::showInsertDialog()
{
    QDialog* insertDialog = new QDialog(this);

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
    insertDialog->show();

 /*   QWizardPage *page = new QWizardPage;
    page->setTitle("Introduction");

    QLabel *label = new QLabel("This wizard will help you register your copy of Super Product Two.");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    page->setLayout(layout);

    QWizardPage *page2 = new QWizardPage;
    page->setTitle("Introduction");

    label->setWordWrap(true);
    layout->addWidget(label);
    page->setLayout(layout);


     QWizard wizard;
     wizard.addPage(page);
     wizard.addPage(page2);

     wizard.show();
     */

}


