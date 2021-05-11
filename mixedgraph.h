#ifndef MIXEDGRAPH_H
#define MIXEDGRAPH_H

#include "graph.h"

class MixedGraph : public Graph
{
public:
    MixedGraph();
    void addEdge(Edge e) override;
};

#endif // MIXEDGRAPH_H
