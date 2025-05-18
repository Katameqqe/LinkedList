//
//  InsertionSorter.hpp
//  LinkedList_rawPointer
//
//  Created by Danil Korotenko on 5/18/25.
//

#ifndef InsertionSorter_hpp
#define InsertionSorter_hpp

#include <stdio.h>

class InsertionSorter
{
public:

    template <typename T>
    static T inserionSort(T aList)
    {
        if (aList == nullptr || aList->getNext() == nullptr)
        {
            return aList;
        }

        T unsortedList = aList->copy();
        T sortedList = nullptr;

        while (unsortedList != nullptr)
        {
            T current = unsortedList;
            unsortedList = unsortedList->getNext();

            if (sortedList == nullptr || current->getData() < sortedList->getData())
            {
                current->setNext(sortedList);
                sortedList = current;
            }
            else
            {
                T prev = sortedList;
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

};

#endif /* InsertionSorter_hpp */
