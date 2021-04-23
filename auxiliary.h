#ifndef AUXILIARY_H
#define AUXILIARY_H

#include <QString>
#include <QMessageBox>
#include "graph.h"
#include <QMainWindow>
#include <QTableWidget>
#include "edge.h"
#include "vertex.h"
#include <QList>
#include <mygraphicview.h>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>


class Auxiliary
{
public:
    Auxiliary();
    static void message(QString title, QString text);
    static void fillByGraph(QTableWidget *tw, Graph* graph);
};

#endif // AUXILIARY_H
