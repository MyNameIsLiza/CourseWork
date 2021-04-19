#ifndef ORIENTEDGRAPH_H
#define ORIENTEDGRAPH_H

#include "graph.h"

class OrientedGraph : public Graph
{
protected: int direction;//0 - до кінця, 1 - до початку, 2 - в обидві сторони
public:
    OrientedGraph();
    void addEdge(Edge e);
    int getDirection() const;
    void setDirection(int value);
};

#endif // ORIENTEDGRAPH_H
