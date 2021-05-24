#ifndef EBIKE_H
#define EBIKE_H
#include "bicicletta.h"
#include "veicoloelettrico.h"


class ebike: public veicoloElettrico, public bicicletta{
protected:
    string SensorePedalata, SensoreSforzo;
public:
    ebike(const string&,const string&,const double&, const int&, const bool&, const string&, const string&, const string&, const string&, const double&, const int&, const double&, const string&, const string&);
    ebike();
    bool operator==(veicolo&) override;

    string getPedalata() const;
    string getSforzo() const;
    double calcolaTax() override;
    Container<string> GetInfo() const override;
    void chiediRicambio() override;
    int calcolaVelocitaMax() const override;


};

#endif // EBIKE_H
