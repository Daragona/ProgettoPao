#include "monopattino.h"
#include "veicolo.h"

monopattino::monopattino (string Marca_,string Modello_,double Price_, int Quantity_, bool Used_, string deck_, string collarino_, string grip_) :
    veicolo(Marca_,Modello_,Price_,Quantity_,Used_),
    deck(deck_), collarinoDiChiusura(collarino_), gripTape(grip_)
{}

string monopattino::getDeck() const{ return deck; }

string monopattino::getCollarinoDiChiusura() const{ return collarinoDiChiusura; }

string monopattino::getGripTape() const{ return gripTape; }
