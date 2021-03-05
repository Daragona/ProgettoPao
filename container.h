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
//    Container(const Container&);
//    ~Container();

    Container& operator=(const Container&);

    unsigned int size(){ return length; } ;

    Container() : primo(nullptr), ultimo(nullptr), length(0){};

    void push_back(T p)
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




    void deleteNodo(T toRemove){

        nodo *temp = primo;
        nodo *prev = nullptr;

        while(temp && temp->info != toRemove){
            prev = temp;
            temp = temp->next;
        }

        if(temp == nullptr){
            return;
        }

        prev->next = temp->next;
        delete temp;
        length -= 1;
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


        Iteratore& operator++(int n)
        {
                if(puntatore!= nullptr) {
                    if(!past_the_end) {
                        if(puntatore->next != nullptr) puntatore = puntatore->next;
                        else {puntatore = puntatore+n; past_the_end = true;}
                    }
                }
                return *this;
        }

        const T & operator*() const
        {
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
