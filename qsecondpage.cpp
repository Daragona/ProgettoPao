#include "qsecondpage.h"

QSecondPage::QSecondPage()
{

    //this->setWindowFlags ( Qt::CustomizeWindowHint | Qt::WindowTitleHint); //
    QVBoxLayout *insertDialogLayout = new QVBoxLayout;
    insertDialogLayout->setSizeConstraint(QVBoxLayout::SetFixedSize);
    this->setLayout(insertDialogLayout);

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

    connect(eBikeButton, &QPushButton::clicked, [this]{createFinalInsert(0);  });
    connect(BMXButton, &QPushButton::clicked, [this]{createFinalInsert(1);  });
    connect(mountainBikeButton, &QPushButton::clicked, [this]{createFinalInsert(2);  });
    connect(monopattinoElettricoButton, &QPushButton::clicked, [this]{createFinalInsert(3);  });


    groupBox->setLayout(groupLayout);
    insertDialogLayout->addWidget(groupBox);

    QPushButton *abort = new QPushButton("Annulla", this);
    insertDialogLayout->addWidget(abort);
    connect(abort, &QPushButton::clicked, [this]{
        close();
    });
};

void QSecondPage::createFinalInsert(int x){
    qfinalinsert *wdg=new qfinalinsert(x);

    wdg->show();
}
