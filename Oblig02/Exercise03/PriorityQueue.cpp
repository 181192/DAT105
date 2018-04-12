//
// Created by k on 12.04.18.
//

#include <iostream>
#include "PriorityQueue.h"

#include "Enode.h"
#include "../graf/edge.h"

PriorityQueue::PriorityQueue() {
    first = nullptr;
    last = nullptr;
    size = 0;
}

PriorityQueue::~PriorityQueue() = default;

void PriorityQueue::add(Edge *el) {
    Enode *e;

    Enode *nynode = new Enode(el);

    Enode *denne = first, *forrige = nullptr;


    while (denne != nullptr && el->weight > denne->getEdge()->weight) {
        forrige = denne;
        denne = denne->getNext();
    }

    if (isEmpty()) {
        first = nynode;
        last = nynode;
    }
    else if (forrige == nullptr){
        first = nynode;
        nynode->setNext(denne);
    }
    else {
        forrige->setNext(nynode);
        nynode->setNext(denne);
    }

    if (denne == nullptr) {
        last = nynode;
    }

    size++;
}
Edge *PriorityQueue::remove() {
    Edge *tmp = first->getEdge();
    first = first->getNext();
    size--;
    return tmp;
}


bool PriorityQueue::isEmpty() {
    return size == 0;
}





Enode *PriorityQueue::getFirst() const {
    return first;
}


int PriorityQueue::getSize() const {
    return size;
}


void PriorityQueue::setFirst(Enode *first) {
    PriorityQueue::first = first;
}

Enode *PriorityQueue::getLast() const {
    return last;
}

void PriorityQueue::setLast(Enode *last) {
    PriorityQueue::last = last;
}

void PriorityQueue::operator+=(Edge *edge) {
    add(edge);
}