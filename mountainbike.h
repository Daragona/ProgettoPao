    #ifndef MOUNTAINBIKE_H
#define MOUNTAINBIKE_H
#include "bicicletta.h"

class mountainbike: public bicicletta{
protected:
    int numMarce;
    string Ammortizzatori;
public:
    mountainbike(string,string,double, int, bool, string, string,string, string, double, int,string);
    mountainbike();
    int getNumMarce();
    string getAmmortizzatori();
    void GetInfo() const override;
    void chiediRicambio() override;
    double calcolaTax() override;

};

#endif // MOUNTAINBIKE_H
