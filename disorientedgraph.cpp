#include "disorientedgraph.h"

DisorientedGraph::DisorientedGraph()
{

}

void DisorientedGraph::addEdge(Edge e)
{
    Edge e2;
    e2.setStart(e.getEnd());
    e2.setEnd(e.getStart());
    int i = is(e);
    if(i == -1){
        listOfEdges.append(e);
        listOfEdges.append(e2);
    }
    else {
        listOfEdges[i] = e;
        i = is(e2);
        listOfEdges[i] = e2;
    }
}

