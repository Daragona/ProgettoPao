#ifndef BICICLETTA_H
#define BICICLETTA_H
#include "veicolo.h"

class bicicletta:  virtual protected veicolo{
protected:
    string Sella;
    string Corona;
    double diamRuote;
public:
    bicicletta(string, string, string, string, double, int, bool,string, string, double);
    bicicletta(string, string, double);
    bicicletta();
    string getSella() const;
    string getCorona() const ;
    double getDiamRuote() const;

};

#endif // BICICLETTA_H
