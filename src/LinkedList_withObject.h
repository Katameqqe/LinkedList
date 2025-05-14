#ifndef LL_H
#define LL_H

#include <iostream>

class NodeData
{
    NodeData();
    
};

class Person : public NodeData
{
    std::string name;

};

class Node
{
public:
    Node(NodeData data);

    NodeData getData();
    void setData(NodeData data);
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