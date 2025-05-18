//
//  LinkedListNodeRawPointer.cpp
//  LinkedList_rawPointer
//
//  Created by Danil Korotenko on 5/18/25.
//

#include "LinkedListNodeRawPointer.hpp"

template <typename T>
LinkedListNodeRawPointer<T>::LinkedListNodeRawPointer(T data) :
    data(data)
    , next(nullptr)
{
}

template <typename T>
T LinkedListNodeRawPointer<T>::getData()
{
    return this->data;
}

template <typename T>
void LinkedListNodeRawPointer<T>::setData(T value)
{
    data = value;
}

template <typename T>
LinkedListNodeRawPointer<T> *LinkedListNodeRawPointer<T>::getNext()
{
    return this->next;
}

template <typename T>
void LinkedListNodeRawPointer<T>::setNext(LinkedListNodeRawPointer<T> *next)
{
    this->next = next;
}
