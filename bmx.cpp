#include "bmx.h"

bmx::bmx(string Sella_, string Corona_, double diamRuote_, string Marca_,string Modello_, string Telaio_, string Manubrio_,double Price_, int Quantity_, bool Used_,bool pad_):
    veicolo(Marca_,Modello_,Telaio_,Manubrio_,Price_,Quantity_,Used_),
    bicicletta(Marca_,Modello_,Telaio_,Manubrio_,Price_,Quantity_,Used_,Sella_,Corona_,diamRuote_),
    Pad(pad_){}


bool bmx::hasPad(){
    return Pad;
}

double bmx::calcolaTax(){
    return Price*0.90;
}


void bmx::GetInfo() const{

}
void bmx::chiediRicambio() {

}
