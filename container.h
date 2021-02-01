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


    class constIteratore
    {
        friend class Container<T>;
    private:
        const nodo* puntatore;
        bool past_the_end;
        constIteratore(nodo* t, bool pte=0): puntatore(t),past_the_end(pte){};
    public:

        //template<class T>
        //typename Container<T>::constIteratore & Container<T>::constIteratore::operator=(const constIteratore & cit)
        //{
        //    puntatore=cit.puntatore;
        //    return *this;
        //}
//        constIteratore();
//        constIteratore& operator=(const constIteratore&);
//        constIteratore& operator++();
//        constIteratore& operator++(int);
//        const T& operator*() const;
//        const T* operator->() const;
//        bool operator==(const constIteratore&);
//        bool operator!=(const constIteratore&);


        constIteratore() : puntatore(nullptr), past_the_end(false){}

        constIteratore operator=(const constIteratore & cit)
        {
            puntatore=cit.puntatore;
            return *this;
        }


        constIteratore& operator++()
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

        constIteratore& operator++(int)
        {
            constIteratore aux(*this);
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
            return puntatore->info;
        }


        const T * operator->() const
        {
            return &(puntatore->info);
        }


        bool operator==(const constIteratore& cit)
        {
            return puntatore == cit.puntatore;
        }


        bool operator!=(const constIteratore& cit)
        {
            return puntatore != cit.puntatore;
        }



    };

    constIteratore inizio() const
    {
        return constIteratore(primo);
    }


    constIteratore fine() const
    {
        if(!ultimo) return constIteratore();
        return constIteratore(ultimo);
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








//    Iteratore inizio() const
//    {
//        return Iteratore(primo);
//    }


//    Iteratore fine() const
//    {
//        if(!ultimo) return Iteratore();
//        return Iteratore(ultimo);
//    }

//        Iteratore() : puntatore(nullptr) {}

//        Iteratore inizio()
//        {
//            return Iteratore(Container::primo);
//        }


//        typename Iteratore fine()
//        {
//            return Iteratore(ultimo);
//        }


//        Iteratore::Iteratore() : puntatore(nullptr) {}


//        typename Iteratore & Iteratore::operator=(const Iteratore & it)
//        {
//            puntatore=it.puntatore;
//            return *this;
//        }


//        typename Iteratore& Iteratore::operator++()
//        {
//            if(puntatore!= nullptr){
//                if(!past_the_end){
//                    if(puntatore->next != nullptr) {puntatore = puntatore->next;}
//                 else { puntatore = puntatore+1; past_the_end = true; }
//                 }
//            }
//            return *this;

//        }

//        typename Iteratore& Iteratore::operator++(int)
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


//        T & Iteratore::operator*() const
//        {
//            return puntatore->info;
//        }


//        T * Iteratore::operator->() const
//        {
//            return &(puntatore->info);
//        }


//        bool Iteratore::operator==(const Iteratore& it)
//        {
//            return puntatore == it.puntatore;
//        }


//        bool Iteratore::operator!=(const Iteratore& it)
//        {
//            return puntatore != it.puntatore;
//        }

//    };
//    constIteratore inizio() const;
//    constIteratore fine() const;
//    Iteratore inizio();
//    Iteratore fine();
};

#endif // CONTAINER_H
