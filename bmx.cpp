#include "bmx.h"

bmx::bmx(bool pad_):Pad(pad_){

}

bool bmx::hasPad(){
    return Pad;
}

double bmx::calcolaTax()const{
    return Price*0.90;
}

