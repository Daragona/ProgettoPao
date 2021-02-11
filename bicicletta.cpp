#include "bicicletta.h"

bicicletta::bicicletta(string Marca_,string Modello_,double Price_, int Quantity_, bool Used_, string Telaio_, string Manubrio_,string Sella_, string Corona_, double diamRuote_):
    veicolo(Marca_,Modello_,Price_, Quantity_, Used_),
    Telaio(Telaio_),Manubrio(Manubrio_),Sella(Sella_),Corona(Corona_),diamRuote(diamRuote_)
    {}

bicicletta::bicicletta(string Sella_, string Corona_, double diamRuote_):
    Sella(Sella_), Corona(Corona_), diamRuote(diamRuote_)
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

