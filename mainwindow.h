#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "auxiliary.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Graph *g;
public slots:
private slots:


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    MyGraphicView *myPicture;


};
#endif // MAINWINDOW_H
