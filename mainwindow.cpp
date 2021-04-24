#include "creategraphwindow.h"
#include "disorientedgraph.h"
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

void MainWindow::on_pushButton_clicked()
{
    int type = ui->comboBox->currentIndex();
    switch(type){
        case 0:
        g = new OrientedGraph();
        break;
        case 1:        
        g = new DisorientedGraph();
        break;
    default: g = new OrientedGraph(); break;
    }
    //Auxiliary::message("", QString::number(INT_MAX));
    CreateGraphWindow *cgw = new CreateGraphWindow(g);    
    cgw->show();
    this->close();/**/
}
