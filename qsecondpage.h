#ifndef QSECONDPAGE_H
#define QSECONDPAGE_H

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
#include "view.h"
#include "qfinalinsert.h"

class Controller;

class QSecondPage: public QWidget
{
    Q_OBJECT
private:
    Controller *ctrl;
public:
    QSecondPage(class Controller*);



private slots:
    void createFinalInsert(int);
};

#endif // QSECONDPAGE_H
