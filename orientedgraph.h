#ifndef ORIENTEDGRAPH_H
#define ORIENTEDGRAPH_H

#include "graph.h"

class OrientedGraph : public Graph
{

public:
    OrientedGraph();
    void addEdge(Edge e);
};

#endif // ORIENTEDGRAPH_H
