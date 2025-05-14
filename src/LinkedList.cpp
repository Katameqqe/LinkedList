#include "LinkedList.h"

template <typename T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = nullptr;
}

template <typename T>
T Node<T>::getData()
{
    return this->data;
}

template <typename T>
void Node<T>::setData(T data)
{
    this->data = data;
}

template <typename T>
Node<T> *Node<T>::getNext()
{
    return this->next;
}

template <typename T>
void Node<T>::setNext(Node<T> *next)
{
    this->next = next;
}


template <typename T>
LinkedList_RawPointer<T>::LinkedList_RawPointer()
{
    head = nullptr;
}

template <typename T>
LinkedList_RawPointer<T>::~LinkedList_RawPointer()
{
    deleteList();
}

template <typename T>
int LinkedList_RawPointer<T>::size()
{
    int count = 0;
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->getNext();
    }
    return count;
}

template <typename T>
void LinkedList_RawPointer<T>::insertToN(int n, T value)
{
    Node<T> *newNode = new Node<T>(value);
    if (n == 0)
    {
        newNode->setNext(head);
        head = newNode;
    }
    else
    {
        Node<T> *temp = head;
        for (int i = 0; i < n - 1 && temp != nullptr; i++)
        {
            temp = temp->getNext();
        }
        if (temp != nullptr)
        {
            newNode->setNext(temp->getNext());
            temp->setNext(newNode);
        }
        else
        {
            delete newNode;
        }
    }
}

template <typename T>
void LinkedList_RawPointer<T>::insertToStart(T value)
{
    insertToN(0,value);
}

template <typename T>
void LinkedList_RawPointer<T>::insertToEnd(T value)
{
    Node<T> *newNode = new Node<T>(value);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node<T> *temp = head;
        while(temp->getNext() != nullptr)
        {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
    }
}

template <typename T>
void LinkedList_RawPointer<T>::deleteN(int n)
{
    if (head == nullptr)
    {
        return;
    }
    Node<T> *temp = head;
    if (n == 0)
    {
        head = temp->getNext();
        delete temp;
        return;
    }
    for (int i = 0; i < n - 1 && temp != nullptr; i++)
    {
        temp = temp->getNext();
    }
    if (temp == nullptr || temp->getNext() == nullptr)
    {
        return;
    }
    Node<T> *nextNode = temp->getNext()->getNext();
    delete temp->getNext();
    temp->setNext(nextNode);
}

template <typename T>
void LinkedList_RawPointer<T>::deleteEnd()
{
    if (head == nullptr) 
    {
        return;
    }
    if (head->getNext() == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node<T> *temp = head;
    while (temp->getNext()->getNext() != nullptr)
    {
        temp = temp->getNext();
    }
    delete temp->getNext();
    temp->setNext(nullptr);
}

template <typename T>
void LinkedList_RawPointer<T>::deleteList()
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        Node<T> *next = temp->getNext();
        delete temp;
        temp = next;
    }
    head = nullptr;
}

template <typename T>
void LinkedList_RawPointer<T>::display(){
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->getData() << " -> ";
        temp = temp->getNext();
    }
    std::cout << "nullptr" << std::endl;
}
template <typename T>
void LinkedList_RawPointer<T>::swapNodes(Node<T>* n1, Node<T>* n2)
{
    T temp = n1->getData();
    n1->setData(n2->getData());
    n2->setData(temp);
}

template <typename T>
Node<T>* LinkedList_RawPointer<T>::getHead()
{
    return head;
}

template class Node<int>;
template class Node<std::string>;

template class LinkedList_RawPointer<int>;
template class LinkedList_RawPointer<std::string>;
