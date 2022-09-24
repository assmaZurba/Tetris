//
// Created by assma on 9/9/22.
//

#ifndef TETRIS_SQUARE_H
#define TETRIS_SQUARE_H
#include "Shape.h"

class Square : public Shape{
public:
    Square(){
        ShapeRectangls[0]->setFillColor(sf::Color::Cyan);
        ShapeRectangls[1]->setFillColor(sf::Color::Cyan);
        ShapeRectangls[2]->setFillColor(sf::Color::Cyan);
        ShapeRectangls[3]->setFillColor(sf::Color::Cyan);
        ShapeRectangls[0]->setPosition((WIDTH/2), 0);
        ShapeRectangls[1]->setPosition((WIDTH/2)-REC_DIM, 0);
        ShapeRectangls[2]->setPosition((WIDTH/2), REC_DIM);
        ShapeRectangls[3]->setPosition((WIDTH/2)-REC_DIM, REC_DIM);
        findDownerRec();
        findLefterRec();
        findRighterRec();
    }
    void Rotate(){}
};

#endif //TETRIS_SQUARE_H
