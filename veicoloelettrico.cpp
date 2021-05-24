#include "veicolo.h"
#include "veicoloelettrico.h"
#include <iostream>

veicoloElettrico::veicoloElettrico(const string &Marca_,const string &Modello_,const double &Price_, const int &Quantity_, const bool &Used_,const int &Watt_, const double &Ampere_):
    veicolo(Marca_,Modello_,Price_, Quantity_, Used_),
    Watt(Watt_), Ampere(Ampere_)
    {}
veicoloElettrico::veicoloElettrico(int Watt_, double Ampere_):
    Watt(Watt_), Ampere(Ampere_)
    {}

int veicoloElettrico::getWatt() const { return Watt; }

double veicoloElettrico::getAmpere() const { return Ampere; }

bool veicoloElettrico::operator==(veicolo& compare) {
    const veicoloElettrico* compareCast=dynamic_cast<const veicoloElettrico*>(&compare);
    if(!compareCast) return false;
    return Watt==compareCast->Watt && Ampere==compareCast->Ampere && veicolo::operator==(compare);
}
