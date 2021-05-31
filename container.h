#ifndef CONTAINER_H
#define CONTAINER_H

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
    unsigned int length;

public:
//    Container();
//    Container(const T&);
//    ~Container();

    Container& operator=(const Container&);

    unsigned int size();

    Container();
    Container(const Container&);

    void push_back(T p);
    void deleteNodo(T toRemove);


    class Iteratore{
        friend Container<T>;
    private:
        nodo * puntatore;
        bool past_the_end;
        Iteratore(nodo * );
    public:
        Iteratore(const Iteratore&);

        Iteratore();
        Iteratore operator=(const Iteratore &);
        Iteratore &operator++();
        Iteratore &operator++(int);
        T &operator*() const;
        T *operator->() const;
        bool operator==(const Iteratore &);
        bool operator!=(const Iteratore &);

    };
    Iteratore inizio();
    Iteratore fine();

    class Const_Iteratore{
        friend Container<T>;
    private:
        const nodo * puntatore;
        bool past_the_end;
        Const_Iteratore(nodo * );

    public:
        Const_Iteratore(const Const_Iteratore&);
        Const_Iteratore();

        Const_Iteratore operator=(const Const_Iteratore &);
        Const_Iteratore &operator++();
        Const_Iteratore &operator++(int);
        const T &operator*() const;
        const T *operator->() const;
        bool operator==(const Const_Iteratore &);
        bool operator!=(const Const_Iteratore &);

    };
    Const_Iteratore inizioc() const;
    Const_Iteratore finec() const;
};

template <class T>
unsigned int Container<T>::size(){
    return length;
}

template <class T>
void Container<T>::push_back(T p)
{
  if(ultimo){
      ultimo->next = new nodo(p, nullptr);
      ultimo = ultimo->next;
  }
  else{
      primo=ultimo=new nodo(p);
  }
  length += 1;
}

template <class T>
void Container<T>::deleteNodo(T toRemove){
    nodo *temp = primo;
    nodo *prev = nullptr;
    while(temp && temp->info != toRemove){
        prev = temp;
        temp = temp->next;
    }

    if(temp == nullptr)  return;

    if(prev){
         prev->next = temp->next;
    }else{
        primo=primo->next;
        if(primo==nullptr) ultimo=primo;
    }

    delete temp;
    length -= 1;
}

template <class T>
Container<T>::Container() : primo(nullptr), ultimo(nullptr), length(0){};

template <class T>
Container<T>::Container(const Container& c) : primo(c.primo), ultimo(c.ultimo), length(c.length){}

template <class T>
Container<T>::Iteratore::Iteratore(nodo * p) : puntatore(p) {}

template <class T>
Container<T>::Iteratore::Iteratore(const Iteratore& p) : puntatore(p.puntatore) {}

template <class T>
Container<T>::Iteratore::Iteratore() : puntatore(nullptr) {}

template <class T>
typename Container<T>::Iteratore Container<T>::Iteratore::operator=(const Iteratore & it){
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

template<class T>
typename Container<T>::Iteratore Container<T>::inizio()
{
    return Iteratore(primo);
}

template<class T>
typename Container<T>::Iteratore Container<T>::fine()
{
    return Iteratore(nullptr);
}

template <class T>
Container<T>::Const_Iteratore::Const_Iteratore(nodo * p) : puntatore(p) {}

template <class T>
Container<T>::Const_Iteratore::Const_Iteratore(const Const_Iteratore& p) : puntatore(p.puntatore) {}


template <class T>
Container<T>::Const_Iteratore::Const_Iteratore() : puntatore(nullptr) {}


template <class T>
typename Container<T>::Const_Iteratore Container<T>::Const_Iteratore::operator=(const Const_Iteratore & cit){
    puntatore=cit.puntatore;
    return *this;
}

template<class T>
typename Container<T>::Const_Iteratore& Container<T>::Const_Iteratore::operator++()
{
    if(puntatore) puntatore=puntatore->next;
    return *this;
}

template<class T>
typename Container<T>::Const_Iteratore& Container<T>::Const_Iteratore::operator++(int)
{
    Const_Iteratore aux=*this;
    if(puntatore) puntatore=puntatore->next;
    return aux;

}

template<class T>
const T & Container<T>::Const_Iteratore::operator*() const
{
    return puntatore->info;
}

template<class T>
const T * Container<T>::Const_Iteratore::operator->() const
{
    return &(puntatore->info);
}

template<class T>
bool Container<T>::Const_Iteratore::operator==(const Const_Iteratore& cit)
{
    return puntatore == cit.puntatore;
}

template<class T>
bool Container<T>::Const_Iteratore::operator!=(const Const_Iteratore& cit)
{
    return puntatore != cit.puntatore;
}

template<class T>
typename Container<T>::Const_Iteratore Container<T>::inizioc() const
{
    return Const_Iteratore(primo);
}

template<class T>
typename Container<T>::Const_Iteratore Container<T>::finec() const
{
    return Const_Iteratore(nullptr);
}

#endif // CONTAINER_H
