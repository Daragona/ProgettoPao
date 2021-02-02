#ifndef VEICOLOELETTRICO_H
#define VEICOLOELETTRICO_H

#include "veicolo.h"

class veicoloElettrico : virtual public veicolo{
protected:
    int Watt;
    double Ampere;
    double oreAutonomia;

public:
    veicoloElettrico(string, string, string, string, double, int, bool,int,double);
    veicoloElettrico(int, double);
    veicoloElettrico();

    int getWatt() const ;
    double getAmpere() const ;
    virtual int calcolaVelocitaMax() const =0;

};

#endif // VEICOLOELETTRICO_H
