#include "mountainbike.h"

mountainbike::mountainbike(){

}
mountainbike::mountainbike(int numMarce_, string Ammortizzatori_):numMarce(numMarce_>0? numMarce_ : 1), Ammortizzatori(Ammortizzatori_){}

int mountainbike::getNumMarce(){
    return numMarce;
}

string mountainbike::getAmmortizzatori(){
    return Ammortizzatori;
}

double mountainbike::calcolaTax()const{
    return Price*0.90;
}
