#include "LL.h"

template <typename T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = nullptr;
};

template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
}
template <typename T>
LinkedList<T>::~LinkedList()
{
    deleteList();
}
template <typename T>
int LinkedList<T>::size()
{
    int count = 0;
    Node<T>* temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
template <typename T>
void LinkedList<T>::insertToN(int n, T value)
{
    Node<T>* newNode = new Node<T>(value);
    if (n == 0)
    {
        newNode->next = head;
        head = newNode;
    } 
    else
    {
        Node<T>* temp = head;
        for (int i = 0; i < n - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp != nullptr)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else
        {
            delete newNode;
        }
    }
}
template <typename T>
void LinkedList<T>::insertToStart(T value)
{
    insertToN(0,value);
}
template <typename T>
void LinkedList<T>::insertToEnd(T value)
{
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node<T>* temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
template <typename T>
void LinkedList<T>::deleteN(int n)
{
    if (head == nullptr) return;
    Node<T>* temp = head;
    if (n == 0)
    {
        head = temp->next;
        delete temp;
        return;
    }
    for (int i = 0; i < n - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) return;
    Node<T>* nextNode = temp->next->next;
    delete temp->next;
    temp->next = nextNode;
}
template <typename T>
void LinkedList<T>::deleteEnd()
{
    if (head == nullptr) return;
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node<T>* temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}
template <typename T>
void LinkedList<T>::deleteList()
{
    Node<T>* temp = head;
    while (temp != nullptr)
    {
        Node<T>* next = temp->next;
        delete temp;
        temp = next;
    }
    head = nullptr;
}
template <typename T>
void LinkedList<T>::display(){
    Node<T>* temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

// /usr/bin/ld: ./obj/main.o: in function `main.cold':
// main.cpp:(.text.unlikely+0xc): undefined reference to 
// `LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>,
// std::allocator<char> > >::~LinkedList()'
// why without this line, it doesn't link compiled file?
template class LinkedList<std::string>;