#ifndef DEEPPTR_H
#define DEEPPTR_H

template <class T>
class deepPtr{
private:
    T* pter;
public:

    deepPtr(T* itm): pter(itm){}

    operator T *() const{
        return pter;
    }


    T* operator->() const{
           return pter;
    }

    //    deepPtr(const deepPtr& dptr){
    //          if(!dptr) pter=nullptr;
    //          else      pter=dptr.pted->clone();
    //    }


    //    ~deepPtr(){
    //        if(pter)    delete pter;
    //    }


    //    deepPtr<T>& operator=(const deepPtr& dptr){
    //        if(this != &dptr){
    //            if(pter)    delete pter;
    //            pter = dptr.pter->clone();
    //        }
    //        return *this;
    //    }


    //    bool operator==(const deepPtr& dptr) const{
    //        return *pter==*(dptr.pted);
    //    }


    //    bool operator!=(const deepPtr& dptr) const{
    //        return *pter!=*(dptr.pter);
    //    }
};


#endif // DEEPPTR_H
