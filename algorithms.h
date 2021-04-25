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
    static double* dijkstrasAlgorithm(Graph* g, int start);
    static double** FUAlgorithm(Graph* g);
    static QList<int> degreeOfVertices(Graph* g);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_left_clicked();

    void on_pushButton_right_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Algorithms *ui;
    Graph *gr;
};

#endif // ALGORITHMS_H
