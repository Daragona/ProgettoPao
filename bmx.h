#ifndef BMX_H
#define BMX_H
#include "bicicletta.h"

class bmx:protected bicicletta{
protected:
    bool Pad;
public:
    bmx(bool);
    bmx();
    bool hasPad();
    double calcolaTax()const override;

};

#endif // BMX_H
