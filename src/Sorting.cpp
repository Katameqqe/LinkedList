#include "Sorting.h"
#include <stdio.h>

// TODO: implement search function. Linear search.
/*
Node<int>* Sorting::search(int value, Node<int>* head)
{

}
*/
LinkedList_RawPointer<int> Sorting::inserSort(LinkedList_RawPointer<int> list)
{
    LinkedList_RawPointer<int> unsortedList = list.copyList();
    LinkedList_RawPointer<int> sortedList;
    if (unsortedList.getHead() == nullptr || unsortedList.getHead()->getNext() == nullptr)
    {
        return unsortedList;
    }
    while (unsortedList.getHead() != nullptr)
    {
        Node<int> *current = unsortedList.getHead();
        unsortedList.setHead(unsortedList.getHead()->getNext());
        if (sortedList.getHead() == nullptr || current->getData() < sortedList.getHead()->getData())
        {
            current->setNext(sortedList.getHead());
            sortedList.setHead(current);
        }
        else
        {
            Node<int> *prev = sortedList.getHead();
            while(prev != nullptr)
            {
                if (prev->getNext() == nullptr || 
                    current->getData() < prev->getNext()->getData())
                {
                    current->setNext(prev->getNext());
                    prev->setNext(current);
                    break;
                }
                prev = prev->getNext();
            }
        }
    }
    return sortedList;
}

LinkedList_sharedPointer<int> Sorting::inserSort(LinkedList_sharedPointer<int> list)
{
    LinkedList_sharedPointer<int> unsortedList = list.copyList();
    LinkedList_sharedPointer<int> sortedList;
    if (unsortedList.getHead() == nullptr || unsortedList.getHead()->getNext() == nullptr)
    {
        return unsortedList;
    }
    while (unsortedList.getHead() != nullptr)
    {
        NodeShared<int>::PtrT current = unsortedList.getHead();
        unsortedList.setHead(unsortedList.getHead()->getNext());
        if (sortedList.getHead() == nullptr || current->getData() < sortedList.getHead()->getData())
        {
            current->setNext(sortedList.getHead());
            sortedList.setHead(current);
        }
        else
        {
            NodeShared<int>::PtrT prev = sortedList.getHead();
            while(prev != nullptr)
            {
                if (prev->getNext() == nullptr || 
                    current->getData() < prev->getNext()->getData())
                {
                    current->setNext(prev->getNext());
                    prev->setNext(current);
                    break;
                }
                prev = prev->getNext();
            }
        }
    }
    return sortedList;
}
