#include <iostream>
#include "DoublyLinkedList.h"
#include "Test.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto *list = new DoublyLinkedList<Test>();
    auto *tull = new Test(5, "test");


    list->addFirst(tull);
    list->addFirst(tull);
    list->addFirst(tull);

    list->display();

    list->remove(tull);
    list->remove(tull);

    list->display();
    return 0;
}