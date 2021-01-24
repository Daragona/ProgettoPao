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

class view : public QWidget
{
    Q_OBJECT
private:

    void itemsList(QGridLayout* screenLayout);

public:
    explicit view(QWidget *parent = nullptr);

    void showInsertDialog();
};
#endif // VIEW_H
