#include "fruit.h"
#include <QBrush>

Fruit::Fruit(QGraphicsItem *parent){
    // draw
    int randx=rand()%700;
    int randy=rand()%500;
    setRect(randx,randy,50,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}
