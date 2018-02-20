//
// Created by k on 17.02.18.
//

#ifndef LAB4_DOUBLENODE_H
#define LAB4_DOUBLENODE_H


template<class T>
class DoubleNode {
public:

    DoubleNode() {
        next = nullptr;
        previous = nullptr;
        element = nullptr;

    }

    DoubleNode(T element, DoubleNode<T> *next, DoubleNode<T> *previous) : element(element), next(next),
                                                                          previous(previous) {}

    T *getElement() const {
        return element;
    }

    void setElement(T *element) {
        DoubleNode::element = element;
    }

    DoubleNode<T> *getNext() const {
        return next;
    }

    void setNext(DoubleNode<T> *next) {
        DoubleNode::next = next;
    }

    DoubleNode<T> *getPrevious() const {
        return previous;
    }

    void setPrevious(DoubleNode<T> *previous) {
        DoubleNode::previous = previous;
    }

private:
    T *element;
    DoubleNode<T> *next;
    DoubleNode<T> *previous;
};


#endif //LAB4_DOUBLENODE_H
