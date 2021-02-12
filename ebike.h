#ifndef EBIKE_H
#define EBIKE_H
#include "bicicletta.h"
#include "veicoloelettrico.h"


class ebike: public veicoloElettrico, public bicicletta{
protected:
    string SensorePedalata, SensoreSforzo;
public:
    ebike(string,string,double, int, bool, string, string, string, string, double, int, double, string, string);
    ebike();
    string getPedalata() const;
    string getSforzo() const;
    double calcolaTax() override;
    Container<string> GetInfo() const override;
    void chiediRicambio() override;
    int calcolaVelocitaMax() const override;

};

#endif // EBIKE_H
