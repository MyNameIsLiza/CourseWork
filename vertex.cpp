#include "vertex.h"

int Vertex::getNumber() const
{
    return number;
}

void Vertex::setNumber(int value)
{
    number = value;
}

Vertex::Vertex()
{

}

Vertex::Vertex(int n)
{
    number = n;
}
