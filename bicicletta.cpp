#include "bicicletta.h"

bicicletta::bicicletta(string Sella_, string Corona_, double diamRuote_, string Marca_,string Modello_, string Telaio_, string Manubrio_,double Price_, int Quantity_, bool Used_):
    veicolo(Marca_,Modello_, Telaio_, Manubrio_,Price_, Quantity_, Used_),
    Sella(Sella_),Corona(Corona_),diamRuote(diamRuote_>0? diamRuote_ : 0)
    {}



string bicicletta::getSella() const{
    return Sella;
}

string bicicletta::getCorona() const {
    return Corona;
}

double bicicletta::getDiamRuote() const{
    return diamRuote;
}

