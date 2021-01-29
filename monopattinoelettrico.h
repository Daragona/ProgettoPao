#ifndef MONOPATTINOELETTRICO_H
#define MONOPATTINOELETTRICO_H

#include "veicoloelettrico.h"
#include "monopattino.h"

class monopattinoElettrico: public monopattino, public veicoloElettrico
{
public:
    string accelleratore;
public:
    monopattinoElettrico(string a);
    string getAccelleratore() const;
    void GetInfo() const;
    void chiediRicambio();
    double calcolaTax();
};

#endif // MONOPATTINOELETTRICO_H
