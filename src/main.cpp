#include "LinkedList.h"
#include "Sorting.h"
#include <string>
#include <stdio.h>

int main ()
{
    LinkedList_RawPointer<int> list;

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