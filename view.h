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
class view : public QWidget
{
    Q_OBJECT
private:
    QWidget InsertPage;
    void itemsList(QGridLayout* screenLayout);

    void showMoreInfo();

    void createItem(QVBoxLayout* veicoloLayout,QVBoxLayout* veicoloElettricoLayout);

public:
    explicit view(QWidget *parent = nullptr);

public slots:
    void importMezzi();
    void showInsertDialog();
};
#endif // VIEW_H
