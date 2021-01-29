#ifndef BMX_H
#define BMX_H
#include "bicicletta.h"

class bmx: public bicicletta{
public:
    bool Pad;
public:
    bmx(string, string, double, string,string, string, string,double, int, bool,bool);
    bmx();
    bool hasPad();
    void GetInfo() const;
    void chiediRicambio();
    double calcolaTax();

};

#endif // BMX_H
