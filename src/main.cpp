#include "LinkedList.h"
#include <string>

int main ()
{
    LinkedList_RawPointer<std::string> list;

    list.insertToEnd("Hello");
    list.insertToEnd("World");
    list.insertToEnd("!");

    list.insertToN(1, "Beautiful");
    list.insertToN(1, "C++");

    list.display();
    std::cout << "Size of the list: " << list.size() << std::endl;

    list.deleteN(4);
    list.display();
    std::cout << "Size of the list: " << list.size() << std::endl;

    list.deleteEnd();
    list.display();
    std::cout << "Size of the list: " << list.size() << std::endl;

    list.deleteList();
    list.display();
    std::cout << "Size of the list: " << list.size() << std::endl;

    return 0;
}