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
        nodo(const T&, nodo* = nullptr);
        nodo(const nodo&);
        void distruggi();
    };
    nodo* primo, *ultimo;
    static nodo* clone(nodo*, nodo*&);



public:
    Container();
    Container(const T&);
    Container(const Container&);
    ~Container();
    Container& operator=(const Container&);

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
        Iteratore(nodo*);
    public:
        Iteratore();
        Iteratore& operator=(const Iteratore&);
        Iteratore &operator++();
        Iteratore &operator++(int);
        T &operator*() const;
        T *operator->() const;
        bool operator==(const Iteratore &);
        bool operator!=(const Iteratore &);

    };
    constIteratore inizio() const;
    constIteratore fine() const;
    Iteratore inizio();
    Iteratore fine();
};

#endif // CONTAINER_H
