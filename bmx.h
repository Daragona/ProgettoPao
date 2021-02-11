#ifndef BMX_H
#define BMX_H
#include "bicicletta.h"

class bmx: public bicicletta{
protected:
    bool Pad;
public:
    bmx(string,string,double, int, bool, string, string, string , string , double ,bool);
    bmx();
    bool hasPad();
    double calcolaTax() override;
    void GetInfo() const override;
    void chiediRicambio() override;
};

#endif // BMX_H
