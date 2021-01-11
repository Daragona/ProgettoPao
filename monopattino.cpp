#include "monopattino.h"
#include "veicolo.h"

monopattino::monopattino (string d, string c, string g) : deck(d), collarinoDiChiusura(c), gripTape(g) {}
monopattino::monopattino () {}

string monopattino::getDeck() const{ return deck; }

string monopattino::getCollarinoDiChiusura() const{ return collarinoDiChiusura; }

string monopattino::getGripTape() const{ return gripTape; }
