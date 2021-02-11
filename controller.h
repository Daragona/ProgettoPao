#ifndef CONTROLLER_H
#define CONTROLLER_H


#include <QObject>
#include "view.h"
#include "model.h"

class Controller : public QObject
{
    Q_OBJECT
private:
    view* viewMezzi;
    Model* model;
    void showMezzi();

public:
    explicit Controller(QObject *parent = nullptr);
    void setModel(Model* m);
    void setView(view* v);
    void deleteVeicolo(deepPtr<veicolo>);
public slots:
    void importaMezziController();
    void createVeicolo(QStringList*);
};

#endif // CONTROLLER_H
