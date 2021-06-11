#ifndef MONOPATTINO_H
#define MONOPATTINO_H

#include <string>
#include "veicolo.h"

using std::string;

class monopattino : virtual public veicolo {
protected:
    string deck;
    string collarinoDiChiusura;
    string gripTape;
public:
    monopattino(const string&,const string&,const double&, const int&,const bool&, const string&, const string&, const string&);
    monopattino();
    virtual ~monopattino()=default;
    virtual bool operator==(veicolo&)  const override;

    // getter
    string getDeck() const ;
    string getCollarinoDiChiusura() const ;
    string getGripTape() const;
};

#endif // MONOPATTINO_H
