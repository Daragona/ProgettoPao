#include "bmx.h"
#include "container.h"

bmx::bmx(string Marca_,string Modello_,double Price_, int Quantity_, bool Used_, string Telaio_, string Manubrio_,string Sella_, string Corona_, double diamRuote_,bool pad_):
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
