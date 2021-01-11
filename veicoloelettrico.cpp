#include "veicolo.h"
#include "veicoloelettrico.h"
#include <iostream>

veicoloElettrico::veicoloElettrico()
{

}

int veicoloElettrico::getWatt() const { return Watt; }

double veicoloElettrico::getAmpere() const { return ampere; }

