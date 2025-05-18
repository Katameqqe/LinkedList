//
//  LinkedList.cpp
//  LinkedList_rawPointer
//
//  Created by Danil Korotenko on 5/18/25.
//

#include "LinkedList.hpp"

//template <typename T>
//int LinkedList::size(T aHeadNode)
//{
//    int count = 0;
//    T temp = aHeadNode;
//    while (temp != nullptr)
//    {
//        count++;
//        temp = temp->getNext();
//    }
//    return count;
//}

//
//template <typename T>
//void LinkedList_RawPointer<T>::insertToEnd(T value)
//{
//    Node<T> *newNode = new Node<T>(value);
//    if (head == nullptr)
//    {
//        head = newNode;
//    }
//    else
//    {
//        Node<T> *temp = head;
//        while(temp->getNext() != nullptr)
//        {
//            temp = temp->getNext();
//        }
//        temp->setNext(newNode);
//    }
//}
//
//template <typename T>
//void LinkedList_RawPointer<T>::deleteN(int n)
//{
//    if (head == nullptr)
//    {
//        return;
//    }
//    Node<T> *temp = head;
//    if (n == 0)
//    {
//        head = temp->getNext();
//        delete temp;
//        return;
//    }
//    for (int i = 0; i < n - 1 && temp != nullptr; i++)
//    {
//        temp = temp->getNext();
//    }
//    if (temp == nullptr || temp->getNext() == nullptr)
//    {
//        return;
//    }
//    Node<T> *nextNode = temp->getNext()->getNext();
//    delete temp->getNext();
//    temp->setNext(nextNode);
//}
//
//template <typename T>
//void LinkedList_RawPointer<T>::deleteEnd()
//{
//    if (head == nullptr) 
//    {
//        return;
//    }
//    if (head->getNext() == nullptr)
//    {
//        delete head;
//        head = nullptr;
//        return;
//    }
//    Node<T> *temp = head;
//    while (temp->getNext()->getNext() != nullptr)
//    {
//        temp = temp->getNext();
//    }
//    delete temp->getNext();
//    temp->setNext(nullptr);
//}
//
//template <typename T>
//void LinkedList_RawPointer<T>::deleteList()
//{
//    Node<T> *temp = head;
//    while (temp != nullptr)
//    {
//        Node<T> *next = temp->getNext();
//        delete temp;
//        temp = next;
//    }
//    head = nullptr;
//}
//
//template <typename T>
//void LinkedList_RawPointer<T>::display(){
//    Node<T> *temp = head;
//    while (temp != nullptr)
//    {
//        std::cout << temp->getData() << " -> ";
//        temp = temp->getNext();
//    }
//    std::cout << "nullptr" << std::endl;
//}
//template <typename T>
//void LinkedList_RawPointer<T>::swapNodes(Node<T>* n1, Node<T>* n2)
//{
//    T temp = n1->getData();
//    n1->setData(n2->getData());
//    n2->setData(temp);
//}
//
//template <typename T>
//Node<T>* LinkedList_RawPointer<T>::getHead()
//{
//    return head;
//}
//
//template <typename T>
//void LinkedList_RawPointer<T>::setHead(Node<T>* phead)
//{
//    head = phead;
//}
//
//
//template <typename T>
//const LinkedList_RawPointer<T> LinkedList_RawPointer<T>::copyList() {
//    LinkedList_RawPointer<T> newList;
//    Node<T>* temp = head;
//
//    while (temp != nullptr) {
//        newList.insertToEnd(temp->getData());
//        temp = temp->getNext();
//    }
//
//    return newList;
//}
//
//
//template class Node<int>;
//template class Node<std::string>;
//
//template class LinkedList_RawPointer<int>;
//template class LinkedList_RawPointer<std::string>;
