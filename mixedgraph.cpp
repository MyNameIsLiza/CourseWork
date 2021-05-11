#include "mixedgraph.h"

MixedGraph::MixedGraph()
{
    type = 3;
}
void MixedGraph::addEdge(Edge e)
{
    int i = is(e);
    if (!e.getDirection()) {
        Edge e2 = e;
        e2.setStart(e.getEnd());
        e2.setEnd(e.getStart());
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
    else{
        if(i == -1)
            listOfEdges.append(e);
        else listOfEdges[i] = e;
    }

}
