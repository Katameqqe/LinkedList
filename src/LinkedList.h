#ifndef LL_H
#define LL_H

#include <iostream>

template <typename T>
class Node
{
public:
    Node(T data);

    T getData();
    void setData(T value);
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
    LinkedList_RawPointer(const LinkedList_RawPointer<T>& other);
    int size();
    void insertToN(int n, T value);
    void insertToStart(T value);
    void insertToEnd(T value);
    void deleteN(int n);
    void deleteEnd();
    void deleteList();
    void display();
    void swapNodes(Node<T> *n1, Node<T> *n2);
    const LinkedList_RawPointer<T> copyList();
    Node<T>* getHead();
    void setHead(Node<T> *phead);
    ~LinkedList_RawPointer();

private:
    Node<T> *head;

};

#endif