#ifndef VEICOLOELETTRICO_H
#define VEICOLOELETTRICO_H

#include "veicolo.h"

class veicoloElettrico : public Veicolo{
private:
    int Watt;
    double ampere;
    double oreAutonomia;

public:
    veicoloElettrico();

    int getWatt() const ;
    double getAmpere() const ;
    virtual unsigned int calcolaVelocitaMax() const = 0;
};

#endif // VEICOLOELETTRICO_H
