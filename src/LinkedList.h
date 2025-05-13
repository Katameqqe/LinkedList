#ifndef LL_H
#define LL_H

#include <iostream>

template <typename T>
class Node
{
public:
    Node(T data);

    T getData();
    void setData(T data);
    Node<T> *getNext();
    void setNext(Node<T> *next);

private:
    T data;
    Node<T> *next;
};

template <typename T>
class LinkedList_RawPointer
{
public:
    LinkedList_RawPointer();
    int size();
    void insertToN(int n, T value);
    void insertToStart(T value);
    void insertToEnd(T value);
    void deleteN(int n);
    void deleteEnd();
    void deleteList();
    void display();
    ~LinkedList_RawPointer();

private:
    Node<T> *head;

};

#endif