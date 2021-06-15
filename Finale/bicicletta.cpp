#include "bicicletta.h"

bicicletta::bicicletta(const string &Marca_,const string &Modello_,const double &Price_, const int &Quantity_, const bool &Used_, const string &Telaio_, const string &Manubrio_,const string &Sella_, const string &Corona_, const double &diamRuote_):
    veicolo(Marca_,Modello_,Price_, Quantity_, Used_),
    Telaio(Telaio_),Manubrio(Manubrio_),Sella(Sella_),Corona(Corona_),diamRuote(diamRuote_)
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

bool bicicletta::operator==(veicolo& compare)const{
    const bicicletta* compareCast=dynamic_cast<const bicicletta*>(&compare);
    if(!compareCast) return false;
    return Telaio==compareCast->Telaio && Manubrio==compareCast->Manubrio && Sella==compareCast->Sella && diamRuote==compareCast->diamRuote && veicolo::operator==(compare);
}
