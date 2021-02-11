#ifndef MONOPATTINOELETTRICO_H
#define MONOPATTINOELETTRICO_H

#include "veicoloelettrico.h"
#include "monopattino.h"

class monopattinoElettrico: public monopattino, public veicoloElettrico
{
protected:
    string accelleratore;
public:
    monopattinoElettrico(string, string, double, int, bool, string, string, string, int, double, string);
    monopattinoElettrico();

    string getAccelleratore() const;
    void GetInfo() const override ;
    void chiediRicambio() override ;
    double calcolaTax() override ;
    int calcolaVelocitaMax() const override ;

};

#endif // MONOPATTINOELETTRICO_H
