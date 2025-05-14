#include "Sorting.h"

void Sorting::inserSort(LinkedList_RawPointer<int> list)
{
    Node<int> *current = list.getHead();
    Node<int> *nextNode = nullptr;
    Node<int> *prevNode = current;

    while (current != nullptr)
    {
        nextNode = current->getNext();
        

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