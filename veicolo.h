#ifndef VEICOLO_H
#define VEICOLO_H

#include <string>
#include <container.h>
using std::string;

class veicolo{
protected:
    string Marca;
    string Modello;
    double Price;
    int Quantity;
    bool Used;

public:
    veicolo(string,string,double,int,bool);
    veicolo();
    virtual Container<string> GetInfo() const =0;
    virtual void chiediRicambio()=0;
    virtual double calcolaTax() =0;
    virtual ~veicolo()=default;
    string getModello() const;
    string getMarca() const;
    int getQuantita() const;
    double getPrezzo() const;

    void setQuantita(int qty);

    void changeQuantity(int);
    void changePrice(double);
    bool operator==(veicolo&);
    bool operator!=(veicolo&);
};

#endif // VEICOLO_H
