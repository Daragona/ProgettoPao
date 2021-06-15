#ifndef VEICOLOELETTRICO_H
#define VEICOLOELETTRICO_H

#include "veicolo.h"

class veicoloElettrico : virtual public veicolo{
protected:
    int Watt;
    double Ampere;
    double oreAutonomia;

public:
    veicoloElettrico(const string&, const string&, const double&, const int&, const bool&,const int&,const double&);
    veicoloElettrico(int, double);
    veicoloElettrico();
    virtual ~veicoloElettrico()=default;
    virtual bool operator==(veicolo&) const override;

    int getWatt() const ;
    double getAmpere() const ;

};

#endif // VEICOLOELETTRICO_H
