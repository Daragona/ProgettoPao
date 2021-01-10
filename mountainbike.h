#ifndef MOUNTAINBIKE_H
#define MOUNTAINBIKE_H
#include "bicicletta.h"

class mountainbike: protected bicicletta{
protected:
    int numMarce;
    string Ammortizzatori;
public:
    mountainbike(int, string);
    mountainbike();
    int getNumMarce();
    string getAmmortizzatori();
    double calcolaTax()const override;

};

#endif // MOUNTAINBIKE_H
