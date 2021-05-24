#include "bmx.h"
#include "container.h"

bmx::bmx(const string &Marca_,const string &Modello_, const double &Price_, const int &Quantity_, const bool &Used_,const  string &Telaio_, const string &Manubrio_,const string &Sella_, const string &Corona_, const double &diamRuote_,const bool &pad_):
    veicolo(Marca_,Modello_,Price_,Quantity_,Used_),
    bicicletta(Marca_,Modello_,Price_,Quantity_,Used_,Telaio_,Manubrio_,Sella_,Corona_,diamRuote_),
    Pad(pad_){}


bool bmx::hasPad(){
    return Pad;
}

double bmx::calcolaTax(){
    return Price*0.90;
}


Container<string> bmx::GetInfo() const{
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
    if(Pad)    strVec.push_back("Pad: Si");
    else        strVec.push_back("Pad: No");
    return strVec;
}
void bmx::chiediRicambio() {

}

bool bmx::operator==(veicolo& compare){
    const bmx* compareCast=dynamic_cast<const bmx*>(&compare);
    if(!compareCast) return false;
    return Pad==compareCast->Pad && bicicletta::operator==(compare);
}


