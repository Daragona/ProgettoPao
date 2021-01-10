#ifndef DEEPPTR_H
#define DEEPPTR_H

template <class T>
class deepPtr{
private:
    T* pter;
public:
    deepPtr(T* =nullptr);
    deepPtr(const deepPtr&);
    deepPtr& operator=(const deepPtr&);
    ~deepPtr();
    bool operator==(const deepPtr&) const;
    bool operator!=(const deepPtr&) const;
    operator T*() const;
    T* operator->() const;

};


#endif // DEEPPTR_H
