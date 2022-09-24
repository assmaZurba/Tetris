//
// Created by assma on 9/9/22.
//

#ifndef TETRIS_LINE_H
#define TETRIS_LINE_H
#include "Shape.h"

class Line : public Shape{
public:
    int num;
    Line(){
        ShapeRectangls[0]->setFillColor(sf::Color::Red);
        ShapeRectangls[1]->setFillColor(sf::Color::Red);
        ShapeRectangls[2]->setFillColor(sf::Color::Red);
        ShapeRectangls[3]->setFillColor(sf::Color::Red);
        this->num=1+(rand() % 2 );
        if(this->num==1){
            ShapeRectangls[0]->setPosition((WIDTH/2)+REC_DIM, 0);
            ShapeRectangls[1]->setPosition((WIDTH/2), 0);
            ShapeRectangls[2]->setPosition((WIDTH/2)-REC_DIM, 0);
            ShapeRectangls[3]->setPosition((WIDTH/2)-2*REC_DIM, 0);
        }
        else if(this->num==2){
            ShapeRectangls[0]->setPosition((WIDTH/2), 0);
            ShapeRectangls[1]->setPosition((WIDTH/2), REC_DIM);
            ShapeRectangls[2]->setPosition((WIDTH/2), 2*REC_DIM);
            ShapeRectangls[3]->setPosition((WIDTH/2), 3*REC_DIM);
        }
        findDownerRec();
        findLefterRec();
        findRighterRec();
    }
    void Rotate();
private:
    void setPosition1();
    void setPosition2();
};

void Line::Rotate() {
    if(this->num==1){
        Line:: setPosition2();
    }
    else if(this->num==2){
        Line:: setPosition1();
    }

}

//move from 2 to 1
void Line:: setPosition1(){
    if(ShapeRectangls[1]->getPosition().x-REC_DIM>=0 && ShapeRectangls[2]->getPosition().x-2*REC_DIM>=0 && ShapeRectangls[3]->getPosition().x-3*REC_DIM>=0){
        this->num=1;
        ShapeRectangls[0]->setPosition( ShapeRectangls[0]->getPosition().x,  ShapeRectangls[0]->getPosition().y);
        ShapeRectangls[1]->setPosition(ShapeRectangls[1]->getPosition().x-REC_DIM, ShapeRectangls[1]->getPosition().y-REC_DIM);
        ShapeRectangls[2]->setPosition(ShapeRectangls[2]->getPosition().x-2*REC_DIM, ShapeRectangls[2]->getPosition().y-2*REC_DIM);
        ShapeRectangls[3]->setPosition(ShapeRectangls[3]->getPosition().x-3*REC_DIM, ShapeRectangls[3]->getPosition().y-3*REC_DIM);
        findDownerRec();
        findLefterRec();
        findRighterRec();
    }
}

//move from 1 to 2
void Line:: setPosition2(){
    if(ShapeRectangls[1]->getPosition().x+REC_DIM<=WIDTH-REC_DIM && ShapeRectangls[2]->getPosition().x+2*REC_DIM<=WIDTH-REC_DIM && ShapeRectangls[3]->getPosition().x+3*REC_DIM<=WIDTH-REC_DIM){
        this->num=2;
        ShapeRectangls[0]->setPosition( ShapeRectangls[0]->getPosition().x,  ShapeRectangls[0]->getPosition().y);
        ShapeRectangls[1]->setPosition(ShapeRectangls[1]->getPosition().x+REC_DIM, ShapeRectangls[1]->getPosition().y+REC_DIM);
        ShapeRectangls[2]->setPosition(ShapeRectangls[2]->getPosition().x+2*REC_DIM, ShapeRectangls[2]->getPosition().y+2*REC_DIM);
        ShapeRectangls[3]->setPosition(ShapeRectangls[3]->getPosition().x+3*REC_DIM, ShapeRectangls[3]->getPosition().y+3*REC_DIM);
        findDownerRec();
        findLefterRec();
        findRighterRec();
    }
}

#endif //TETRIS_LINE_H
