#include "monopattino.h"
#include "veicolo.h"

monopattino::monopattino (const string &Marca_,const string &Modello_, const double &Price_, const int &Quantity_, const bool &Used_, const string& deck_, const string &collarino_, const string &grip_) :
    veicolo(Marca_,Modello_,Price_,Quantity_,Used_),
    deck(deck_), collarinoDiChiusura(collarino_), gripTape(grip_)
{}

string monopattino::getDeck() const{ return deck; }

string monopattino::getCollarinoDiChiusura() const{ return collarinoDiChiusura; }

string monopattino::getGripTape() const{ return gripTape; }

bool monopattino::operator==(veicolo& compare) const{
    const monopattino* compareCast=dynamic_cast<const monopattino*>(&compare);
    if(!compareCast) return false;
    return deck==compareCast->deck && collarinoDiChiusura==compareCast->collarinoDiChiusura && gripTape==compareCast->gripTape && veicolo::operator==(compare);
}
