#include "orientedgraph.h"

OrientedGraph::OrientedGraph()
{
    type = 1;
}

void OrientedGraph::addEdge(Edge e)
{
    int i = is(e);
    if(i == -1)
        listOfEdges.append(e);
    else listOfEdges[i] = e;
}
