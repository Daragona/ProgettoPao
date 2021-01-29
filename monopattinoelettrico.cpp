#include "monopattinoelettrico.h"

monopattinoElettrico::monopattinoElettrico(string a): accelleratore(a){}

string monopattinoElettrico::getAccelleratore() const { return accelleratore; }

void monopattinoElettrico::GetInfo() const{

};
void monopattinoElettrico::chiediRicambio(){

};

double monopattinoElettrico::calcolaTax(){
    return Price*0.90;
}
