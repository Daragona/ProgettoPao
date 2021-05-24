#include "mountainbike.h"



mountainbike::mountainbike(const string &Marca_,const string &Modello_, const double &Price_, const int &Quantity_, const bool &Used_,const  string &Telaio_, const string &Manubrio_,const string &Sella_, const string &Corona_, const double &diamRuote_, const int &numMarce_,const string &Ammortizzatori_):
    veicolo(Marca_,Modello_,Price_,Quantity_,Used_),
    bicicletta(Marca_,Modello_,Price_,Quantity_,Used_,Telaio_,Manubrio_,Sella_,Corona_,diamRuote_),
    numMarce(numMarce_),Ammortizzatori(Ammortizzatori_){}

int mountainbike::getNumMarce(){
    return numMarce;
}

string mountainbike::getAmmortizzatori(){
    return Ammortizzatori;
}

Container<string> mountainbike::GetInfo() const{
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
    strVec.push_back("Marce: "+std::to_string(numMarce));
    strVec.push_back("Ammortizzatori: "+Ammortizzatori);
    return strVec;
}

void mountainbike::chiediRicambio(){

};

double mountainbike::calcolaTax(){
    return Price*0.10;
}

bool mountainbike::operator==(veicolo& compare){
    const mountainbike* compareCast=dynamic_cast<const mountainbike*>(&compare);
    if(!compareCast) return false;
    return numMarce==compareCast->numMarce && Ammortizzatori==compareCast->Ammortizzatori && bicicletta::operator==(compare);
}
