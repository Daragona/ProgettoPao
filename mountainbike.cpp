#include "mountainbike.h"



mountainbike::mountainbike
(string Sella_, string Corona_, double diamRuote_, string Marca_,string Modello_, string Telaio_, string Manubrio_,double Price_, int Quantity_, bool Used_, int numMarce_,string Ammortizzatori_):

    bicicletta(Sella_,Corona_,diamRuote_,Marca_,Modello_,Telaio_,Manubrio_,Price_,Quantity_,Used_),
    numMarce(numMarce_),Ammortizzatori(Ammortizzatori_){}

int mountainbike::getNumMarce(){
    return numMarce;
}

string mountainbike::getAmmortizzatori(){
    return Ammortizzatori;
}

double mountainbike::calcolaTax(){
    return Price*0.90;
}
