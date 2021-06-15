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
    veicolo(const string&, const string&, const double&, const int&, const bool&);
    veicolo();
    virtual Container<string> GetInfo() const =0;
    virtual Container<string> GetInfoExport() const =0;
    virtual double calcolaTax()const =0;
    virtual ~veicolo()=default;
    string getModello() const;
    string getMarca() const;
    int getQuantita() const;
    double getPrezzo() const;

    void setQuantita(int);

    virtual bool operator==(veicolo&)const;
    bool operator!=(veicolo&)const;
};

#endif // VEICOLO_H
