#include "LinkedList_RawPointer.h"
#include "LinkedList_sharedPointer.h"
#include "Sorting.h"
#include <string>
#include <stdio.h>

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

    list.insertToEnd(1);
    list.insertToEnd(2);
    list.insertToEnd(3);

    list.insertToN(1, 4);
    list.insertToN(1, 5);

    list.display();
    LinkedList_RawPointer<int> rlist = Sorting::inserSort(list);
    rlist.display();

    // BinarySorting::....
    return 0;
}