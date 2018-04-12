//
// Created by k on 12.04.18.
//

#ifndef EXERCISE03_NODE_H
#define EXERCISE03_NODE_H

#include <vector>
#include<climits>
#include<cstdlib>

class Edge;

class Node {
public:
    explicit Node(int d) : data(d), visited(false), distance(INT_MAX), previous(NULL) {}

    char data;
    bool visited;
    int distance;
    Node *previous;
    std::vector<Edge *> edgeList;
};


#endif //EXERCISE03_NODE_H
