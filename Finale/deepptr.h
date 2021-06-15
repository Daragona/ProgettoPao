#ifndef DEEPPTR_H
#define DEEPPTR_H

template <class T>
class deepPtr{
private:
    T* pter;
public:
    deepPtr(T* itm=nullptr);
    deepPtr(const deepPtr&);
    deepPtr& operator=(const deepPtr&);
    T* operator->() const;
    //~deepPtr();
    bool operator==(const deepPtr&) const;
    bool operator!=(const deepPtr&) const;
    operator T*() const;


};

template <class T>
deepPtr<T>::deepPtr(T* itm): pter(itm){}

template <class T>
deepPtr<T>::deepPtr(const deepPtr& dptr){
    if(!dptr)
        pter=nullptr;
    else
        pter = dptr.pter;
}

template <class T>
deepPtr<T>::operator T *() const{
    if(this)return pter;
    else return nullptr;
}

template <class T>
T* deepPtr<T>::operator->() const{
    if(pter)return pter;
    else return nullptr;
}

template <class T>
deepPtr<T>& deepPtr<T>::operator=(const deepPtr& dptr){
    if(this != &dptr){
        if(pter)
            delete pter;
        pter = dptr.pter;
    }
    return *this;
}

template <class T>
bool deepPtr<T>::operator==(const deepPtr& dptr) const{
    return *pter==*(dptr.pter);
}

template <class T>
bool deepPtr<T>::operator!=(const deepPtr& dptr) const{
    return *pter!=*(dptr.pter);
}


#endif // DEEPPTR_H
