#ifndef QFINALINSERT_H
#define QFINALINSERT_H


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
#include <QListWidget>
#include "view.h"
#include "container.h"
#include "deepptr.h"

class Controller;
class qfinalinsert : public QWidget
{
    Q_OBJECT
private:
    QString tipo;
    //QLineEdit *Marca, *Modello, *Telaio, *Manubrio;
    //QCheckBox *Used;
    //QDoubleSpinBox *Prezzo;
    //QSpinBox *Quantita;
    QList<QWidget*> *extra;
    Container<deepPtr<QObject>> *Valori;
    Controller *ctrl;
public:
    explicit qfinalinsert(class Controller*,int=1);
private slots:
    void confirm();
    void back();
};

#endif // QFINALINSERT_H
