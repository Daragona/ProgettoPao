#ifndef BMX_H
#define BMX_H
#include "bicicletta.h"
#include <container.h>
class bmx: public bicicletta{
protected:
    bool Pad;
public:
    bmx(string,string,double, int, bool, string, string, string , string , double ,bool);
    bmx();
    bool hasPad();
    double calcolaTax() override;
    Container<string> GetInfo() const override;
    void chiediRicambio() override;
    virtual ~bmx()=default;

    bool operator==(bmx&);

};

#endif // BMX_H
