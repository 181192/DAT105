//
// Created by k on 12.04.18.
//

#include "Edge.h"

Edge::Edge(Node* v, Node* w, int wt, bool d){
    endpoint[0] = v;
    endpoint[1] = w;
    weight = wt;
    isDirected = d;
};