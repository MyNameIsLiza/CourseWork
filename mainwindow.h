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
    static Graph* g;

private slots:


private:
    Ui::MainWindow *ui;
    MyGraphicView *myPicture;

};
#endif // MAINWINDOW_H
