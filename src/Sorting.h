#ifndef SORTING_H
#define SORTING_H

#include "LinkedList_RawPointer.h"
#include "LinkedList_sharedPointer.h"

class Sorting
{
public:
    static LinkedList_RawPointer<int> inserSort(LinkedList_RawPointer<int> list);
    static LinkedList_sharedPointer<int> inserionSort(LinkedList_sharedPointer<int> list);

private:
    //static Node<int>* search(int value, Node<int>* list);

};

// todo: implement class inhertied from Sorting
// class BinarySearchSorting: public Sorting
// {
//     ....
//     void search()
// }

////////// BinarySearchSorting.cpp
// void search()
// {
//     // binary search
// }



#endif
