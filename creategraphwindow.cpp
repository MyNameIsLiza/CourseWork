#include "creategraphwindow.h"
#include "auxiliary.h"
#include "mainwindow.h"
#include "ui_creategraphwindow.h"
#include "algorithms.h"
#include <QException>
#include <QFile>
#include <QXmlStreamWriter>

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
        break;
        case 2: ui->label->setText("Неорієнтований граф");
        ui->comboBox_4->setVisible(false);
        break;
    }
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
    for(int i = count; i > 0; i--){
        lastIndex = gr->getListOfVertices().length() - i;
        lastNumber = gr->getListOfVertices()[lastIndex].getNumber() + 1;
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
    }

    gr->addEdge(edge);
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->doubleSpinBox->setValue(0);
    Auxiliary::fillByGraph(ui->tableWidget, gr);
}

void CreateGraphWindow::on_pushButton_3_clicked()
{
    Algorithms* a = new Algorithms(gr);
    a->show();
}

void CreateGraphWindow::on_tableWidget_cellChanged(int row, int column)
{
    int l = ui->tableWidget->item(row, column)->text().toInt();
    if(ui->tableWidget->item(row, column)->text().compare(QString::number(l))==0)
    gr->addEdge(Edge(row + 1, column + 1, l, 1));
    else ui->tableWidget->item(row, column)->setText("");
}
QString filename = "C:\\Users\\Roman\\Documents\\Lizo4ka\\Cute\\CourseWork\\graph.xml";
void CreateGraphWindow::on_pushButton_write_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Важливо", "Ви впевнені, що хочете переписати файл?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::No) {
        return;
      }
    QFile file(filename);
    if( !file.open(QIODevice::WriteOnly) ) {
        Auxiliary::message( "Помилка","Не вдалось відкрити/створити файл на запис");
        return;
    } else {
        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
            xmlWriter.writeStartElement("Graph");
            xmlWriter.writeStartElement("type");
            xmlWriter.writeAttribute("QString", QString::number(gr->getType()));
            xmlWriter.writeEndElement();
            xmlWriter.writeStartElement("listOfVerices");
            foreach(Vertex v, gr->getListOfVertices()){
                xmlWriter.writeStartElement("vertex");
                xmlWriter.writeStartElement("number");
                xmlWriter.writeAttribute("QString", QString::number(v.getNumber()));
                xmlWriter.writeEndElement();
                xmlWriter.writeEndElement();
            }
            xmlWriter.writeEndElement();
            xmlWriter.writeStartElement("listOfEdges");
            foreach(Edge e, gr->getListOfEdges()){
                xmlWriter.writeStartElement("edge");
                xmlWriter.writeStartElement("start");
                xmlWriter.writeAttribute("QString", QString::number(e.getStart().getNumber()));
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("end");
                xmlWriter.writeAttribute("QString", QString::number(e.getEnd().getNumber()));
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("length");
                xmlWriter.writeAttribute("QString", QString::number(e.getLength()));
                xmlWriter.writeEndElement();
                xmlWriter.writeEndElement();
            }
            xmlWriter.writeEndElement();
            xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();
        file.close();
    }
}
