    #ifndef MOUNTAINBIKE_H
#define MOUNTAINBIKE_H
#include "bicicletta.h"

class mountainbike: public bicicletta{
protected:
    int numMarce;
    string Ammortizzatori;
public:
    mountainbike(const string&,const string&,const double&,const int&,const bool&,const string&,const string&, const string&,const string&,const double&,const int&,const string&);
    mountainbike();
    bool operator==(veicolo&) override;

    int getNumMarce();
    string getAmmortizzatori();
    Container<string> GetInfo() const override;
    void chiediRicambio() override;
    double calcolaTax() override;

};

#endif // MOUNTAINBIKE_H
