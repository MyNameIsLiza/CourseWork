#ifndef EDGE_H
#define EDGE_H
#include "vertex.h"

class Edge
{
private:
    Vertex start;
    Vertex end;
    double length;
    int direction;//0 - без напрямку, 1 - до кінця

public:
    Edge();
    Edge(int s, int e, double l);
    Edge(int s, int e, double l, int d);
    Vertex getStart() const;
    void setStart(const Vertex &value);
    Vertex getEnd() const;
    void setEnd(const Vertex &value);
    double getLength() const;
    void setLength(double value);
    int getDirection() const;
    void setDirection(int value);
};

#endif // EDGE_H
