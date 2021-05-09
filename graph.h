#ifndef GRAPH_H
#define GRAPH_H

#include "edge.h"
#include "vertex.h"
#include <QList>

class Graph
{
protected:
    QList<Edge> listOfEdges;
    QList<Vertex> listOfVertices;    
public:
    int type;//1 - орієнтований, 2 - неорієнтований
    Graph();
    QList<Edge> getListOfEdges() const;
    void setListOfEdges(const QList<Edge> &value);
    QList<Vertex> getListOfVertices() const;
    void setListOfVertices(const QList<Vertex> &value);
    void removeEdge();
    int getNewIndexForEdge();
    int getNewIndexForVertex();
    void addVertex();
    void addVertex(Vertex v);
    void addVertices(int count);
    virtual void addEdge(Edge e);
    void removeEdge(Edge e);
    int is(Edge e);
    double** formAdjacencyMatrix();
    int getType() const;
    void setType(int value);
};

#endif // GRAPH_H
