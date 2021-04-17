#ifndef GRAPH_H
#define GRAPH_H

#include "edge.h"
#include "vertex.h"
#include <QList>

class Graph
{
private:
    QList<Edge> listOfEdges;
    QList<Vertex> listOfVertices;

public:
    Graph();
    QList<Edge> getListOfEdges() const;
    void setListOfEdges(const QList<Edge> &value);
    QList<Vertex> getListOfVertices() const;
    void setListOfVertices(const QList<Vertex> &value);
    void removeEdge();
    int getNewIndexForEdge();
    int getNewIndexForVertex();
    void addVertex();
    void addVertex(int count);
    void addEdge(Edge e);
    int is(Edge e);
};

#endif // GRAPH_H
