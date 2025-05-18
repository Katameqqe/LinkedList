//
//  LinkedList.hpp
//  LinkedList_rawPointer
//
//  Created by Danil Korotenko on 5/18/25.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>

class LinkedList
{
public:
    template <typename T>
    static int size(T aHeadNode);

    template <typename T>
    static T insertToN(T aHeadNode, int n, T aNode)
    {
        if (n == 0)
        {
            aNode->setNext(aHeadNode);
            return aNode;
        }

        T temp = aHeadNode;
        for (int i = 0; i < n - 1 && temp != nullptr; i++)
        {
            temp = temp->getNext();
        }

        if (temp != nullptr)
        {
            aNode->setNext(temp->getNext());
            temp->setNext(aNode);
        }
        return aHeadNode;
    }

    template <typename T>
    static T insertToStart(T aHeadNode, T aNode)
    {
        return insertToN(aHeadNode, 0, aNode);
    }

    template <typename T>
    static void insertToEnd(T aHeadNode, T aNode);

    template <typename T>
    void deleteN(T aHeadNode, int n);

    template <typename T>
    void deleteEnd(T aHeadNode);

    template <typename T>
    void display(T aHeadNode);

    template <typename T>
    void swapNodes(T aNode1, T aNode2);
};


#endif /* LinkedList_hpp */
