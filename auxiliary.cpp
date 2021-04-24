#include "auxiliary.h"



Auxiliary::Auxiliary()
{

}

void Auxiliary::message(QString title, QString text)
{
    QMessageBox msgbox;
    msgbox.setWindowTitle(title);
    msgbox.setText(text);
    msgbox.exec();
}

void Auxiliary::fillByGraph(QTableWidget *tw, Graph *graph){
    int lastIndex = graph->getListOfVertices().length() - 1;
    int lastNumber = graph->getListOfVertices()[lastIndex].getNumber() + 1;
    tw->setRowCount(lastNumber);
    tw->setColumnCount(lastNumber);
    foreach(Edge edge, graph->getListOfEdges()){
        switch(edge.getDirection()){
        case 0: tw->setItem(edge.getStart().getNumber() - 1,
                            edge.getEnd().getNumber() - 1,
                            new QTableWidgetItem(QString::number(edge.getLength())));
            tw->setItem(edge.getEnd().getNumber() - 1,
                                        edge.getStart().getNumber() - 1,
                                        new QTableWidgetItem(QString::number(edge.getLength())));
                                break;
        case 1:
            tw->setItem(edge.getStart().getNumber() - 1,
                        edge.getEnd().getNumber() - 1,
                        new QTableWidgetItem(QString::number(edge.getLength())));
                break;
        }
    }
}

void Auxiliary::fillArrBy(int* arr, int count, int o)
{
    for(int i = 0; i < count; i++){
        arr[i] = o;
    }
}

void Auxiliary::fillArrBy(double **arr, int count, int o)
{
    for(int i = 0; i < count; i++){
        for(int j = 0; j < count; j++){
            arr[i][j] = o;
        }
}
}
