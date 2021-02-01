#include "mountainbike.h"


mountainbike::mountainbike
(string Sella_, string Corona_, double diamRuote_, string Marca_,string Modello_, string Telaio_, string Manubrio_,double Price_, int Quantity_, bool Used_, int numMarce_,string Ammortizzatori_):
    veicolo(Marca_,Modello_,Telaio_,Manubrio_,Price_,Quantity_,Used_),
    bicicletta(Marca_,Modello_,Telaio_,Manubrio_,Price_,Quantity_,Used_,Sella_,Corona_,diamRuote_),
    numMarce(numMarce_),Ammortizzatori(Ammortizzatori_){}

int mountainbike::getNumMarce(){
    return numMarce;
}

string mountainbike::getAmmortizzatori(){
    return Ammortizzatori;
}



void mountainbike::GetInfo() const{

};
void mountainbike::chiediRicambio(){

};

double mountainbike::calcolaTax(){
    return Price*0.10;
}
