#ifndef LL_H
#define LL_H

#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node<T>* next;

    Node(T data);
};

template <typename T>
class LinkedList
{
private:
    Node<T>* head;

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
};
#endif