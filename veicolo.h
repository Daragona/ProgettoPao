#ifndef VEICOLO_H
#define VEICOLO_H

#include <string>
using std::string;

class veicolo{
protected:
    string Marca;
    string Modello;
    string Telaio;
    string Manubrio;
    double Price;
    int Quantity;
    bool Used;

public:
    veicolo(string,string,string,string,double,int,bool);
    veicolo();
    virtual void GetInfo() const =0;
    virtual void chiediRicambio()=0;
    virtual double calcolaTax() =0;
    virtual ~veicolo()=default;

    void changeQuantity(int);
    void changePrice(double);

    string getModello() const;
    int getQuantita() const;
    double getPrezzo() const;


};

#endif // VEICOLO_H
