#include <iostream>
#include <vector>
#include "../Exercise03/Edge.h"
#include "Graph.h"

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

int printSum(vector<Edge *> v) {
    int sum = 0;
    for (Edge *edge : v) {
        sum += edge->weight;
    }
    return sum;
}

int main() {
    Graph graf;
    auto *e = new Node('e');
    auto *f = new Node('f');
    auto *g = new Node('g');
    auto *h = new Node('h');
    auto *i = new Node('i');

    graf.insertVertex(e);
    graf.insertVertex(f);
    graf.insertVertex(g);
    graf.insertVertex(h);
    graf.insertVertex(i);

    graf.insertEdge(e, f, 1);
    graf.insertEdge(f, g, 2);
    graf.insertEdge(e, g, 3);
    graf.insertEdge(g, h, 2);
    graf.insertEdge(i, g, 3);


    cout << "-------------------GRAF--------------------" << endl;
    printVector(graf.edges());

    cout << "-------------------BREADTH FIRST TRAVERSAL--------------------" << endl;
    graf.breadthFirstTraversal(f);
    cout << endl;

    cout << "-------------------DEPTH FIRST TRAVERSAL--------------------" << endl;
    graf.depthFirstTraversal(f);

    cout << "-------------------PRIMS ALGORITHM--------------------" << endl;
    vector<Edge *> v = graf.primsAlgorithm();
    printVector(v);
    cout << "MST weight " << printSum(v) << endl;

    cout << "-------------------DIJKSTRAS ALGORITHM--------------------" << endl;
    graf.dijkstrasAlgorithm(h);

    cout << "" << endl;

    cout << "Fjerner " << f->data << endl;
    graf.removeVertex(f);

    cout << "-------------------GRAF--------------------" << endl;
    printVector(graf.edges());
    cout << endl;


    cout << "Fjerner " << h->data << endl;
    graf.removeVertex(h);

    cout << "-------------------GRAF--------------------" << endl;
    printVector(graf.edges());
    return 0;
}