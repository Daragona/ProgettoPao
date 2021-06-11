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
    bool operator==(veicolo&) const override;

    string getPedalata() const;
    string getSforzo() const;
    double calcolaTax() const override;
    Container<string> GetInfo() const override;


};

#endif // EBIKE_H
