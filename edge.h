#ifndef EDGE_H
#define EDGE_H
#include "vertex.h"

class Edge
{
private:
    Vertex start;
    Vertex end;
    double length;
public:
    Edge();
    Edge(int s, int e, double l);
    Vertex getStart() const;
    void setStart(const Vertex &value);
    Vertex getEnd() const;
    void setEnd(const Vertex &value);
    double getLength() const;
    void setLength(double value);
};

#endif // EDGE_H
