#ifndef MONOPATTINOELETTRICO_H
#define MONOPATTINOELETTRICO_H

#include "veicoloelettrico.h"
#include "monopattino.h"

class monopattinoElettrico: protected monopattino, protected veicoloElettrico
{
protected:
    string accelleratore;
public:
    monopattinoElettrico(string, string, string, string, double, int, bool, string, string, string, int, double, string);
    monopattinoElettrico();

    string getAccelleratore() const;
    void GetInfo() const override ;
    void chiediRicambio() override ;
    double calcolaTax() override ;
    int calcolaVelocitaMax() const override ;

};

#endif // MONOPATTINOELETTRICO_H
