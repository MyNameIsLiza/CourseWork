#include "algorithms.h"
#include "auxiliary.h"
#include "ui_algorithms.h"

Algorithms::Algorithms(Graph* g, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Algorithms)
{
    ui->setupUi(this);
    gr = g;
    ui->stackedWidget->setCurrentIndex(0);
}

Algorithms::~Algorithms()
{
    delete ui;
}
QList<int> Algorithms::degreeOfVertices(Graph* g){
    QList<int> degree;
    for(int i = 0; i < g->getListOfVertices().count(); i++)
        degree.append(0);
    foreach(Edge edge, g->getListOfEdges()){
        degree[edge.getStart().getNumber()-1] = degree.at(edge.getStart().getNumber()-1)+1;
    }
    return degree;
}
QList<Vertex> Algorithms::dijkstrasAlgorithm(Graph *g)
{
    QList<Vertex> listOfVertices;
    double** adjacencyMatrix = g->formAdjacencyMatrix();
     int ver;
     int count = g->getListOfVertices().count();
     int numOfVisited = 0;
     int minLen[count];
     Auxiliary::fillArrBy(minLen, count, 0);
     int visit[count];
     Auxiliary::fillArrBy(visit, count, 0);
    do{
         int min = INT_MAX;
         ver = INT_MAX;
         for (int i = 0; i < count; i++) {
           if (visit[i] == 0 && (minLen[i] < min && minLen[i] != 0)) {
             min = minLen[i];
             ver = i;
           }
         }

         if (min != INT_MAX && ver != INT_MAX) {
           for (int i = 0; i < count; i++) {
             if (adjacencyMatrix[ver][i] > 0) {
               if (adjacencyMatrix[ver][i] + min < minLen[i] || (minLen[i] == 0 && i != 0)) {
                 minLen[i] = adjacencyMatrix[ver][i] + min;
               }
             }
           }
           visit[ver] = 1;
         }
             numOfVisited++;
     }
    while(ver < INT_MAX);
    for (int i = 0; i < count; i++)
       listOfVertices.append(Vertex(minLen[i]));
    return listOfVertices;
}

void Algorithms::on_pushButton_2_clicked()
{
    QList<int> degree = degreeOfVertices(gr);
    ui->tableWidget->setRowCount(degree.count());
    ui->tableWidget->setColumnCount(1);
    for (int i = 0; i < degree.count(); i++)
        ui->tableWidget->setItem(i,0,
        new QTableWidgetItem(QString::number(degree[i])));
}

void Algorithms::on_pushButton_left_clicked()
{
    int current = ui->stackedWidget->currentIndex();
    //if(current!=0)
    ui->stackedWidget->setCurrentIndex(current - 1);
}

void Algorithms::on_pushButton_right_clicked()
{
    int current = ui->stackedWidget->currentIndex();
    //if(current != ui->stackedWidget->)
    ui->stackedWidget->setCurrentIndex(current + 1);
}
