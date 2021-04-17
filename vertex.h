#ifndef VERTEX_H
#define VERTEX_H

#include <QString>



class Vertex
{
private:
    int number;

public:
    Vertex();
    Vertex(int n);
    int getNumber() const;
    void setNumber(int value);
};

#endif // VERTEX_H
