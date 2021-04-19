#include "creategraphwindow.h"
//#include "disorientedgraph.h"
#include "graph.h"
#include "mainwindow.h"
#include "orientedgraph.h"
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
        ui->comboBox->addItem("Орієнтований граф");
        ui->comboBox->addItem("Неорієнтований граф");
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
void MainWindow::on_pushButton_clicked()
{
   int count = ui->spinBox->value();
   myPicture->drawGraph(count, 1);
}

void MainWindow::on_pushButton_2_clicked()
{
    int s = ui->comboBox->currentText().toInt();
    int e = ui->comboBox_2->currentText().toInt();
    double l = ui->doubleSpinBox->value();
    Edge edge = Edge(s, e, l);
    g->addEdge(edge);
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->doubleSpinBox->setValue(0);
    //fillByGraph(ui->tableWidget, g);
}
void MainWindow::fillHeaders(QTableWidget *tw, Graph g){
    if(list.length()>=1){
    tw->setColumnCount(list.length());
    for(int i = 0; i < list.length(); i++){
        tw->setHorizontalHeaderItem(i, new QTableWidgetItem(list.at(i)));
    }
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    int type = ui->comboBox->currentIndex();
    switch(type){
        case 0: g = new OrientedGraph();break;
        //case 1: g = new DisorientedGraph() ;break;
    }
    CreateGraphWindow *cgw = new CreateGraphWindow();
    cgw->show();
    this->close();
}
*/
