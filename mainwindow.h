#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "graph.h"

#include <QMainWindow>
#include <QTableWidget>
#include <mygraphicview.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void fillByGraph(QTableWidget *tw, Graph g);
private:
    Ui::MainWindow *ui;
    MyGraphicView *myPicture;
};
#endif // MAINWINDOW_H
