#include "bicicletta.h"

bicicletta::bicicletta(string Sella_, string Corona_, double diamRuote_):
    Sella(Sella_),Corona(Corona_),diamRuote(diamRuote_>0? diamRuote_ : 0){}



string bicicletta::getSella(){
    return Sella;
}

string bicicletta::getCorona(){
    return Corona;
}

double bicicletta::getDiamRuote(){
    return diamRuote;
}

