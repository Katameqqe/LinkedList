#include "LL.h"
#include <string>

int main (){
    LinkedList<std::string> list;
    
    list.insert("Hello");
    list.insert("World");
    list.insert("!");

    list.display();
    return 0;    
}