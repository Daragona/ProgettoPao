#ifndef MOUNTAINBIKE_H
#define MOUNTAINBIKE_H
#include "bicicletta.h"

class mountainbike: public bicicletta{
public:
    int numMarce;
    string Ammortizzatori;
public:
    mountainbike(string, string, double, string,string, string, string,double, int, bool,int,string);
    mountainbike();
    int getNumMarce();
    string getAmmortizzatori();
    void GetInfo() const;
    void chiediRicambio();
    double calcolaTax();

};

#endif // MOUNTAINBIKE_H
