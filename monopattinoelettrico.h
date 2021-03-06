#ifndef MONOPATTINOELETTRICO_H
#define MONOPATTINOELETTRICO_H

#include "veicoloelettrico.h"
#include "monopattino.h"

class monopattinoElettrico: public monopattino, public veicoloElettrico
{
protected:
    string accelleratore;
public:
    monopattinoElettrico(const string&, const string&, const double&,const  int&, const bool&, const string&, const string&, const string&, const int&, const double&, const string&);
    monopattinoElettrico();
    bool operator==(veicolo&) const override;

    string getAccelleratore() const;
    Container<string> GetInfo() const override ;
    Container<string> GetInfoExport() const override;
    double calcolaTax() const override ;

};

#endif // MONOPATTINOELETTRICO_H
