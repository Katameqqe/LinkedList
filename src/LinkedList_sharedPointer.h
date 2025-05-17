#ifndef LL_shared_H
#define LL_shared_H

#include <iostream>
#include <memory>

template <typename T>
class NodeShared
{
public:
    using PtrT = std::shared_ptr<NodeShared<T>>;
    static PtrT create(T data);

    // TODO: constructor always first 
    NodeShared(T data);
    // destructor is needed!
    // next = nullptr;
    T getData();
    void setData(T value);
    PtrT getNext();
    void setNext(PtrT next);
private:
    T data;
    PtrT next;
};

template <typename T>
class LinkedList_sharedPointer
{
public:
    using PtrT = typename NodeShared<T>::PtrT;
    
    LinkedList_sharedPointer();
    LinkedList_sharedPointer(const LinkedList_sharedPointer<T>& other);
    
    int size();
    void insertToN(int n, T value);
    void insertToStart(T value);
    void insertToEnd(T value);
    void deleteN(int n);
    void deleteEnd();
    void deleteList();
    void display();

    PtrT getHead() const;
    void setHead(PtrT phead);

    const LinkedList_sharedPointer<T> copyList();

    ~LinkedList_sharedPointer();

private:
    typename NodeShared<T>::PtrT head;
};
#endif