#ifndef BMX_H
#define BMX_H
#include "bicicletta.h"
#include <container.h>
class bmx: public bicicletta{
protected:
    bool Pad;
public:
    bmx(const string&,const string&,const double&, const int&, const bool&, const string&, const string&, const string &, const string &, const double &,const bool&);
    bmx();
    bool hasPad();
    double calcolaTax() override;
    Container<string> GetInfo() const override;
    void chiediRicambio() override;

    bool operator==(veicolo&) override;

};

#endif // BMX_H
