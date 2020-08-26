#include "game.h"
#include "fruit.h"
#include "snakehead.h"
Game::Game(QWidget *parent): QGraphicsView(parent)
{
    // set the scene
        scene = new QGraphicsScene(0,0,800,600);
        setScene(scene);

}

void Game::start(){
    // create snakeHead
    SnakeHead* snakeHead = new SnakeHead();
    scene->addItem(snakeHead);
    snakeHead->setFocus();

    // create a fruit
    Fruit* f1 = new Fruit();
    scene->addItem(f1);

}
