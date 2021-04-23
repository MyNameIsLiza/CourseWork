#include "creategraphwindow.h"
#include "auxiliary.h"
#include "mainwindow.h"
#include "ui_creategraphwindow.h"

#include <QException>

CreateGraphWindow::CreateGraphWindow(Graph* g, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::CreateGraphWindow)
{
    ui->setupUi(this);
    gr = g;
    int t = gr->type;
    switch(t){
        case 1: ui->label->setText("Орієнтований граф");
        ui->comboBox_4->setVisible(true);
        ui->comboBox_4->addItem("Без напрямку");
        ui->comboBox_4->addItem("До кінця");
        //ui->comboBox_4->addItem("До початку");
        //ui->comboBox_4->addItem("В обидві сторони");

        //ui->horizontalLayout->addItem(new QLayoutItem());
        break;
        case 2: ui->label->setText("Неорієнтований граф");
        ui->comboBox_4->setVisible(false);
        break;
    }
    ui->comboBox_3->addItem("Алгоритм Дейстри");
}

CreateGraphWindow::~CreateGraphWindow()
{
    delete ui;
}
void CreateGraphWindow::setGraph(Graph* g){
    gr = g;
}
void CreateGraphWindow::on_pushButton_clicked()
{
    int lastIndex, lastNumber;
    int count = ui->spinBox->value();
    gr->addVertex(count);
    for(int i = count; i >0; i--){
        lastIndex = gr->getListOfVertices().length() - i;
        lastNumber = gr->getListOfVertices()[lastIndex].getNumber() + 1;
        //ui->comboBox->addItem(QString::number(g.getListOfVertices()[lastIndex].getNumber()+1));
    ui->comboBox->addItem(QString::number(lastNumber));
    ui->comboBox_2->addItem(QString::number(lastNumber));
    }
    ui->comboBox->setCurrentText(QString::number(lastNumber));
    ui->comboBox_2->setCurrentText(QString::number(lastNumber));
    lastIndex = gr->getListOfVertices().length() - 1;
    lastNumber = gr->getListOfVertices()[lastIndex].getNumber() + 1;
    ui->tableWidget->setRowCount(lastNumber);
    ui->tableWidget->setColumnCount(lastNumber);
    ui->spinBox->setValue(1);
}

void CreateGraphWindow::on_pushButton_2_clicked()
{
    int s = ui->comboBox->currentText().toInt();
    int e = ui->comboBox_2->currentText().toInt();
    double l = ui->doubleSpinBox->value();
    Edge edge;
    switch(gr->type){
    case 1: int d = ui->comboBox_4->currentIndex();
        edge = Edge(s, e, l, d);
    break;
    //case 2: edge = Edge(s, e, l);
    //break;
    }

    gr->addEdge(edge);
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->doubleSpinBox->setValue(0);
    Auxiliary::fillByGraph(ui->tableWidget, gr);
}




void CreateGraphWindow::on_pushButton_3_clicked()
{

}

void CreateGraphWindow::on_tableWidget_cellChanged(int row, int column)
{
    int l = ui->tableWidget->item(row, column)->text().toInt();
    gr->addEdge(Edge(row + 1, column + 1, l, 1));
    /*
    Edge edge;
        int l = ui->tableWidget->item(row, column)->text().toInt();
        Auxiliary::message("text", QString::number(ui->tableWidget->item(row, column)->text().compare("0")));
        Auxiliary::message("l", QString::number(QString::number(l).compare("0")));
        if(QString::number(l).compare("0")==0 && ui->tableWidget->item(row, column)->text().compare("0")!=-1)
        {
            Auxiliary::message("l", QString::number(l));
            ui->tableWidget->setItem(row, column, new QTableWidgetItem(0));
            edge = Edge(row + 1, column + 1, 0, 1);
        }else edge = Edge(row + 1, column + 1, l, 1);
        gr->addEdge(edge);*/
}
