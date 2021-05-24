#ifndef BICICLETTA_H
#define BICICLETTA_H
#include "veicolo.h"

class bicicletta:  virtual public veicolo{
protected:
    string Telaio;
    string Manubrio;
    string Sella;
    string Corona;
    double diamRuote;
public:
    bicicletta(const string&, const string&, const double&,const int&, const bool&,const string&, const string& , const string&,const string&,const double&);
    bicicletta();
    string getSella() const;
    string getCorona() const ;
    double getDiamRuote() const;
    virtual ~bicicletta()=default;

    virtual bool operator==(veicolo&) override;

};

#endif // BICICLETTA_H
