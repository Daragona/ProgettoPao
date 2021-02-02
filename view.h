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

#include <qsecondpage.h>
#include <deepptr.h>

class Controller;       //dichiarazione incompleta per evitare dipendenza


class view : public QWidget
{
    Q_OBJECT
private:
    Controller *ctrl;

    QPushButton *Usato;
    QPushButton *Importa;
    QPushButton *Inserisci;

    QWidget InsertPage;
    void itemsList(QGridLayout* screenLayout);
    void showMoreInfo();
    QFrame* veicoloList;
    QFrame* veicoloElettricoList;


public:
    explicit view(QWidget *parent = nullptr);
    void setController(Controller* c);
    void showInsertDialog();
    void showMezzi(QString immagine, QString Modello, QString Quantita, QString Prezzo);

};
#endif // VIEW_H
