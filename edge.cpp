#include "edge.h"

Vertex Edge::getStart() const
{
    return start;
}

void Edge::setStart(const Vertex &value)
{
    start = value;
}

Vertex Edge::getEnd() const
{
    return end;
}

void Edge::setEnd(const Vertex &value)
{
    end = value;
}

double Edge::getLength() const
{
    return length;
}

void Edge::setLength(double value)
{
    length = value;
}

int Edge::getDirection() const
{
    return direction;
}

void Edge::setDirection(int value)
{
    direction = value;
}

Edge::Edge()
{
    
}

Edge::Edge(int s, int e, double l)
{
    start = s;
    end = e;
    length = l;
    direction = 0;
}
Edge::Edge(int s, int e, double l, int d)
{
    start.setNumber(s);
    end.setNumber(e);
    length = l;
    direction = d;
}
