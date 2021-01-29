#include "deepptr.h"

//template <class T>
//deepPtr<T>::deepPtr(T* itm): pter(itm){}

//template <class T>
//deepPtr<T>::deepPtr(const deepPtr& dptr){
//      if(!dptr) pter=nullptr;
//      else      pter=dptr.pted->clone();
//}

//template <class T>
//deepPtr<T>::~deepPtr(){
//    if(pter)    delete pter;
//}

//template <class T>
//deepPtr<T>& deepPtr<T>::operator=(const deepPtr& dptr){
//    if(this != &dptr){
//        if(pter)    delete pter;
//        pter = dptr.pted->clone();
//    }
//    return *this;
//}

//template <class T>
//bool deepPtr<T>::operator==(const deepPtr& dptr) const{
//    return *pter==*(dptr.pted);
//}

//template <class T>
//bool deepPtr<T>::operator!=(const deepPtr& dptr) const{
//    return *pter!=*(dptr.pted);
//}

//template<class T>
//deepPtr<T>::operator T *() const{
//    return pter;
//}

//template <class T>
//T* deepPtr<T>::operator->() const{
//       return pter;
//}
