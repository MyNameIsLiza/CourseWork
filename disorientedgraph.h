#ifndef DISORIENTEDGRAPH_H
#define DISORIENTEDGRAPH_H

#include "graph.h"

class DisorientedGraph : public Graph
{
public:
    DisorientedGraph();
    void addEdge(Edge e);
};

#endif // DISORIENTEDGRAPH_H
