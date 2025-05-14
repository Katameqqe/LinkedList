#include "LinkedList.h"
#include "Sorting.h"
#include <string>

int main ()
{
    LinkedList_RawPointer<int> list;

    list.insertToEnd(1);
    list.insertToEnd(2);
    list.insertToEnd(3);

    list.insertToN(1, 4);
    list.insertToN(1, 5);

    list.display();
    Sorting::inserSort(list);
    list.display();

    // BinarySorting::....
    return 0;
}