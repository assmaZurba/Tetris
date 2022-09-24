//
// Created by assma on 9/9/22.
//

#ifndef TETRIS_SHAPE_H
#define TETRIS_SHAPE_H
#include <SFML/Graphics.hpp>
int const WIDTH=800;
int const HEIGHT=960;
int const REC_DIM=40;
int const RECTANGELS_NUM=4;
class Shape {

public:
    sf::RectangleShape* ShapeRectangls[RECTANGELS_NUM];
    sf::RectangleShape *righterRec;
    sf::RectangleShape *lefterRec;
    sf::RectangleShape *downerRec;

    Shape(){
        for(int i=0;i<RECTANGELS_NUM;i++){
            ShapeRectangls[i]=new sf::RectangleShape();
            ShapeRectangls[i]->setSize(sf::Vector2f(REC_DIM,REC_DIM));
        }
        righterRec=new sf::RectangleShape();
        lefterRec=new sf::RectangleShape();
        ShapeRectangls[0]->setOutlineThickness(1);
        ShapeRectangls[1]->setOutlineThickness(1);
        ShapeRectangls[2]->setOutlineThickness(1);
        ShapeRectangls[3]->setOutlineThickness(1);
        ShapeRectangls[0]->setOutlineColor(sf::Color::Black);
        ShapeRectangls[1]->setOutlineColor(sf::Color::Black);
        ShapeRectangls[2]->setOutlineColor(sf::Color::Black);
        ShapeRectangls[3]->setOutlineColor(sf::Color::Black);
    }
    void moveLeft();
    void moveRight();
    void moveDown(int offset = 1);
    virtual void  Rotate(){}
    void findRighterRec();
    void findLefterRec();
    void findDownerRec();
};

void Shape::moveLeft(){
    for(int i=0;i<RECTANGELS_NUM;i++)
        ShapeRectangls[i]->setPosition( ShapeRectangls[i]->getPosition().x-REC_DIM,ShapeRectangls[i]->getPosition().y);
}

void Shape::moveRight(){
    for(int i=0;i<RECTANGELS_NUM;i++)
        ShapeRectangls[i]->setPosition( ShapeRectangls[i]->getPosition().x+REC_DIM,ShapeRectangls[i]->getPosition().y);
}

void Shape::moveDown(int offset){
    for(int i=0;i<RECTANGELS_NUM;i++)
        ShapeRectangls[i]->setPosition( ShapeRectangls[i]->getPosition().x,ShapeRectangls[i]->getPosition().y+offset);
}

void Shape::findRighterRec(){
    righterRec=ShapeRectangls[0];
    for(int i=1;i<RECTANGELS_NUM;i++)
        if(ShapeRectangls[i]->getPosition().x>righterRec->getPosition().x)
            righterRec=ShapeRectangls[i];
}

void Shape::findLefterRec(){
    lefterRec=ShapeRectangls[0];
    for(int i=1;i<RECTANGELS_NUM;i++)
        if(ShapeRectangls[i]->getPosition().x<lefterRec->getPosition().x)
            lefterRec=ShapeRectangls[i];
}

void Shape::findDownerRec(){
    downerRec=ShapeRectangls[0];
    for(int i=1;i<RECTANGELS_NUM;i++)
        if(ShapeRectangls[i]->getPosition().y>downerRec->getPosition().y)
            downerRec=ShapeRectangls[i];
}

#endif //TETRIS_SHAPE_H
