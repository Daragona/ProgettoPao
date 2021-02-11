#include "veicolo.h"
veicolo::veicolo(string Marca_,string Modello_,double Price_, int Quantity_, bool Used_)
    :Marca(Marca_), Modello(Modello_), Price(Price_>0 ? Price_: 0), Quantity(Quantity_>=0? Quantity_ : 0),Used(Used_){
}
veicolo::veicolo(){

}
void veicolo::changeQuantity(int NewQ){
    if(NewQ>=0){
        Quantity=NewQ;
    }
}
void veicolo::changePrice(double NewP){
    if(NewP>0){
        Price=NewP;
    }
}

string veicolo::getModello() const{
    return Modello;
}
string veicolo::getMarca() const{
    return Marca;
}
int veicolo::getQuantita() const{
    return Quantity;
}
double veicolo::getPrezzo() const{
    return Price;
}


bool veicolo::operator==(veicolo& compare)
{
    return Marca==compare.Marca && Modello==compare.Modello;
}

//veicolo::veicolo(){

//}
