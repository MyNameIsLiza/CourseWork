#ifndef CREATEGRAPHWINDOW_H
#define CREATEGRAPHWINDOW_H

#include "auxiliary.h"
#include "mainwindow.h"
#include <QMainWindow>
#include <QTableWidget>

namespace Ui {
class CreateGraphWindow;
}

class CreateGraphWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateGraphWindow(QWidget *parent = nullptr);
    ~CreateGraphWindow();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void fillByGraph(QTableWidget *tw, Graph* graph);

private:
    Ui::CreateGraphWindow *ui;
};

#endif // CREATEGRAPHWINDOW_H
