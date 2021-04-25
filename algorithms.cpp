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
    int count = gr->getListOfVertices().length();
    int lastIndex, lastNumber;
    for(int i = count; i > 0; i--){
        lastIndex = gr->getListOfVertices().length() - i;
        lastNumber = gr->getListOfVertices()[lastIndex].getNumber() + 1;
        ui->comboBox->addItem(QString::number(lastNumber));
    }
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Степінь"));
    ui->tableWidget_2->setColumnCount(1);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setHorizontalHeaderItem(0, new QTableWidgetItem("Найкоротший шлях"));
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
        degree[edge.getStart().getNumber()] = degree.at(edge.getStart().getNumber())+1;
    }
    return degree;
}
double* Algorithms::dijkstrasAlgorithm(Graph *g, int start)
{
    int count = g->getListOfVertices().count();
    double* D = new double[count];
    double** adjacencyMatrix = g->formAdjacencyMatrix();
    bool visit[count];    
    for(int i=0;i<count;i++)
        {
            D[i]=adjacencyMatrix[start][i];
            visit[i]=false;
        }
    D[start]=0;
    visit[start]=true;
    int current;
    double min;
    do{
      current = -1;
      min = INT_MAX;
    for(int i = 0; i < count; i++){
        if(D[i]< min && !visit[i]){
            min = D[i];
            current = i;
        }
    }
    //Auxiliary::message("current", QString::number(current+1));
    visit[current] = true;
    if(current == -1){
        //for (int i = 0;i < count;i++)
          //  Auxiliary::message("D"+QString::number(i+1), QString::number(D[i]));

        return D;
    }
    foreach(Edge e, g->getListOfEdges()){
        if(e.getStart().getNumber() == current && !visit[e.getEnd().getNumber()]
                && D[current] + e.getLength() < D[e.getEnd().getNumber()]){
            D[e.getEnd().getNumber()] = D[current] + e.getLength();
        }
    }
    }
    while(current!=-1);
    return D;
}

void Algorithms::on_pushButton_2_clicked()
{
    QList<int> degree = degreeOfVertices(gr);
    ui->tableWidget->setRowCount(degree.count());    
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

void Algorithms::on_pushButton_clicked()
{
    int count = gr->getListOfVertices().count();
    int s = ui->comboBox->currentText().toInt() - 1;
    double* D = dijkstrasAlgorithm(gr, s);
    ui->tableWidget_2->setRowCount(count);
    //ui->tableWidget_2->setItem(0,0, new QTableWidgetItem(QString::number(D[0])));
    for (int i = 0;i < count;i++)
        if(D[i]!= INT_MAX)
        ui->tableWidget_2->setItem(i,0,
        new QTableWidgetItem(QString::number(D[i])));
    else ui->tableWidget_2->setItem(i,0,
                                    new QTableWidgetItem("∞"));
    /**/
}
