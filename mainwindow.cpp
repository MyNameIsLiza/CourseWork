#include "creategraphwindow.h"
#include "disorientedgraph.h"
#include "graph.h"
#include "mainwindow.h"
#include "orientedgraph.h"
#include "mixedgraph.h"
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
        ui->comboBox->addItem("Змішаний граф");
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
        case 2:
        g = new MixedGraph();

        break;
        default: g = new OrientedGraph(); break;
    }
    CreateGraphWindow *cgw = new CreateGraphWindow(g);    
    cgw->show();
    this->close();/**/
}
