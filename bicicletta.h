#ifndef BICICLETTA_H
#define BICICLETTA_H
#include "veicolo.h"

class bicicletta: virtual public veicolo{
public:
    string Sella;
    string Corona;
    double diamRuote;
public:
    bicicletta(string, string, double, string, string, string, string, double, int, bool);
    string getSella() const;
    string getCorona() const ;
    double getDiamRuote() const;
    virtual ~bicicletta()=default;

};

#endif // BICICLETTA_H
