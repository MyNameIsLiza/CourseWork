#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "graph.h"

#include <QMainWindow>

namespace Ui {
class Algorithms;
}

class Algorithms : public QMainWindow
{
    Q_OBJECT

public:
    explicit Algorithms(Graph* g, QWidget *parent = nullptr);
    ~Algorithms();
    static QList<Vertex> dijkstrasAlgorithm(Graph* g);
    static QList<int> degreeOfVertices(Graph* g);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_left_clicked();

    void on_pushButton_right_clicked();

private:
    Ui::Algorithms *ui;
    Graph *gr;
};

#endif // ALGORITHMS_H
