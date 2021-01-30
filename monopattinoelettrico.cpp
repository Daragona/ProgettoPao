#include "monopattinoelettrico.h"

monopattinoElettrico::monopattinoElettrico(string Marca_,string Modello_, string Telaio_, string Manubrio_,double Price_, int Quantity_, bool Used_, string deck_, string collarino_, string grip_, int Watt_, double Ampere_, string accelleratore_):

    veicolo(Marca_,Modello_,Telaio_,Manubrio_,Price_,Quantity_,Used_),
    monopattino(Marca_,Modello_,Telaio_,Manubrio_,Price_,Quantity_,Used_,deck_, collarino_,grip_),
    veicoloElettrico(Marca_,Modello_,Telaio_,Manubrio_,Price_,Quantity_,Used_,Watt_,Ampere_),
    accelleratore(accelleratore_)
    {}

string monopattinoElettrico::getAccelleratore() const { return accelleratore; }


void monopattinoElettrico::GetInfo() const{

}
void monopattinoElettrico::chiediRicambio(){ }

double monopattinoElettrico::calcolaTax() {
    return Price*0.95;

}
int monopattinoElettrico::calcolaVelocitaMax() const{
}

