//
//  LinkedListNode.hpp
//  LinkedList_rawPointer
//
//  Created by Danil Korotenko on 5/18/25.
//

#ifndef LinkedListNodeRawPointer_hpp
#define LinkedListNodeRawPointer_hpp

#include <stdio.h>
#include <string>
#include <sstream>

template <typename T>
class LinkedListNodeRawPointer
{
public:
    LinkedListNodeRawPointer(T data) :
        data(data)
        , next(nullptr)
    {
    }

    ~LinkedListNodeRawPointer()
    {
        if (next != nullptr)
        {
            delete next;
        }
    }

    T getData()
    {
        return this->data;
    }

    LinkedListNodeRawPointer<T> *getNext()
    {
        return this->next;
    }

    void setNext(LinkedListNodeRawPointer<T> *next)
    {
        this->next = next;
    }

    std::string toString()
    {
        std::stringstream ss;
        ss << this->data;
        if (this->next == nullptr)
        {
            ss << "->nullptr" << std::endl;
        }
        else
        {
            ss << "->" << next->toString();
        }
        return ss.str();
    }

    LinkedListNodeRawPointer<T> *copy()
    {
        LinkedListNodeRawPointer<T> *newNode = new LinkedListNodeRawPointer<T>(data);
        if (next != nullptr)
        {
            newNode->next = next->copy();
        }
        return newNode;
    }

private:
    T data;
    LinkedListNodeRawPointer<T> *next;
};

#endif /* LinkedListNodeRawPointer_hpp */
