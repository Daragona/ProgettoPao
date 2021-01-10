#include "container.h"

template<class T>
Container<T>::constIteratore::constIteratore(deepPtr<T> * p) : puntatore(p) {}

template<class T>
Container<T>::constIteratore::constIteratore() : puntatore(nullptr) {}

template<class T>
typename Container<T>::constIteratore & Container<T>::constIteratore::operator=(const constIteratore & cit)
{
    puntatore=cit.puntatore;
    return *this;
}

template<class T>
typename Container<T>::constIteratore& Container<T>::constIteratore::operator++()
{
    if(puntatore) puntatore=puntatore->next;
    return *this;

}
template<class T>
typename Container<T>::constIteratore& Container<T>::constIteratore::operator++(int)
{
    Iteratore aux=*this;
    if(puntatore) puntatore=puntatore->next;
    return aux;

}

template<class T>
const T & Container<T>::constIteratore::operator*() const
{
    return puntatore->info;
}

template<class T>
const T * Container<T>::constIteratore::operator->() const
{
    return &(puntatore->info);
}

template<class T>
bool Container<T>::constIteratore::operator==(const constIteratore& cit)
{
    return puntatore == cit.puntatore;
}

template<class T>
bool Container<T>::constIteratore::operator!=(const constIteratore& cit)
{
    return puntatore != cit.puntatore;
}

template<class T>
Container<T>::Iteratore::Iteratore(deepPtr<T> * p) : puntatore(p) {}

template<class T>
Container<T>::Iteratore::Iteratore() : puntatore(nullptr) {}

template<class T>
typename Container<T>::Iteratore & Container<T>::Iteratore::operator=(const Iteratore & it)
{
    puntatore=it.puntatore;
    return *this;
}

template<class T>
typename Container<T>::Iteratore& Container<T>::Iteratore::operator++()
{
    if(puntatore) puntatore=puntatore->next;
    return *this;

}
template<class T>
typename Container<T>::Iteratore& Container<T>::Iteratore::operator++(int)
{
    Iteratore aux=*this;
    if(puntatore) puntatore=puntatore->next;
    return aux;

}

template<class T>
T & Container<T>::Iteratore::operator*() const
{
    return puntatore->info;
}

template<class T>
T * Container<T>::Iteratore::operator->() const
{
    return &(puntatore->info);
}

template<class T>
bool Container<T>::Iteratore::operator==(const Iteratore& it)
{
    return puntatore == it.puntatore;
}

template<class T>
bool Container<T>::Iteratore::operator!=(const Iteratore& it)
{
    return puntatore != it.puntatore;
}


