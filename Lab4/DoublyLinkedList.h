//
// Created by k on 17.02.18.
//

#ifndef LAB4_DOUBLYLINKEDLIST_H
#define LAB4_DOUBLYLINKEDLIST_H

#include "ListADT.h"
#include "DoubleNode.h"

template<class T>
class DoublyLinkedList : public ListADT<T> {
public:

    DoublyLinkedList(DoubleNode<T> *first, DoubleNode<T> *last) : first(first), last(last), count(0) {}

    DoublyLinkedList() {
        first = nullptr;
        last = nullptr;
        count = 0;
    }

    virtual ~DoublyLinkedList() = default;

    T *removeFirst() override {
        return nullptr;
    }

    T *removeLast() override {
        return nullptr;
    }

    T *find() override {
        return nullptr;
    }

    T *remove() override {
        return nullptr;
    }

    T *first() override {
        return nullptr;
    }

    T *last() override {
        return nullptr;
    }

    bool contains() override {
        return false;
    }

    bool isEmpty() override {
        return false;
    }

private:
    DoubleNode<T> *first;
    DoubleNode<T> *last;
    int count;

};


#endif //LAB4_DOUBLYLINKEDLIST_H
