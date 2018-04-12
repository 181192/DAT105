//
// Created by k on 12.04.18.
//

#ifndef EXERCISE03_ENODE_H
#define EXERCISE03_ENODE_H


class Edge;

class Enode {
public:
    explicit Enode(Edge *edge);

    virtual ~Enode();

    Edge *getEdge() const;

    void setEdge(Edge *edge);

    Enode *getNext() const;

    void setNext(Enode *next);

private:
    Edge *edge;
    Enode *next;
};


#endif //EXERCISE03_ENODE_H
