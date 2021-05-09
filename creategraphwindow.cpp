#include "creategraphwindow.h"
#include "auxiliary.h"
#include "mainwindow.h"
#include "ui_creategraphwindow.h"
#include "algorithms.h"
#include "orientedgraph.h"
#include "disorientedgraph.h"
#include <QException>
#include <QFile>
#include <QXmlStreamWriter>

CreateGraphWindow::CreateGraphWindow(Graph* g, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::CreateGraphWindow)
{
    ui->setupUi(this);

    int t = g->type;
    switch(t){
        case 1:
        gr = new OrientedGraph();
        gr = g;
        ui->label->setText("Орієнтований граф");
        ui->comboBox_4->setVisible(true);
        ui->comboBox_4->addItem("Без напрямку");
        ui->comboBox_4->addItem("До кінця");
        break;
        case 2:
        gr = new DisorientedGraph();
        gr = g;
        ui->label->setText("Неорієнтований граф");
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
    gr->addVertices(count);
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
    isAllowed = false;
    Auxiliary::tableInitialization(ui->tableWidget, lastNumber);
    isAllowed = true;
    ui->spinBox->setValue(1);
}

void CreateGraphWindow::on_pushButton_2_clicked()
{
    int s = ui->comboBox->currentText().toInt() - 1;
    int e = ui->comboBox_2->currentText().toInt() - 1;
    double l = ui->doubleSpinBox->value();
    Edge edge;
    int d = ui->comboBox_4->currentIndex();
    edge = Edge(s, e, l, d);
    gr->addEdge(edge);
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->doubleSpinBox->setValue(0);
    isAllowed = false;
    Auxiliary::fillByGraph(ui->tableWidget, gr);
    isAllowed = true;
    Auxiliary::message("new edge", QString::number(s) + " " + QString::number(e));
}

void CreateGraphWindow::on_pushButton_3_clicked()
{
    Algorithms* a = new Algorithms(gr);
    a->show();
}

void CreateGraphWindow::on_tableWidget_cellChanged(int row, int column)
{
    //if(ui->tableWidget->item(row, column)->text().compare("") == 1)
    //Auxiliary::message("4444 1", QString::number(ui->tableWidget->item(row, column)->text().compare("")));
    //Auxiliary::message("4444 2", QString::number(ui->tableWidget->item(column, row)->text().compare("")));
if(!isAllowed)return;

    int l = ui->tableWidget->item(row, column)->text().toInt();
    switch(gr->type){
        case 1:
        if(ui->tableWidget->item(row, column)->text().compare(QString::number(l))==0)
            gr->addEdge(Edge(row, column, l, 1));
        else {
            isAllowed=false;
            ui->tableWidget->item(row, column)->setText("");
            isAllowed=true;
            Edge e;
            e.setStart(row);
            e.setEnd(column);
            e.setDirection(true);
            gr->removeEdge(e);
        }
        break;
        case 2:
        Auxiliary::message("2 1", QString::number(ui->tableWidget->item(row, column)->text().compare(QString::number(l))));
        Auxiliary::message("2 2", QString::number(ui->tableWidget->item(column, row)->text().compare(QString::number(l))));
        if(ui->tableWidget->item(row, column)->text().compare(QString::number(l))==0){
            gr->addEdge(Edge(row, column, l, 2));
            isAllowed=false;
            ui->tableWidget->item(column, row)->setText(QString::number(l));
            isAllowed=true;
        }
        else {
            isAllowed=false;
            ui->tableWidget->item(row, column)->setText("");
            ui->tableWidget->item(column, row)->setText("");
            isAllowed=true;
            Edge e;
            e.setStart(row);
            e.setEnd(column);
            e.setDirection(false);
            gr->removeEdge(e);
        }
        break;
    }



    /*
    int l = ui->tableWidget->item(row, column)->text().toInt();
    if(ui->tableWidget->item(row, column)->text().compare(QString::number(l))==0)
    switch(gr->type){
        case 1:gr->addEdge(Edge(row, column, l, 1));break;
        case 2:gr->addEdge(Edge(row, column, l, 2));
        ui->tableWidget->item(column, row)->setText(QString::number(l));
        break;
    }
    else ui->tableWidget->item(row, column)->setText("");*/
}
QString filename = "C:\\Users\\Roman\\Documents\\Lizo4ka\\Cute\\CourseWork\\graph.xml";
void CreateGraphWindow::on_pushButton_write_clicked()
{
    if(gr->getType() == 1)filename = "C:\\Users\\Roman\\Documents\\Lizo4ka\\Cute\\CourseWork\\orientedgraph.xml";
    if(gr->getType() == 2)filename = "C:\\Users\\Roman\\Documents\\Lizo4ka\\Cute\\CourseWork\\disorientedgraph.xml";
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
                xmlWriter.writeAttribute("number", QString::number(v.getNumber()));
                xmlWriter.writeEndElement();
            }
            xmlWriter.writeEndElement();
            xmlWriter.writeStartElement("listOfEdges");
            foreach(Edge e, gr->getListOfEdges()){
                xmlWriter.writeStartElement("edge");
                xmlWriter.writeAttribute("start", QString::number(e.getStart().getNumber()));
                xmlWriter.writeAttribute("end", QString::number(e.getEnd().getNumber()));
                xmlWriter.writeAttribute("length", QString::number(e.getLength()));
                xmlWriter.writeAttribute("direction", QString::number(e.getDirection()));
                xmlWriter.writeEndElement();
            }
            xmlWriter.writeEndElement();
            xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();
        file.close();
    }
}

void CreateGraphWindow::on_pushButton_read_clicked()
{
    if(gr->getType() == 1)filename = "C:\\Users\\Roman\\Documents\\Lizo4ka\\Cute\\CourseWork\\orientedgraph.xml";
    if(gr->getType() == 2)filename = "C:\\Users\\Roman\\Documents\\Lizo4ka\\Cute\\CourseWork\\disorientedgraph.xml";
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Важливо", "Ви впевнені, що хочете зчитати з файлу?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::No) {
        return;
      }
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::critical(this,"Помилка",
            "Не вдалося відкрити файл",
            QMessageBox::Ok);
            return;
    }
    QXmlStreamReader xmlReader(&file);
    Graph* t;
    while(!xmlReader.atEnd() && !xmlReader.hasError()) {
        //Auxiliary::message("WHILE", "iteration");
        QXmlStreamReader::TokenType token = xmlReader.readNext();

        if(token == QXmlStreamReader::StartDocument) {
                        continue;
                }
        if(token == QXmlStreamReader::StartElement) {
        if(xmlReader.name().toString() == "type") {
            QXmlStreamAttribute a = xmlReader.attributes().at(0);
            int type = a.value().toInt();
            switch(type){
                case 1: t = new OrientedGraph();
                break;
                case 2: t = new DisorientedGraph();
                break;
            }
        }
        if(xmlReader.name().toString() == "edge") {
            //Auxiliary::message("edges", "+1");
            bool d = xmlReader.attributes().at(3).value().toInt();
            double l = xmlReader.attributes().at(2).value().toDouble();
            int e = xmlReader.attributes().at(1).value().toInt();
            int s = xmlReader.attributes().at(0).value().toInt();
            Edge edge = Edge(s, e, l, d);
            t->addEdge(edge);
        }
        if(xmlReader.name().toString() == "vertex") {
            Vertex v = Vertex(xmlReader.attributes().at(0).value().toInt());
            t->addVertex(v);
}
    }
}

    if(xmlReader.hasError()) {
            QMessageBox::critical(this,
            "xmlFile.xml Parse Error",xmlReader.errorString(),
            QMessageBox::Ok);
            return;
    }
    xmlReader.clear();
    file.close();
    gr = t;
    int lastIndex, lastNumber;
    int count = gr->getListOfVertices().count();
    for(int i = count; i > 0; i--){
        lastIndex = gr->getListOfVertices().length() - i;
        lastNumber = gr->getListOfVertices()[lastIndex].getNumber() + 1;
        ui->comboBox->addItem(QString::number(lastNumber));
        ui->comboBox_2->addItem(QString::number(lastNumber));
    }
    isAllowed = false;
    Auxiliary::fillByGraph(ui->tableWidget, gr);
    isAllowed = true;
}
