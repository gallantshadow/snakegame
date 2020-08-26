#include "snakehead.h"
#include <QBrush>
#include "fruit.h"
#include "snakebody.h"
#include "game.h"
#include "QDebug"
#include "QTimer"

extern Game* game;

SnakeHead::SnakeHead(QGraphicsItem *parent){

    // draw
    setRect(400,300,50,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);

    // make focusable
    setFlag(QGraphicsItem::ItemIsFocusable,true);

    // TODO remove, test
    SnakeBody* b1 = new SnakeBody();
    b1->setPos(51,0);
    game->scene->addItem(b1);
    snakeBodies.prepend(b1);
    QTimer * timer =new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(600);


}

void SnakeHead::keyPressEvent(QKeyEvent *event){
    // move up
    if (event->key() == Qt::Key_Up){

        prevPos = pos();
        int xPos = x();
        int yPos = y() - boundingRect().height();
        setPos(xPos,yPos);
        moveBodies();
    }

    // move down
    if (event->key() == Qt::Key_Down){
        prevPos = pos();
        int xPos = x();
        int yPos = y() + boundingRect().height();
        setPos(xPos,yPos);
        moveBodies();
    }

    // move right
    if (event->key() == Qt::Key_Right){

        prevPos = pos();
        int xPos = x() + boundingRect().width();
        int yPos = y();
        setPos(xPos,yPos);
        moveBodies();
    }

    // move left
    if (event->key() == Qt::Key_Left){
        prevPos = pos();
        int xPos = x() - boundingRect().width();
        int yPos = y();
        setPos(xPos,yPos);
        moveBodies();
    }

    // elongate if collides with Fruit
   detectcollision();
}

void SnakeHead::elongate(){
    // add new SnakeBody to list
    SnakeBody* body = new SnakeBody();
    snakeBodies.prepend(body);

    // properly position the body
    body->setPos(snakeBodies[snakeBodies.size()-1]->pos()); // TODO
    game->scene->addItem(body);
}

void SnakeHead::moveBodies(){
    // traverses through list of bodies and moves them properly

    // move all bodies from back to front
    for (int i = 0, n = snakeBodies.size()-1; i < n; ++i){
        qDebug() <<snakeBodies.size()<<" ";
        snakeBodies[i]->setPos(snakeBodies[i+1]->pos());
    }

    // move front body to previous position of head
    snakeBodies.last()->setPos(prevPos);
}



void SnakeHead::move()
{

 if(prevPos.rx()<x())
 {
     prevPos = pos();
     int xPos = x() + boundingRect().width();
     int yPos = y();
     setPos(xPos,yPos);
     moveBodies();

 }
 if(prevPos.rx()>x())
 {
     prevPos = pos();
     int xPos = x() - boundingRect().width();
     int yPos = y();
     setPos(xPos,yPos);
     moveBodies();
 }
 if (prevPos.ry()>y()){

     prevPos = pos();
     int xPos = x();
     int yPos = y() - boundingRect().height();
     setPos(xPos,yPos);
     moveBodies();
 }

 // move down
 if (prevPos.ry()<y()){
     prevPos = pos();
     int xPos = x();
     int yPos = y() + boundingRect().height();
     setPos(xPos,yPos);
     moveBodies();
 }
detectcollision();
}

void SnakeHead::detectcollision(){
    QList<QGraphicsItem*> cItems = collidingItems();
    for (int i = 0, n = cItems.size(); i < n; ++i){
        if (typeid(*cItems[i]) == typeid(Fruit)){
            scene()->removeItem(cItems[i]);
            delete cItems[i];
            Fruit* f1 = new Fruit();
            scene()->addItem(f1);

            // fruit found in collision list
            elongate();
        }
        else if (typeid(*cItems[i]) == typeid(SnakeBody)) {
            game->scene->clear();
            game->start();


        }
    }
}
