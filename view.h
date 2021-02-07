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
#include "qwidgetveicolo.h"

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
    void showMoreInfo();
    QScrollArea* veicoloList;
    QScrollArea* veicoloElettricoList;


public:
    explicit view(QWidget *parent = nullptr);
    void setController(Controller* c);
    void showInsertDialog();
    void showMezzi(deepPtr<veicolo>, QString, QString=nullptr);

};
#endif // VIEW_H
