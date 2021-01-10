#ifndef CONTAINER_H
#define CONTAINER_H

#include "deepptr.h"

template <class T>

class Container
{
private:


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
        const deepPtr<T>* puntatore;
        constIteratore(deepPtr<T>*);
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
        deepPtr<T> * puntatore;
        Iteratore(deepPtr <T>*);
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
