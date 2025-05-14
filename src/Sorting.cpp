#include "Sorting.h"

// TODO: implement search function. Linear search.
// void search()
// {
// }

void Sorting::inserSort(LinkedList_RawPointer<int> list)
{
    Node<int> *current = list.getHead();
    Node<int> *nextNode = nullptr;
    Node<int> *prevNode = current;

    while (current != nullptr)
    {
        nextNode = current->getNext();
        
        // todo: call search function

        while (prevNode != nullptr && prevNode->getData() < current->getData())
        {
            prevNode = prevNode->getNext();
        }

        if (prevNode != nullptr)
        {
            current->setNext(prevNode);
            current = nextNode;
        }
    }
}