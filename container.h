#ifndef CONTAINER_H
#define CONTAINER_H

#include "deepptr.h"

template <class T>

class Container
{
private:
    class nodo {
        friend class Container<T>;
    private:
        T info;
        nodo* next;
        nodo(const T& t, nodo* p = nullptr) : info(t), next(p){};
        //nodo(const nodo&);
        //void distruggi();
    };
    nodo* primo, *ultimo;
    static nodo* clone(nodo*, nodo*&);



public:
//    Container();
//    Container(const T&);
//    Container(const Container&);
//    ~Container();
    Container& operator=(const Container&);

    void push_back(T p)
    {
      if(ultimo){
          ultimo->next = new nodo(p, nullptr);
          ultimo = ultimo->next;
      }
      else{
          primo=ultimo=new nodo(p);
      }
    }

    class constIteratore
    {
        friend class Container<T>;
    private:
        const nodo* puntatore;
        bool past_the_end;
        constIteratore(nodo*, bool pte=0);
    public:
        constIteratore();
        constIteratore& operator=(const constIteratore&);
        constIteratore& operator++();
        constIteratore& operator++(int);
        const T& operator*() const;
        const T* operator->() const;
        bool operator==(const constIteratore&);
        bool operator!=(const constIteratore&);
    };


    class Iteratore{
        friend Container<T>;
    private:
        nodo * puntatore;
        bool past_the_end;
        Iteratore(nodo * p) : puntatore(p) {}
    public:

        Iteratore() : puntatore(nullptr) {}

//        typename Iteratore inizio()
//        {
//            return Iteratore(primo);
//        }


//        typename Container<T>::Iteratore Container<T>::fine()
//        {
//            return Iteratore(ultimo);
//        }


//        Container<T>::Iteratore::Iteratore() : puntatore(nullptr) {}


//        typename Container<T>::Iteratore & Container<T>::Iteratore::operator=(const Iteratore & it)
//        {
//            puntatore=it.puntatore;
//            return *this;
//        }


//        typename Container<T>::Iteratore& Container<T>::Iteratore::operator++()
//        {
//            if(puntatore!= nullptr){
//                if(!past_the_end){
//                    if(puntatore->next != nullptr) {puntatore = puntatore->next;}
//                 else { puntatore = puntatore+1; past_the_end = true; }
//                 }
//            }
//            return *this;

//        }

//        typename Container<T>::Iteratore& Container<T>::Iteratore::operator++(int)
//        {
//            constIteratore aux(*this);
//                if(puntatore!= nullptr) {
//                    if(!past_the_end) {
//                        if(puntatore->next != nullptr) puntatore = puntatore->next;
//                        else {puntatore = puntatore+1; past_the_end = true;}
//                    }
//                }
//                return aux;

//        }


//        T & Container<T>::Iteratore::operator*() const
//        {
//            return puntatore->info;
//        }


//        T * Container<T>::Iteratore::operator->() const
//        {
//            return &(puntatore->info);
//        }


//        bool Container<T>::Iteratore::operator==(const Iteratore& it)
//        {
//            return puntatore == it.puntatore;
//        }


//        bool Container<T>::Iteratore::operator!=(const Iteratore& it)
//        {
//            return puntatore != it.puntatore;
//        }

    };
    constIteratore inizio() const;
    constIteratore fine() const;
    Iteratore inizio();
    Iteratore fine();
};

#endif // CONTAINER_H
