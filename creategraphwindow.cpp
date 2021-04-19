#include "creategraphwindow.h"
#include "auxiliary.h"
#include "ui_creategraphwindow.h"

CreateGraphWindow::CreateGraphWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateGraphWindow)
{
    ui->setupUi(this);
    /*int t = MainWindow::g->type;
    switch(t){
        case 1: //ui->label->
        break;
        case 2: break;
    }*/
}

CreateGraphWindow::~CreateGraphWindow()
{
    delete ui;
}
//Graph g;
void CreateGraphWindow::on_pushButton_clicked()
{/*
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
    ui->tableWidget->setColumnCount(lastNumber+1);*/
}

void CreateGraphWindow::on_pushButton_2_clicked()
{/*
    int s = ui->comboBox->currentText().toInt();
    int e = ui->comboBox_2->currentText().toInt();
    double l = ui->doubleSpinBox->value();
    Edge edge = Edge(s, e, l);
    g.addEdge(edge);
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->doubleSpinBox->setValue(0);
    fillByGraph(ui->tableWidget, g);*/
}
void CreateGraphWindow::fillByGraph(QTableWidget *tw, Graph* graph){
    /*int lastIndex = graph->getListOfVertices().length() - 1;
    int lastNumber = graph->getListOfVertices()[lastIndex].getNumber() + 1;
    tw->setRowCount(lastNumber+1);
    tw->setColumnCount(lastNumber+1);
    //message("Увага", QString::number(lastNumber));
    foreach(Edge edge, graph->getListOfEdges()){
        tw->setItem(edge.getStart().getNumber() - 1,
                    edge.getEnd().getNumber() - 1,
                    new QTableWidgetItem(QString::number(edge.getLength())));
    }*/
}
