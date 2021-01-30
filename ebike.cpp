#include "ebike.h"

ebike::ebike(string Sella_, string Corona_, double diamRuote_, string Marca_,string Modello_, string Telaio_, string Manubrio_,double Price_, int Quantity_, bool Used_,int Watt_, double Ampere_, string Pedalata_, string Sforzo_):
    veicolo(Marca_,Modello_,Telaio_,Manubrio_,Price_,Quantity_,Used_),
    veicoloElettrico(Watt_,Ampere_),
    bicicletta(Sella_, Corona_,diamRuote_),
    SensorePedalata(Pedalata_), SensoreSforzo(Sforzo_)

{}

string ebike::getPedalata() const{
    return SensorePedalata;
}

string ebike::getSforzo() const{
    return SensoreSforzo;
}

int ebike::calcolaVelocitaMax() const{
    return 1;
}

void ebike::GetInfo() const{

}
void ebike::chiediRicambio(){

}

double ebike::calcolaTax() {
    return Price*0.02;

}
