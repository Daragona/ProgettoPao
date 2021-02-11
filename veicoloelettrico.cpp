#include "veicolo.h"
#include "veicoloelettrico.h"
#include <iostream>

veicoloElettrico::veicoloElettrico(string Marca_,string Modello_,double Price_, int Quantity_, bool Used_,int Watt_, double Ampere_):
    veicolo(Marca_,Modello_,Price_, Quantity_, Used_),
    Watt(Watt_), Ampere(Ampere_)
    {}
veicoloElettrico::veicoloElettrico(int Watt_, double Ampere_):
    Watt(Watt_), Ampere(Ampere_)
    {}

int veicoloElettrico::getWatt() const { return Watt; }

double veicoloElettrico::getAmpere() const { return Ampere; }

