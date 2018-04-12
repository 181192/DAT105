//
// Created by k on 12.04.18.
//

#ifndef EXERCISE03_EDGE_H
#define EXERCISE03_EDGE_H


class Node;
class Edge {

public:

    Edge(Node* v, Node* w, int wt = 0, bool d = false);

    Edge(bool isDirected, int weight, Node **endpoint);

    bool isDirected;
    int weight;
    Node* endpoint[2];
};



#endif //EXERCISE03_EDGE_H
