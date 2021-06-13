#include "ebike.h"

ebike::ebike(const string &Marca_,const string &Modello_, const double &Price_, const int &Quantity_, const bool &Used_,const  string &Telaio_, const string &Manubrio_,const string &Sella_, const string &Corona_, const double &diamRuote_,const int &Watt_, const double &Ampere_, const string &Pedalata_, const string &Sforzo_):
    veicolo(Marca_,Modello_,Price_,Quantity_,Used_),
    veicoloElettrico(Marca_,Modello_,Price_,Quantity_,Used_,Watt_,Ampere_),
    bicicletta(Marca_,Modello_,Price_,Quantity_,Used_,Telaio_,Manubrio_,Sella_, Corona_,diamRuote_),
    SensorePedalata(Pedalata_), SensoreSforzo(Sforzo_)

{}

string ebike::getPedalata() const{
    return SensorePedalata;
}

string ebike::getSforzo() const{
    return SensoreSforzo;
}



Container<string> ebike::GetInfo() const{
    Container<string> strVec;
    strVec.push_back("\"Marca\": \""+Marca+"\"");
    strVec.push_back("\"Modello\": \""+Modello+"\"");
    strVec.push_back("\"Prezzo\": \""+std::to_string(Price)+" €\"");
    strVec.push_back("\"Quantità\": "+std::to_string(Quantity));
    if(Used)    strVec.push_back("\"Usata\": \"Si\"");
    else        strVec.push_back("\"Usata\": \"No\"");
    strVec.push_back("\"Telaio\": \""+Telaio+"\"");
    strVec.push_back("\"Manubrio\": \""+Manubrio+"\"");
    strVec.push_back("\"Sella\": \""+Sella+"\"");
    strVec.push_back("\"Corona\": \""+Corona+"\"");
    strVec.push_back("\"Diametro\": \""+std::to_string(diamRuote)+" cm\"");
    strVec.push_back("\"Watt\": "+std::to_string(Watt));
    strVec.push_back("\"Ampere\": "+std::to_string(Ampere));
    strVec.push_back("\"Sens. Pedalata\": \""+SensorePedalata+"\"");
    strVec.push_back("\"Sens. Sforzo\": \""+SensoreSforzo+"\"");
    return strVec;
}

Container<string> ebike::GetInfoExport() const{
    Container<string> strVec;
    strVec.push_back("\"Tipo\": \"ebike\"");
    strVec.push_back("\"Marca\": \""+Marca+"\"");
    strVec.push_back("\"Modello\": \""+Modello+"\"");
    strVec.push_back("\"Prezzo\": "+std::to_string(Price));
    strVec.push_back("\"Quantita\": "+std::to_string(Quantity));
    strVec.push_back("\"Usata\":" + std::to_string(Used));
    strVec.push_back("\"Telaio\": \""+Telaio+"\"");
    strVec.push_back("\"Manubrio\": \""+Manubrio+"\"");
    strVec.push_back("\"Sella\": \""+Sella+"\"");
    strVec.push_back("\"Corona\": \""+Corona+"\"");
    strVec.push_back("\"Diametro\": "+std::to_string(diamRuote));
    strVec.push_back("\"Watt\": "+std::to_string(Watt));
    strVec.push_back("\"Ampere\": "+std::to_string(Ampere));
    strVec.push_back("\"Sens. Pedalata\": \""+SensorePedalata+"\"");
    strVec.push_back("\"Sens. Sforzo\": \""+SensoreSforzo+"\"");
    return strVec;
}


double ebike::calcolaTax() const{
    return Price*0.02;

}

bool ebike::operator==(veicolo& compare)const{
    const ebike* compareCast=dynamic_cast<const ebike*>(&compare);
    if(!compareCast) return false;
    return SensorePedalata==compareCast->SensorePedalata && SensoreSforzo==compareCast->SensoreSforzo && bicicletta::operator==(compare) && veicoloElettrico::operator==(compare);
}
