#include "LinkedList_sharedPointer.h"

template <typename T>
typename NodeShared<T>::PtrT NodeShared<T>::create(T data)
{
    return std::make_shared<NodeShared<T>>(data);
}

template <typename T>
NodeShared<T>::NodeShared(T data) :
    data(data)
    , next (nullptr)
{
}

template <typename T>
T NodeShared<T>::getData()
{
    return this->data;
}

template <typename T>
void NodeShared<T>::setData(T value)
{
    data = value;
}

template <typename T>
typename NodeShared<T>::PtrT NodeShared<T>::getNext()
{
    return this->next;
}

template <typename T>
void NodeShared<T>::setNext(typename NodeShared<T>::PtrT next)
{
    this->next = next;
}

template <typename T>
LinkedList_sharedPointer<T>::LinkedList_sharedPointer()
{
    head = nullptr;
}

template <typename T>
LinkedList_sharedPointer<T>::LinkedList_sharedPointer(const LinkedList_sharedPointer<T>& other) : head(nullptr) {
    PtrT temp = other.getHead();
    while (temp != nullptr) {
        insertToEnd(temp->getData());
        temp = temp->getNext();
    }
}
template <typename T>
LinkedList_sharedPointer<T>::~LinkedList_sharedPointer()
{
    deleteList();
}

template <typename T>
int LinkedList_sharedPointer<T>::size()
{
    int count = 0;
    PtrT temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->getNext();
    }
    return count;
}

template <typename T>
void LinkedList_sharedPointer<T>::insertToN(int n, T value)
{
    PtrT newNode = NodeShared<T>::create(value);
    if (n == 0)
    {
        newNode->setNext(head);
        head = newNode;
    }
    else
    {
        PtrT temp = head;
        for (int i = 0; i < n - 1 && temp != nullptr; i++)
        {
            temp = temp->getNext();
        }
        if (temp != nullptr)
        {
            newNode->setNext(temp->getNext());
            temp->setNext(newNode);
        }
    }
}

template <typename T>
void LinkedList_sharedPointer<T>::insertToStart(T value)
{
    insertToN(0,value);
}

template <typename T>
void LinkedList_sharedPointer<T>::insertToEnd(T value)
{
    PtrT newNode = NodeShared<T>::create(value);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        PtrT temp = head;
        while(temp->getNext() != nullptr)
        {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
    }
}

template <typename T>
void LinkedList_sharedPointer<T>::deleteN(int n)
{
    if (head == nullptr)
    {
        return;
    }
    PtrT temp = head;
    if (n == 0)
    {
        head = temp->getNext();
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
    PtrT nextNode = temp->getNext()->getNext();
    temp->setNext(nextNode);
}

template <typename T>
void LinkedList_sharedPointer<T>::deleteEnd()
{
    if (head == nullptr) 
    {
        return;
    }
    if (head->getNext() == nullptr)
    {
        head = nullptr;
        return;
    }
    PtrT temp = head;
    while (temp->getNext()->getNext() != nullptr)
    {
        temp = temp->getNext();
    }
    temp->setNext(nullptr);
}

template <typename T>
void LinkedList_sharedPointer<T>::deleteList()
{
    PtrT temp = head;
    while (temp != nullptr)
    {
        PtrT next = temp->getNext();
        temp = next;
    }
    head = nullptr;
}

template <typename T>
void LinkedList_sharedPointer<T>::display(){
    PtrT temp = head;
    
    while (temp != nullptr)
    {
        std::cout << temp->getData() << " -> ";
        temp = temp->getNext();
    }
    std::cout << "nullptr" << std::endl;
}

template <typename T>
typename NodeShared<T>::PtrT LinkedList_sharedPointer<T>::getHead() const
{
    return head;
}

template <typename T>
void LinkedList_sharedPointer<T>::setHead(typename NodeShared<T>::PtrT phead)
{
    head = phead;
}

template <typename T>
const LinkedList_sharedPointer<T> LinkedList_sharedPointer<T>::copyList() {
    LinkedList_sharedPointer<T> newList;
    PtrT temp = head;

    while (temp != nullptr) {
        newList.insertToEnd(temp->getData());
        temp = temp->getNext();
    }

    return newList;
}

template class NodeShared<int>;
template class NodeShared<std::string>;

template class LinkedList_sharedPointer<std::string>;
template class LinkedList_sharedPointer<int>;