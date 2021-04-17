#include "graph.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /* Инициализируем виджет с графикой */
        myPicture   = new MyGraphicView();
        /* и добавляем его на слой */
        ui->gridLayout->addWidget(myPicture);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   int count = ui->spinBox->value();
   myPicture->drawGraph(count, 1);
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{

}
Graph g;
void MainWindow::on_pushButton_3_clicked()
{
    int lastIndex, lastNumber;
    int count = ui->spinBox->value();
    g.addVertex(count);
    for(int i = count; i >0; i--){
        lastIndex = g.getListOfVertices().length() - i;
        lastNumber = g.getListOfVertices()[lastIndex].getNumber() + 1;
        //ui->comboBox->addItem(QString::number(g.getListOfVertices()[lastIndex].getNumber()+1));
    ui->comboBox->addItem(QString::number(lastNumber));
    ui->comboBox_2->addItem(QString::number(lastNumber));
    }
    ui->comboBox->setCurrentText(QString::number(lastNumber));
    ui->comboBox_2->setCurrentText(QString::number(lastNumber));
    lastIndex = g.getListOfVertices().length() - 1;
    lastNumber = g.getListOfVertices()[lastIndex].getNumber() + 1;
    ui->tableWidget->setRowCount(lastNumber+1);
    ui->tableWidget->setColumnCount(lastNumber+1);
}

void MainWindow::on_pushButton_2_clicked()
{
    int s = ui->comboBox->currentText().toInt();
    int e = ui->comboBox_2->currentText().toInt();
    double l = ui->doubleSpinBox->value();
    Edge edge = Edge(s, e, l);
    g.addEdge(edge);
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->doubleSpinBox->setValue(0);
    fillByGraph(ui->tableWidget, g);
}/*
void MainWindow::fillHeaders(QTableWidget *tw, Graph g){
    if(list.length()>=1){
    tw->setColumnCount(list.length());
    for(int i = 0; i < list.length(); i++){
        tw->setHorizontalHeaderItem(i, new QTableWidgetItem(list.at(i)));
    }
    }
}
*/
void MainWindow::fillByGraph(QTableWidget *tw, Graph graph){
    int lastIndex = graph.getListOfVertices().length() - 1;
    int lastNumber = graph.getListOfVertices()[lastIndex].getNumber() + 1;
    tw->setRowCount(lastNumber+1);
    tw->setColumnCount(lastNumber+1);
    //message("Увага", QString::number(lastNumber));
    foreach(Edge edge, g.getListOfEdges()){
        tw->setItem(edge.getStart().getNumber() - 1,
                    edge.getEnd().getNumber() - 1,
                    new QTableWidgetItem(QString::number(edge.getLength())));

    }

}
