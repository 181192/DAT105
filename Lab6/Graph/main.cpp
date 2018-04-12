#include <iostream>
#include "graph.h"

using namespace std;

std::ostream &operator<<(std::ostream &os, const Edge *e) {
    os << "(" << e->endpoint[0]->data << ", " << e->endpoint[1]->data << ")";
    return os;
}

template<class T>
void printVector(vector<T> v) {
    for (auto i = v.begin(); i != v.end(); i++) {
        cout << *i << endl;
    }
}

int main() {
    Graph graf;
    auto *e = new Node('e');
    auto *f = new Node('f');
    auto g = new Node('g');
    auto *h = new Node('h');

    graf.insertVertex(e);
    graf.insertVertex(f);
    graf.insertVertex(g);
    graf.insertVertex(h);

    graf.insertEdge(e, f, 1);
    graf.insertEdge(f, g, 2);
    graf.insertEdge(e, g, 3);
    graf.insertEdge(g, h, 2);

    graf.depthFirstTraversal(f);
    graf.breadthFirstTraversal(f);
    vector<Edge *> v = graf.primsAlgorithm();
    printVector(v);
    graf.dijkstrasAlgorithm(e);

    return 0;
}

