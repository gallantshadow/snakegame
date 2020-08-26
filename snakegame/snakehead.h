#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H

#include "snakebody.h"
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QList>
#include <QPointF>
#include <QObject>
#include "game.h"

class SnakeHead:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    // constructors
    SnakeHead(QGraphicsItem* parent=nullptr);

    // events
    void keyPressEvent(QKeyEvent* event);

    // public method
    void elongate();
    void moveBodies();
    void go();
    void detectcollision();
public slots:
    void move();
private:
    QList<SnakeBody*> snakeBodies;
    QPointF prevPos;


};

#endif // SNAKEHEAD_H
