#include "ebike.h"

ebike::ebike(string Marca_,string Modello_,double Price_, int Quantity_, bool Used_, string Telaio_, string Manubrio_,string Sella_, string Corona_, double diamRuote_,int Watt_, double Ampere_, string Pedalata_, string Sforzo_):
    veicolo(Marca_,Modello_,Price_,Quantity_,Used_),
    veicoloElettrico(Marca_,Modello_,Price_,Quantity_,Used_,Watt_,Ampere_),
    bicicletta(Marca_,Modello_,Price_,Quantity_,Used_,Telaio_,Manubrio_,Sella_, Corona_,diamRuote_),
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

Container<string> ebike::GetInfo() const{
    Container<string> strVec;
    strVec.push_back("Marca: "+Marca);
    strVec.push_back("Modello: "+Modello);
    strVec.push_back("Prezzo: "+std::to_string(Price)+" €");
    strVec.push_back("Quantità: "+std::to_string(Quantity)+" pz");
    if(Used)    strVec.push_back("Usata: Si");
    else        strVec.push_back("Usata: No");
    strVec.push_back("Telaio: "+Telaio);
    strVec.push_back("Manubrio: "+Manubrio);
    strVec.push_back("Sella: "+Sella);
    strVec.push_back("Corona: "+Corona);
    strVec.push_back("Diametro: "+std::to_string(diamRuote)+" cm");
    strVec.push_back("Watt: "+std::to_string(Watt));
    strVec.push_back("Ampere: "+std::to_string(Ampere));
    strVec.push_back("Sens. Pedalata: "+SensorePedalata);
    strVec.push_back("Sens. Sforzo: "+SensoreSforzo);
    return strVec;
}

void ebike::chiediRicambio(){

}

double ebike::calcolaTax() {
    return Price*0.02;

}
