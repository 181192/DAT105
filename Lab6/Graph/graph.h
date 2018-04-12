#ifndef GRAPH_H
#define GRAPH_H

#include "graphadt.h"
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>

class Graph : public GraphADT {

public:
    // General graph methods
    Node *aVertex() override;

    void insertVertex(Node *n) override;

    void insertEdge(Node *v, Node *w, int i = 0) override;

    void removeVertex(Node *n) override;

    void removeEdge(Edge *e) override;

    std::vector<Edge *> &incidentEdges(Node *n) override;

    Node **endVertices(Edge *e) override;

    Node *opposite(Node *n, Edge *e) override;

    bool areAdjacent(Node *v, Node *w) override;

    // Methods for directed edges
    bool isDirected(Edge *e) override;

    void insertDirectedEdge(Node *v, Node *w, int i = 0) override;

    Node *origin(Edge *e) override;

    Node *destination(Edge *e) override;

    // Generic methods
    int numVertices() override;

    int numEdges() override;

    std::vector<Node *> &vertices() override;

    std::vector<Edge *> &edges() override;

    // Algorithms
    void depthFirstTraversal(Node *n);

    void breadthFirstTraversal(Node *n);

    std::vector<Edge *> primsAlgorithm();

    void dijkstrasAlgorithm(Node *n);

private:
    void setAllUnvisited();

    std::vector<Node *> verticeList;
    std::vector<Edge *> edgeList;
};


Node *Graph::aVertex() {
    if (!verticeList.empty())
        return verticeList.at(0);
    else
        return nullptr;
}

void Graph::insertVertex(Node *n) {
    verticeList.push_back(n);
}

void Graph::insertEdge(Node *v, Node *w, int i) {
    auto *e = new Edge(v, w, i);
    edgeList.push_back(e);
    v->edgeList.push_back(e);
    w->edgeList.push_back(e);
}

void Graph::removeVertex(Node *n) {

}

void Graph::removeEdge(Edge *e) {

}

std::vector<Edge *> &Graph::incidentEdges(Node *n) {
    return n->edgeList;
}

Node **Graph::endVertices(Edge *e) {
    return e->endpoint;
}

Node *Graph::opposite(Node *n, Edge *e) {
    if (e->endpoint[0] == n)
        return e->endpoint[1];
    else
        return e->endpoint[0];
}

bool Graph::areAdjacent(Node *v, Node *w) {
    auto i = v->edgeList.begin();
    while (i != v->edgeList.end()) {
        if ((*i)->endpoint[0] == w || (*i)->endpoint[1] == w) {
            return true;
        }
    }
    return false;
}

bool Graph::isDirected(Edge *e) {
    return e->isDirected;
}

void Graph::insertDirectedEdge(Node *v, Node *w, int i) {
    auto *e = new Edge(v, w, i, true);
    edgeList.push_back(e);
    v->edgeList.push_back(e);
    w->edgeList.push_back(e);
}

Node *Graph::origin(Edge *e) {
    if (e->isDirected)
        return e->endpoint[0];
    else
        return nullptr;
}

Node *Graph::destination(Edge *e) {
    if (e->isDirected)
        return e->endpoint[1];
    else
        return nullptr;
}

int Graph::numVertices() {
    return verticeList.size();
}

int Graph::numEdges() {
    return edgeList.size();
}

std::vector<Node *> &Graph::vertices() {
    return verticeList;
}

std::vector<Edge *> &Graph::edges() {
    return edgeList;
}

void Graph::depthFirstTraversal(Node *n) {
    std::stack<Node *> verticeStack;
    verticeStack.push(n);
    while (!verticeStack.empty()) {
        Node *v = verticeStack.top();
        verticeStack.pop();
        if (!v->visited) {
            for (auto i = v->edgeList.begin(); i != v->edgeList.end(); i++) {
                verticeStack.push(opposite(v, *i));
            }
            std::cout << v->data << " ";
            v->visited = true;
        }
    }
    std::cout << std::endl;
    setAllUnvisited();
}

void Graph::breadthFirstTraversal(Node *n) {

}

void Graph::setAllUnvisited() {
    for (auto &i : verticeList) {
        i->visited = false;
    }
}

/*
 *  Here we create a functor class that we can use to create a priority queue for Edges
 */
class CompareEdges {
public:
    bool operator()(const Edge *e, const Edge *f) {
        /* Returns true if edge e has less weight than edge f */
        return e->weight > f->weight;
    }
};

std::vector<Edge *> Graph::primsAlgorithm() {

}

/*
 *  Here we create a functor class that we can use to create a priority queue for Nodes
 */
class CompareNodeDistance {
public:
    bool operator()(const Node *v, const Node *w) {
        /* Returns true if node v has shorter path than node w */
        return v->distance < w->distance;
    }
};

void Graph::dijkstrasAlgorithm(Node *n) {
    std::priority_queue<Node *, std::vector<Node *>, CompareNodeDistance> unvisitedNodes(verticeList.begin(),
                                                                                         verticeList.end());

    while (!unvisitedNodes.empty()) {
        // find min distance node
        Node *v = unvisitedNodes.top();
        unvisitedNodes.pop();
        v->visited = true;
        for (auto i = v->edgeList.begin(); i != v->edgeList.end(); i++) {
            Node *w = opposite(v, *i);
            if (!w->visited) {
                int dist = w->distance + (*i)->weight;
                if (dist < w->distance) {
                    w->distance = dist;
                    w->previous = v;
                }
            }
        }
    }
}

#endif // GRAPH_H
