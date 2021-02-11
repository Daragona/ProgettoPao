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



public:
//    Container();
//    Container(const T&);
//    Container(const Container&);
//    ~Container();
    Container& operator=(const Container&);

    Container() : primo(nullptr), ultimo(nullptr){};

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






    class Iteratore{
        friend Container<T>;
    private:
        nodo * puntatore;
        bool past_the_end;
        Iteratore(nodo * p) : puntatore(p) {}
    public:
        Iteratore() : puntatore(nullptr), past_the_end(false){}

        Iteratore operator=(const Iteratore & cit)
        {
            puntatore=cit.puntatore;
            return *this;
        }


        Iteratore& operator++()
        {
            if(puntatore!= nullptr){
                if(!past_the_end){
                    if(puntatore->next != nullptr) {puntatore = puntatore->next;}
                 else { puntatore = puntatore+1; past_the_end = true; }
                 }
            }
            else{
                return *this;
            }


        }


        Iteratore& operator++(int)
        {
            Iteratore aux(*this);
                if(puntatore!= nullptr) {
                    if(!past_the_end) {
                        if(puntatore->next != nullptr) puntatore = puntatore->next;
                        else {puntatore = puntatore+1; past_the_end = true;}
                    }
                }
                return aux;
        }

        const T & operator*() const
        {
            if(this == nullptr) return nullptr;
            return puntatore->info;
        }


        const T * operator->() const
        {
            return &(puntatore->info);
        }


        bool operator==(const Iteratore& cit)
        {
            return puntatore == cit.puntatore;
        }


        bool operator!=(const Iteratore& cit)
        {
            return puntatore != cit.puntatore;
        }
    };

    Iteratore inizio()
    {
        return Iteratore(Container::primo);
    }


    Iteratore fine()
    {
        if(!ultimo) return Iteratore();
        return Iteratore(ultimo);
    }


};

#endif // CONTAINER_H
