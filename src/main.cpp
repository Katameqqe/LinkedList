#include "LinkedList_RawPointer.h"
#include "LinkedList_sharedPointer.h"
#include "Sorting.h"
#include <string>
#include <stdio.h>

#include "LinkedListNodeRawPointer.hpp"
#include "LinkedList.hpp"
#include "InsertionSorter.hpp"

int main ()
{
    LinkedList_RawPointer<int> list;
    LinkedList_sharedPointer<int> slist;

    slist.insertToStart(1);
    slist.insertToStart(2);
    slist.insertToStart(3);
    slist.insertToStart(4);
    slist.insertToStart(5);
    slist.display();

    LinkedList_sharedPointer<int> slist2 = Sorting::inserionSort(slist);
    slist2.display();

    std::cout << "------------------------" << std::endl;

    list.insertToEnd(1);
    list.insertToEnd(2);
    list.insertToEnd(3);

    list.insertToN(1, 4);
    list.insertToN(1, 5);

    list.display();
    LinkedList_RawPointer<int> rlist = Sorting::inserSort(list);
    rlist.display();

    std::cout << "------------------------" << std::endl;

    LinkedListNodeRawPointer<int> *headNode = new LinkedListNodeRawPointer<int>(1);

    headNode = LinkedList::insertToStart(headNode, new LinkedListNodeRawPointer<int>(2));
    headNode = LinkedList::insertToStart(headNode, new LinkedListNodeRawPointer<int>(3));
    headNode = LinkedList::insertToStart(headNode, new LinkedListNodeRawPointer<int>(4));
    headNode = LinkedList::insertToStart(headNode, new LinkedListNodeRawPointer<int>(5));
    headNode = LinkedList::insertToStart(headNode, new LinkedListNodeRawPointer<int>(5));
    headNode = LinkedList::insertToStart(headNode, new LinkedListNodeRawPointer<int>(4));
    headNode = LinkedList::insertToStart(headNode, new LinkedListNodeRawPointer<int>(3));

    std::cout << headNode->toString();

    LinkedListNodeRawPointer<int> *sortedHead = InsertionSorter::inserionSort(headNode);

    std::cout << sortedHead->toString();

    delete headNode;

    std::cout << "------------------------" << std::endl;

    // BinarySorting::....
    return 0;
}
