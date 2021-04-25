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
    int lastIndex = graph->getListOfVertices().length()-1;
    int lastNumber = graph->getListOfVertices()[lastIndex].getNumber() + 1;
    tw->setRowCount(lastNumber);
    tw->setColumnCount(lastNumber);
    foreach(Edge edge, graph->getListOfEdges()){
        switch(edge.getDirection()){
        case false: tw->setItem(edge.getStart().getNumber(),
                            edge.getEnd().getNumber(),
                            new QTableWidgetItem(QString::number(edge.getLength())));
            tw->setItem(edge.getEnd().getNumber(),
                                        edge.getStart().getNumber(),
                                        new QTableWidgetItem(QString::number(edge.getLength())));
                                break;
        case true:
            tw->setItem(edge.getStart().getNumber(),
                        edge.getEnd().getNumber(),
                        new QTableWidgetItem(QString::number(edge.getLength())));
                break;
        }
    }/**/
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
