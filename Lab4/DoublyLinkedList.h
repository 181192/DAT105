//
// Created by k on 17.02.18.
//

#ifndef LAB4_DOUBLYLINKEDLIST_H
#define LAB4_DOUBLYLINKEDLIST_H

#include <ostream>
#include "ListADT.h"
#include "Node.h"
#include "../std_lib_facilities.h"

template<class T>
class DoublyLinkedList : public ListADT<T> {
public:

    explicit DoublyLinkedList(Node<T> *first, Node<T> *last) : first(first), last(last), count(0) {}

    DoublyLinkedList() {
        first = nullptr;
        last = nullptr;
        count = 0;
    }

    virtual ~DoublyLinkedList() = default;

    void addFirst(T *element) override {
        auto *tmp = new Node<T>();

        tmp->setElement(element);
        tmp->setNext(first);
        tmp->setPrevious(nullptr);

        if (first != nullptr)
            first->setPrevious(tmp);

        first = tmp;
        count++;
    }

    void addLast(T *element) override {
        auto *tmp = new Node<T>();
        auto *p = last;
        tmp->setElement(element);
        tmp->setNext(nullptr);
        if (count == 0) {
            tmp->setPrevious(nullptr);
            last = tmp;
            return;
        }

        while (p->getNext() != nullptr)
            p = p->getNext();

        p->setNext(tmp);
        tmp->setPrevious(p);
        count++;
    }

    T *removeFirst() override {
        return first->getNext()->setPrevious(nullptr), first->getElement();
    }

    T *removeLast() override {
        return last->getPrevious()->setNext(nullptr), last->getElement();
    }

    T *find(T *element) override {
        Node<T> *tmp = first;
        while (tmp != nullptr) {
            if (tmp->getElement() == element)
                return tmp->getElement();
            tmp = tmp->getNext();
        }
        return nullptr;
    }

    T *remove(T *element) override {
        Node<T> *tmp = first;
        while (tmp != nullptr) {
            if (tmp->getElement() == element)
                break;
            tmp = tmp->getNext();
        }

        if (first == nullptr)
            return nullptr;

        if (first == tmp)
            first = tmp->getNext();

        if (tmp->getNext() != nullptr)
            tmp->getNext()->setPrevious(tmp->getPrevious());

        return tmp->getElement();
    }

    T *getFirst() override {
        return first->getElement();
    }

    T *getLast() override {
        return last->getElement();
    }

    bool contains(T *element) override {
        return false;
    }

    bool isEmpty() override {
        return count == 0;
    }

    int size() override {
        return count;
    }

    void display() {
        Node<T> *tmp = first;
        while (tmp != nullptr) {
            cout << *tmp->getElement() << endl;
            tmp = tmp->getNext();
        }
    }

private:
    Node<T> *first;
    Node<T> *last;
    int count;

};


#endif //LAB4_DOUBLYLINKEDLIST_H
