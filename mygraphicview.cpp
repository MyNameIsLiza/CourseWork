#include "mygraphicview.h"

#include <QPointF>
#include <QRectF>
#include <QWidget>
#include <QMessageBox>

MyGraphicView::MyGraphicView(QWidget *parent)
    : QGraphicsView(parent)
{

    /* Немного поднастроим отображение виджета и его содержимого */
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    this->setAlignment(Qt::AlignCenter);                        // Делаем привязку содержимого к центру
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету

    /* Также зададим минимальные размеры виджета
     * */
    this->setMinimumHeight(100);
    this->setMinimumWidth(100);

    scene = new QGraphicsScene();   // Инициализируем сцену для отрисовки
    this->setScene(scene);          // Устанавливаем сцену в виджет

    group_1 = new QGraphicsItemGroup(); // Инициализируем первую группу элементов
    group_2 = new QGraphicsItemGroup(); // Инициализируем вторую группу элементов

    scene->addItem(group_1);            // Добавляем первую группу в сцену
    scene->addItem(group_2);            // Добавляем вторую группу в сцену

    timer = new QTimer();               // Инициализируем Таймер
    timer->setSingleShot(true);
    // Подключаем СЛОТ для отрисовки к таймеру
    connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
    timer->start(50);                   // Стартуем таймер на 50 миллисекунд
}

MyGraphicView::~MyGraphicView()
{

}

void MyGraphicView::drawGraph(int count){
    this->deleteItemsFromGroup(group_1);
    this->deleteItemsFromGroup(group_2);
    double R = 25;double border = R;
    int width = this->width();
    int height = this->height();
    QGraphicsTextItem *text;

    scene->setSceneRect(0,0,width,height);
    QPen penBlack(Qt::black);
    QPen penRed(Qt::red);
    double left, top;
    left = border;
    top = height/2;
    group_1->addToGroup(scene->addEllipse(QRectF(left, top, R, R)));
    text = scene->addText("1");
    text->setPos(left + R/4, top + R/4);
    double hH = (height -2*border)/count*1.9, hW = (width -2*border)/count*1.9;
    //QMessageBox::warning(this, "Увага","hH = " + QString::number(hH) + "hW = " + QString::number(hW));
    int i = 0;
    if(count%2 == 0){
        for(i = 1; i < count/4; i++){
            left += hW;
            top += hH;
            group_1->addToGroup(scene->addEllipse(QRectF(left, top, R, R)));
            text = scene->addText(QString::number(i+1));
            text->setPos(left + R/4, top + R/4);
            group_1->addToGroup(text);
    //QMessageBox::warning(this, "Увага",QString::number(i+1)+"left = " + QString::number(left) + "top = " + QString::number(top));
        }
        top += 2*hH;
        for(i = count/4; i < count/2; i++){
            left += hW;
            //if(left < border)
            //left += hW;
            top -= hH;
            //if(top > height - border)
            //top -= hH;
            group_1->addToGroup(scene->addEllipse(QRectF(left, top, R, R)));
            text = scene->addText(QString::number(i+1));
            text->setPos(left + R/4, top + R/4);
            group_1->addToGroup(text);
    //QMessageBox::warning(this, "Увага",QString::number(i+1)+"left = " + QString::number(left) + "top = " + QString::number(top));
        }
        left = border;
        top = height/2;
        for(i = count/2; i < count*3/4; i++){
            /*left -= hW;
            if(left < border)
            left += 2*hW;*/
            left += hW;
            //if(left > width - border)
            //left -= hW;
            top -= hH;
            //if(top < border)
            //top += hH;
            group_1->addToGroup(scene->addEllipse(QRectF(left, top, R, R)));
            text = scene->addText(QString::number(i+1));
            text->setPos(left + R/4, top + R/4);
            group_1->addToGroup(text);
    //QMessageBox::warning(this, "Увага",QString::number(i+1)+"left = " + QString::number(left) + "top = " + QString::number(top));
        }
        //top -= 2*hH;
        for(i = count*3/4; i < count; i++){
            left += hW;
            //if(left < border)
            //left += hW;
            top += hH;
            //if(top > height - border)
            //top -= hH;
            group_1->addToGroup(scene->addEllipse(QRectF(left, top, R, R)));
            text = scene->addText(QString::number(i+1));
            text->setPos(left + R/4, top + R/4);
            group_1->addToGroup(text);
    //QMessageBox::warning(this, "Увага",QString::number(i+1)+"left = " + QString::number(left) + "top = " + QString::number(top));
        }
}else{
        for(i = 1; i < count/4; i++){
            left += hW;
            //if(left > width - border)
            //left -= hW;
            top += hH;
                //if(top > height - border)
            //top -= 2*hH;
            group_1->addToGroup(scene->addEllipse(QRectF(left, top, R, R)));
            text = scene->addText(QString::number(i+1));
            text->setPos(left + R/4, top + R/4);
            group_1->addToGroup(text);
    //QMessageBox::warning(this, "Увага",QString::number(i+1)+"left = " + QString::number(left) + "top = " + QString::number(top));
        }
        top += 2*hH;
        for(i = count/4; i < count/2; i++){
            left += hW;
            //if(left < border)
            //left += hW;
            top -= hH;
            //if(top > height - border)
            //top -= hH;
            group_1->addToGroup(scene->addEllipse(QRectF(left, top, R, R)));
            text = scene->addText(QString::number(i+1));
            text->setPos(left + R/4, top + R/4);
            group_1->addToGroup(text);
    //QMessageBox::warning(this, "Увага",QString::number(i+1)+"left = " + QString::number(left) + "top = " + QString::number(top));
        }
        left = border;
        top = height/2;
        for(i = count/2; i < count*3/4; i++){
            /*left -= hW;
            if(left < border)
            left += 2*hW;*/
            left += hW;
            //if(left > width - border)
            //left -= hW;
            top -= hH;
            //if(top < border)
            //top += hH;
            group_1->addToGroup(scene->addEllipse(QRectF(left, top, R, R)));
            text = scene->addText(QString::number(i+1));
            text->setPos(left + R/4, top + R/4);
            group_1->addToGroup(text);
    //QMessageBox::warning(this, "Увага",QString::number(i+1)+"left = " + QString::number(left) + "top = " + QString::number(top));
        }
        //top -= 2*hH;
        for(i = count*3/4; i < count - 1; i++){
            left += hW;
            //if(left < border)
            //left += hW;
            top += hH;
            //if(top > height - border)
            //top -= hH;
            group_1->addToGroup(scene->addEllipse(QRectF(left, top, R, R)));
            text = scene->addText(QString::number(i+1));
            text->setPos(left + R/4, top + R/4);
            group_1->addToGroup(text);
    //QMessageBox::warning(this, "Увага",QString::number(i+1)+"left = " + QString::number(left) + "top = " + QString::number(top));
        }
        group_1->addToGroup(scene->addEllipse(QRectF(width/2, height/2, R, R)));
        text = scene->addText(QString::number(count));
        text->setPos(width/2 + R/4, height/2 + R/4);
    }
    //QMessageBox::warning(this, "Увага","і = " + QString::number(i));
}
void MyGraphicView::drawGraph(int count, int o){
    this->deleteItemsFromGroup(group_1);
    this->deleteItemsFromGroup(group_2);
    double R = 25;double border = R;
    int width = this->width();
    int height = this->height();
    QGraphicsTextItem *text;

    scene->setSceneRect(0,0,width,height);
    QPen penBlack(Qt::black);
    QPen penRed(Qt::red);
    double left, top;
    left = border;
    top = height/2;
    group_1->addToGroup(scene->addEllipse(QRectF(left, top, R, R)));
    text = scene->addText("1");
    text->setPos(left + R/4, top + R/4);
    double hH = (height -2*border)/count*1.9, hW = (width -2*border)/count*1.9;
    int i = 0;
    if(count%2 == 0){
        for(i = 1; i < count/4; i++){
            left += hW;
            top += hH;
            group_1->addToGroup(scene->addEllipse(QRectF(left, top, R, R)));
            text = scene->addText(QString::number(i+1));
            text->setPos(left + R/4, top + R/4);
            group_1->addToGroup(text);
    }
        top += 2*hH;
        for(i = count/4; i < count/2; i++){
            left += hW;
            top -= hH;
            group_1->addToGroup(scene->addEllipse(QRectF(left, top, R, R)));
            text = scene->addText(QString::number(i+1));
            text->setPos(left + R/4, top + R/4);
            group_1->addToGroup(text);
    }
        left = border;
        top = height/2;
        for(i = count/2; i < count*3/4; i++){
            left += hW;
            top -= hH;
            group_1->addToGroup(scene->addEllipse(QRectF(left, top, R, R)));
            text = scene->addText(QString::number(i+1));
            text->setPos(left + R/4, top + R/4);
            group_1->addToGroup(text);
        }
        for(i = count*3/4; i < count; i++){
            left += hW;
            top += hH;
            group_1->addToGroup(scene->addEllipse(QRectF(left, top, R, R)));
            text = scene->addText(QString::number(i+1));
            text->setPos(left + R/4, top + R/4);
            group_1->addToGroup(text);
    }
}else{
        for(i = 1; i < count/4; i++){
            left += hW;
            top += hH;
            group_1->addToGroup(scene->addEllipse(QRectF(left, top, R, R)));
            text = scene->addText(QString::number(i+1));
            text->setPos(left + R/4, top + R/4);
            group_1->addToGroup(text);
     }
        top += 2*hH;
        for(i = count/4; i < count/2; i++){
            left += hW;
            top -= hH;
            group_1->addToGroup(scene->addEllipse(QRectF(left, top, R, R)));
            text = scene->addText(QString::number(i+1));
            text->setPos(left + R/4, top + R/4);
            group_1->addToGroup(text);
     }
        left = border;
        top = height/2;
        for(i = count/2; i < count*3/4; i++){
            left += hW;
            top -= hH;
            group_1->addToGroup(scene->addEllipse(QRectF(left, top, R, R)));
            text = scene->addText(QString::number(i+1));
            text->setPos(left + R/4, top + R/4);
            group_1->addToGroup(text);
     }
        for(i = count*3/4; i < count - 1; i++){
            left += hW;
            top += hH;
            group_1->addToGroup(scene->addEllipse(QRectF(left, top, R, R)));
            text = scene->addText(QString::number(i+1));
            text->setPos(left + R/4, top + R/4);
            group_1->addToGroup(text);
     }
        group_1->addToGroup(scene->addEllipse(QRectF(width/2, height/2, R, R)));
        text = scene->addText(QString::number(count));
        text->setPos(width/2 + R/4, height/2 + R/4);
        group_1->addToGroup(text);
        group_1->addToGroup(scene->addLine(border + R, height/2 + R/2,width/2, height/2 + R/2, penBlack));
    }
}
void MyGraphicView::slotAlarmTimer()
{/*

    this->deleteItemsFromGroup(group_1);
    this->deleteItemsFromGroup(group_2);

    int width = this->width();
    int height = this->height();
    scene->setSceneRect(0,0,width,height);

    QPen penBlack(Qt::black); // Задаём чёрную кисть
    QPen penRed(Qt::red);   // Задаём красную кисть



    //group_1->addToGroup(scene->addEllipse(QRectF(20, 20, height-40, height - 40)));
    group_1->addToGroup(scene->addEllipse(QRectF(100, 100, 25, 25)));
    QGraphicsTextItem *text = scene->addText("1");
    text->setPos(103.5, 103.5);
    group_1->addToGroup(text);

    int sideOfSquare = (height > width) ? (width - 60) : (height - 60);
    int centerOfWidget_X = width/2;
    int centerOfWidget_Y = height/2;

    group_2->addToGroup(scene->addLine(centerOfWidget_X - (sideOfSquare/2),
                                       centerOfWidget_Y - (sideOfSquare/2),
                                       centerOfWidget_X + (sideOfSquare/2),
                                       centerOfWidget_Y - (sideOfSquare/2),
                                       penRed));

    group_2->addToGroup(scene->addLine(centerOfWidget_X + (sideOfSquare/2),
                                       centerOfWidget_Y - (sideOfSquare/2),
                                       centerOfWidget_X + (sideOfSquare/2),
                                       centerOfWidget_Y + (sideOfSquare/2),
                                       penRed));

    group_2->addToGroup(scene->addLine(centerOfWidget_X + (sideOfSquare/2),
                                       centerOfWidget_Y + (sideOfSquare/2),
                                       centerOfWidget_X - (sideOfSquare/2),
                                       centerOfWidget_Y + (sideOfSquare/2),
                                       penRed));

    group_2->addToGroup(scene->addLine(centerOfWidget_X - (sideOfSquare/2),
                                       centerOfWidget_Y + (sideOfSquare/2),
                                       centerOfWidget_X - (sideOfSquare/2),
                                       centerOfWidget_Y - (sideOfSquare/2),
                                       penRed));*/

}
/* Этим методом перехватываем событие изменения размера виджет
 * */
void MyGraphicView::resizeEvent(QResizeEvent *event)
{
    timer->start(50);   // Как только событие произошло стартуем таймер для отрисовки
    QGraphicsView::resizeEvent(event);  // Запускаем событие родителького класса
}


/* Метод для удаления всех элементов из группы
 * */
void MyGraphicView::deleteItemsFromGroup(QGraphicsItemGroup *group)
{
    /* Перебираем все элементы сцены, и если они принадлежат группе,
     * переданной в метод, то удаляем их
     * */
    foreach( QGraphicsItem *item, scene->items(group->boundingRect())) {
       if(item->group() == group ) {
          delete item;
       }
    }
}
