//
//  LinkedListNode.hpp
//  LinkedList_rawPointer
//
//  Created by Danil Korotenko on 5/18/25.
//

#ifndef LinkedListNodeRawPointer_hpp
#define LinkedListNodeRawPointer_hpp

#include <stdio.h>

template <typename T>
class LinkedListNodeRawPointer
{
public:
    LinkedListNodeRawPointer(T data);

    T getData();
    void setData(T value);
    LinkedListNodeRawPointer<T> *getNext();
    void setNext(LinkedListNodeRawPointer<T> *next);

private:
    T data;
    LinkedListNodeRawPointer<T> *next;
};

#endif /* LinkedListNodeRawPointer_hpp */
