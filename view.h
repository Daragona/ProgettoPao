#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QMenuBar>
#include <QMenu>
#include <QPushButton>
#include <QGridLayout>
#include <QDialog>
#include <QWizard>
#include <QRadioButton>
#include <QWizardPage>
#include <QGroupBox>
#include <QButtonGroup>
#include <QLineEdit>
#include <QCheckBox>
#include <QDoubleValidator>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QString>
#include <QFormLayout>
#include <QScrollArea>

#include <deepptr.h>
#include <veicolo.h>

class Controller;       //dichiarazione incompleta per evitare dipendenza
class QSecondPage;

class view : public QWidget
{
    Q_OBJECT
private:
    QSecondPage *wdg=nullptr;
    Controller *ctrl;

    QPushButton *Usato;
    QPushButton *Importa;
    QPushButton *Inserisci;

    QWidget InsertPage;
    void itemsList(QGridLayout* screenLayout);
    QScrollArea* veicoloList;
    QScrollArea* veicoloElettricoList;


public:
    Controller* getCtrl();
    explicit view(QWidget *parent = nullptr);
    void setController(Controller* c);
    void showInsertDialog();
    void showMezzi(deepPtr<veicolo>, QString, QString=nullptr);

    // non ancora implementato perchè non so come fare, serve quando viene inserito un modello già presente, dovrebbe aggiornare la quantità senza inserire un nuovo campo
    void updateMezzi(QString modello,int Quantita);

};
#endif // VIEW_H
