//
// Created by k on 17.02.18.
//

#ifndef LAB4_DOUBLENODE_H
#define LAB4_DOUBLENODE_H


#include <ostream>

template<class T>
class Node {
public:

    Node() {
        next = nullptr;
        previous = nullptr;
        element = nullptr;

    }

    Node(T element, Node<T> *next, Node<T> *previous) : element(element), next(next),
                                                        previous(previous) {}

    T *getElement() const {
        return element;
    }

    void setElement(T *element) {
        Node::element = element;
    }

    Node<T> *getNext() const {
        return next;
    }

    void setNext(Node<T> *next) {
        Node::next = next;
    }

    Node<T> *getPrevious() const {
        return previous;
    }

    void setPrevious(Node<T> *previous) {
        Node::previous = previous;
    }

    friend std::ostream &operator<<(std::ostream &os, const Node &node) {
        os << "element: " << node.element << " next: " << node.next->element << " previous: " << node.previous->element;
        return os;
    }

private:
    T *element;
    Node<T> *next;
    Node<T> *previous;
};


#endif //LAB4_DOUBLENODE_H
