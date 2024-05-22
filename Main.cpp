#include <iostream>
#include "LinkedList.h"
int main() {
    LinkedList list;

    list.createNode(25);
    list.pushNode(12);

    list.createNode(88);
    list.createNode(899);
//    list.pop()
//    list.removeLast();
//    list.removeByIndex(2);
//    list.removeByData(88);
    list.printList();
    
}
