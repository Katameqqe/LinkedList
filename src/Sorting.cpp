#include "Sorting.h"
#include <stdio.h>

// TODO: implement search function. Linear search.

Node<int>* Sorting::search(int value, Node<int>* list)
{
    Node<int> *current = list;
    while (current != nullptr)
    {
        if(current->getData() < value)
        {
            return current;
        }
        current = current->getNext();
    }
    return list;
}

LinkedList_RawPointer<int> Sorting::inserSort(LinkedList_RawPointer<int> list)
{
    LinkedList_RawPointer<int> sortedList = list.copyList();
    Node<int> *current = sortedList.getHead();
    Node<int> *nextNode = nullptr;
    Node<int> *prevNode = current;
    Node<int> *temp;

    while (current != nullptr)
    {
        nextNode = current->getNext();
        temp = search(current->getData(), sortedList.getHead());
        printf("%d ", temp->getData());
        if (temp != nullptr)
        {
            prevNode->setNext(nextNode);
            temp->setNext(current);
            current->setNext(temp->getNext());
        }
        prevNode = prevNode->getNext();
        current = nextNode;
    }
    return sortedList;
}
