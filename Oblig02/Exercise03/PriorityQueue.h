//
// Created by k on 12.04.18.
//

#ifndef EXERCISE03_PRIORITYQUEUE_H
#define EXERCISE03_PRIORITYQUEUE_H


class Edge;

class Enode;

class PriorityQueue {
public:

    PriorityQueue();

    virtual ~PriorityQueue();

    void add(Edge *el);

    Edge *remove();

    bool isEmpty();

    int getSize() const;

    Enode *getFirst() const;

    void setFirst(Enode *first);

    Enode *getLast() const;

    void setLast(Enode *last);

    void operator+=(Edge *edge);


private:
    Enode *first;
    Enode *last;
    int size;

};


#endif //EXERCISE03_PRIORITYQUEUE_H
