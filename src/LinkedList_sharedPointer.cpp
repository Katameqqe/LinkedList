#include "LinkedList_sharedPointer.h"

template <typename T>
Node<T>::PtrT Node<T>::create(T data)
{
    return std::shared_ptr<Node<T>>(new Node<T>(value));
}

template <typename T>
Node<T>::Node(T data) :
    data(data)
    , next (nullptr)
{
}

template <typename T>
LinkedList_sharedPointer<T>::LinkedList_sharedPointer():
    head(nullptr)
{
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
    std::shared_ptr<Node<T>> temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
template <typename T>
void LinkedList_sharedPointer<T>::insertToN(int n, T value)
{
    std::shared_ptr<Node<T>> newNode = Node<T>::create(value);
    if (n == 0)
    {
        newNode->next = head;
        head = newNode;
    } 
    else
    {
        std::shared_ptr<Node<T>> temp = head;
        for (int i = 0; i < n - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp != nullptr)
        {
            newNode->next = temp->next;
            temp->next = newNode;
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
    std::shared_ptr<Node<T>> newNode = new Node<T>(value);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        std::shared_ptr<Node<T>> temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
template <typename T>
void LinkedList_sharedPointer<T>::deleteN(int n)
{
    if (head == nullptr) return;
    std::shared_ptr<Node<T>> temp = head;
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
    std::shared_ptr<Node<T>> nextNode = temp->next->next;
    delete temp->next;
    temp->next = nextNode;
}
template <typename T>
void LinkedList_sharedPointer<T>::deleteEnd()
{
    if (head == nullptr) return;
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    std::shared_ptr<Node<T>> temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}
template <typename T>
void LinkedList_sharedPointer<T>::deleteList()
{
    std::shared_ptr<Node<T>> temp = head;
    while (temp != nullptr)
    {
        std::shared_ptr<Node<T>> next = temp->next;
        delete temp;
        temp = next;
    }
    head = nullptr;
}
template <typename T>
void LinkedList_sharedPointer<T>::display(){
    std::shared_ptr<Node<T>> temp = head;
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
template class LinkedList_sharedPointer<std::string>;
template class LinkedList_sharedPointer<int>;