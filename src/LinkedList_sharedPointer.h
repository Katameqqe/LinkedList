#ifndef LL_shared_H
#define LL_shared_H

#include <iostream>
#include <memory>

template <typename T>
class Node
{
public:
    using PtrT = std::shared_ptr<Node<T>>;

    static PtrT create(T data);

    // TODO; implement getters and setters for internal variables 
    // TODO: data should be private
    T data;
    PtrT next;

    // TODO: constructor always first 
    Node(T data);
    // destructor is needed!
    // next = nullptr;

    // should be mthods

    // should be private section
};

template <typename T>
class LinkedList_sharedPointer
{
public:
    LinkedList_sharedPointer();
    int size();
    void insertToN(int n, T value);
    void insertToStart(T value);
    void insertToEnd(T value);
    void deleteN(int n);
    void deleteEnd();
    void deleteList();
    void display();
    ~LinkedList_sharedPointer();

private:
    PtrT head;
};
#endif