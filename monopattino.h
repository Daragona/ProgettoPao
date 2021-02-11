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
    monopattino(string, string, double, int, bool, string, string, string);
    monopattino();

    // getter
    string getDeck() const ;
    string getCollarinoDiChiusura() const ;
    string getGripTape() const;
};

#endif // MONOPATTINO_H
