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

