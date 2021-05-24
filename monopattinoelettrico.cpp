#include "monopattinoelettrico.h"

monopattinoElettrico::monopattinoElettrico(const string &Marca_,const string &Modello_, const double &Price_, const int &Quantity_, const bool &Used_, const string& deck_, const string &collarino_, const string &grip_, const int &Watt_, const double &Ampere_, const string &accelleratore_):
    veicolo(Marca_,Modello_,Price_,Quantity_,Used_),
    monopattino(Marca_,Modello_,Price_,Quantity_,Used_,deck_, collarino_,grip_),
    veicoloElettrico(Marca_,Modello_,Price_,Quantity_,Used_,Watt_,Ampere_),
    accelleratore(accelleratore_)
    {}

string monopattinoElettrico::getAccelleratore() const { return accelleratore; }


Container<string> monopattinoElettrico::GetInfo() const{
    Container<string> strVec;
    strVec.push_back("Marca: "+Marca);
    strVec.push_back("Modello: "+Modello);
    strVec.push_back("Prezzo: "+std::to_string(Price)+" €");
    strVec.push_back("Quantità: "+std::to_string(Quantity)+" pz");
    if(Used)    strVec.push_back("Usata: Si");
    else        strVec.push_back("Usata: No");
    strVec.push_back("Deck: "+deck);
    strVec.push_back("Collarino: "+collarinoDiChiusura);
    strVec.push_back("Grip: "+gripTape);
    strVec.push_back("Watt: "+std::to_string(Watt));
    strVec.push_back("Ampere: "+std::to_string(Ampere));
    strVec.push_back("Accelleratore: "+accelleratore);
    return strVec;
}
void monopattinoElettrico::chiediRicambio(){ }

double monopattinoElettrico::calcolaTax() {
    return Price*0.95;

}
int monopattinoElettrico::calcolaVelocitaMax() const{

}

bool monopattinoElettrico::operator==(veicolo& compare){
    const monopattinoElettrico* compareCast=dynamic_cast<const monopattinoElettrico*>(&compare);
    if(!compareCast) return false;
    return accelleratore==compareCast->accelleratore && monopattino::operator==(compare) && veicoloElettrico::operator==(compare);
}
