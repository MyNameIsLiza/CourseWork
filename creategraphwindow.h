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
    explicit CreateGraphWindow(Graph* g, QWidget *parent = nullptr);
    ~CreateGraphWindow();
    void setGraph(Graph* g);
private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void fillByGraph(QTableWidget *tw, Graph* graph);
    void on_CreateGraphWindow_tabifiedDockWidgetActivated(QDockWidget *dockWidget);

public slots:
private:
    Ui::CreateGraphWindow *ui;
    Graph *gr;
};

#endif // CREATEGRAPHWINDOW_H
