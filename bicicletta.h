#ifndef BICICLETTA_H
#define BICICLETTA_H
#include "veicolo.h"

class bicicletta: virtual protected veicolo{
protected:
    string Sella;
    string Corona;
    double diamRuote;
public:
    bicicletta(string, string, double);
    bicicletta();
    string getSella();
    string getCorona();
    double getDiamRuote();
    double calcolaTax()const override;

};

#endif // BICICLETTA_H
