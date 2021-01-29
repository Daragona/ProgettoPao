//#include "container.h"

//template<class T>
//Container<T>::constIteratore::constIteratore(nodo * p, bool pte) :
//    puntatore(p),past_the_end(pte) {}

//template<class T>
//Container<T>::constIteratore::constIteratore() : puntatore(nullptr), past_the_end(false){}

//template<class T>
//typename Container<T>::constIteratore & Container<T>::constIteratore::operator=(const constIteratore & cit)
//{
//    puntatore=cit.puntatore;
//    return *this;
//}

//template<class T>
//typename Container<T>::constIteratore& Container<T>::constIteratore::operator++()
//{
//    if(puntatore!= nullptr){
//        if(!past_the_end){
//            if(puntatore->next != nullptr) {puntatore = puntatore->next;}
//         else { puntatore = puntatore+1; past_the_end = true; }
//         }
//    }
//    return *this;

//}
//template<class T>
//typename Container<T>::constIteratore& Container<T>::constIteratore::operator++(int)
//{
//    constIteratore aux(*this);
//        if(puntatore!= nullptr) {
//            if(!past_the_end) {
//                if(puntatore->next != nullptr) puntatore = puntatore->next;
//                else {puntatore = puntatore+1; past_the_end = true;}
//            }
//        }
//        return aux;
//}

//template<class T>
//const T & Container<T>::constIteratore::operator*() const
//{
//    return puntatore->info;
//}

//template<class T>
//const T * Container<T>::constIteratore::operator->() const
//{
//    return &(puntatore->info);
//}

//template<class T>
//bool Container<T>::constIteratore::operator==(const constIteratore& cit)
//{
//    return puntatore == cit.puntatore;
//}

//template<class T>
//bool Container<T>::constIteratore::operator!=(const constIteratore& cit)
//{
//    return puntatore != cit.puntatore;
//}


//template<class T>
//typename Container<T>::constIteratore Container<T>::inizio() const
//{
//    return constIteratore(primo);
//}

//template<class T>
//typename Container<T>::constIteratore Container<T>::fine() const
//{
//    return constIteratore(ultimo);
//}

//template<class T>
//typename Container<T>::Iteratore Container<T>::inizio()
//{
//    return Iteratore(primo);
//}

//template<class T>
//typename Container<T>::Iteratore Container<T>::fine()
//{
//    return Iteratore(ultimo);
//}

//template<class T>
//Container<T>::Iteratore::Iteratore(nodo * p) : puntatore(p) {}

//template<class T>
//Container<T>::Iteratore::Iteratore() : puntatore(nullptr) {}

//template<class T>
//typename Container<T>::Iteratore & Container<T>::Iteratore::operator=(const Iteratore & it)
//{
//    puntatore=it.puntatore;
//    return *this;
//}

//template<class T>
//typename Container<T>::Iteratore& Container<T>::Iteratore::operator++()
//{
//    if(puntatore!= nullptr){
//        if(!past_the_end){
//            if(puntatore->next != nullptr) {puntatore = puntatore->next;}
//         else { puntatore = puntatore+1; past_the_end = true; }
//         }
//    }
//    return *this;

//}
//template<class T>
//typename Container<T>::Iteratore& Container<T>::Iteratore::operator++(int)
//{
//    constIteratore aux(*this);
//        if(puntatore!= nullptr) {
//            if(!past_the_end) {
//                if(puntatore->next != nullptr) puntatore = puntatore->next;
//                else {puntatore = puntatore+1; past_the_end = true;}
//            }
//        }
//        return aux;

//}

//template<class T>
//T & Container<T>::Iteratore::operator*() const
//{
//    return puntatore->info;
//}

//template<class T>
//T * Container<T>::Iteratore::operator->() const
//{
//    return &(puntatore->info);
//}

//template<class T>
//bool Container<T>::Iteratore::operator==(const Iteratore& it)
//{
//    return puntatore == it.puntatore;
//}

//template<class T>
//bool Container<T>::Iteratore::operator!=(const Iteratore& it)
//{
//    return puntatore != it.puntatore;
//}

//template<class T>
//void Container<T>::push_back(deepPtr<T> p)
//{
//  if(ultimo){
//      ultimo->next = new nodo(p, nullptr);
//      ultimo = ultimo->next;
//  }
//  else{
//      primo=ultimo=new nodo(p);
//  }
//}

