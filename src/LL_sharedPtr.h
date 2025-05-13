#ifndef LL_H
#define LL_H

#include <iostream>

template <typename T>
class Node
{
public:
    // TODO; implement getters and setters for internal variables 
    // TODO: data should be private
    T data;
    std::shared_ptr<Node<T>> next;

    // TODO: constructor always first 
    Node(T data);
    // destructor is needed!
    // next = nullptr;

    // should be mthods

    // should be private section
};

template <typename T>
class LinkedList
{
public:
    LinkedList();
    int size();
    void insertToN(int n, T value);
    void insertToStart(T value);
    void insertToEnd(T value);
    void deleteN(int n);
    void deleteEnd();
    void deleteList();
    void display();
    ~LinkedList();

private:
    std::shared_ptr<Node<T>> head;
};
#endif