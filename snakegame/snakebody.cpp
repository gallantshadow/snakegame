#include "SnakeBody.h"
#include <QBrush>

SnakeBody::SnakeBody(QGraphicsItem *parent){
    // draw
    setRect(400,300,50,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}
