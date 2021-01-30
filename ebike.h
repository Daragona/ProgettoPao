#ifndef EBIKE_H
#define EBIKE_H
#include "bicicletta.h"
#include "veicoloelettrico.h"


class ebike: protected veicoloElettrico, protected bicicletta{
protected:
    string SensorePedalata, SensoreSforzo;
public:
    ebike(string, string, double, string,string, string, string,double, int, bool, int, double, string, string);
    ebike();
    string getPedalata() const;
    string getSforzo() const;
    double calcolaTax() override;
    void GetInfo() const override;
    void chiediRicambio() override;
    int calcolaVelocitaMax() const override;

};

#endif // EBIKE_H
