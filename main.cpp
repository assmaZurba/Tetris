#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Line.h"
#include "Square.h"
#include "badShape.h"

Shape *shapeArray[100];
int shapesCounter=0;
typedef struct{
    int x;
    int y;
}HigherPlate;
HigherPlate plate[WIDTH/REC_DIM];
sf::RectangleShape** plates[HEIGHT/REC_DIM][WIDTH/REC_DIM];
void updatePlate();
void updateHigh(int high);
int main() {
    for(int i=0;i<HEIGHT/REC_DIM;i++)
        for(int j=0;j<WIDTH/REC_DIM;j++){
            plates[i][j]= nullptr;
        }

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "NEW GAME");
    int random=rand()%100;
    if(random%3==0){
        shapeArray[shapesCounter]=new Line();
    }
    else if(random%3==1){
        shapeArray[shapesCounter]=new Square();
    }
    else{
        shapeArray[shapesCounter]=new badShape();
    }
    float timer=0;
    float delay=0.3;
    sf::Clock clock1;

    for(int i=0;i<WIDTH/REC_DIM;i++){
        plate[i].x=i*REC_DIM;
        plate[i].y=HEIGHT;
    }
    int stop=0;
    // Start the game loop
    while (window.isOpen())
    {
        float  time =clock1.getElapsedTime().asSeconds();
        clock1.restart();
        timer+=time;

        for(int i=0;i<WIDTH/REC_DIM;i++){
            for(int j=0;j<4;j++){
                if(plate[i].x==shapeArray[shapesCounter]->ShapeRectangls[j]->getPosition().x)
                    if(plate[i].y==shapeArray[shapesCounter]->ShapeRectangls[j]->getPosition().y+REC_DIM)
                        stop=1;
            }
        }

        if(timer>delay && stop==0){
            shapeArray[shapesCounter]->moveDown(REC_DIM);
            timer=0;
        }

        if(stop==1){
            stop=0;

            for(int i=0;i<4;i++){
                plates[(int)shapeArray[shapesCounter]->ShapeRectangls[i]->getPosition().y / (REC_DIM)][(int)shapeArray[shapesCounter]->ShapeRectangls[i]->getPosition().x /(REC_DIM)]=&(shapeArray[shapesCounter]->ShapeRectangls[i]);
            }
            for(int i=0;i<HEIGHT/REC_DIM;i++){
                for(int j=0;j<WIDTH/REC_DIM;j++){
                    if(plates[i][j]== nullptr)
                        break;
                    else if(j==WIDTH/REC_DIM-1){
                        for(j=0;j<WIDTH/REC_DIM;j++){
                            *plates[i][j]= nullptr;
                            plates[i][j]= nullptr;
                        }
                        updateHigh(i*REC_DIM);
                        updatePlate();
                        window.display();
                    }
                }
            }
            updatePlate();

            window.display();
            shapesCounter++;
            random=rand()%100 ;
            if(random%3==0){
                shapeArray[shapesCounter]=new Line();
            }
            else if(random%3==1){
                shapeArray[shapesCounter]=new Square();
            }
            else{
                shapeArray[shapesCounter]=new badShape();
            }
        }

        window.clear(sf::Color::White );
        for(int j=0;j<=shapesCounter;j++){
            for(int k=0;k<RECTANGELS_NUM;k++)
                if(shapeArray[j]->ShapeRectangls[k]!= nullptr){
                    window.draw(*(shapeArray[j]->ShapeRectangls[k]));
                }
        }

        window.display();
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            //move to left
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                if(shapeArray[shapesCounter]->lefterRec->getPosition().x-REC_DIM>=0){
                    shapeArray[shapesCounter]->moveLeft();
                    window.display();
                }
            }

            //move to right
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                if(shapeArray[shapesCounter]->righterRec->getPosition().x+REC_DIM<=WIDTH-REC_DIM){
                    shapeArray[shapesCounter]->moveRight();
                    window.display();
                }
            }

            //Rotate
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                shapeArray[shapesCounter]->Rotate();
                window.display();
            }

            //faster
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

            }
        }
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}

void updatePlate(){
    int find=0;
    for(int i=0;i<WIDTH/REC_DIM;i++){
        for(int k=0;k<=shapesCounter;k++){
            for(int j=0;j<4;j++){
                if(shapeArray[k]->ShapeRectangls[j]!= nullptr){
                    if(plate[i].x==shapeArray[k]->ShapeRectangls[j]->getPosition().x)
                        if(plate[i].y>=shapeArray[k]->ShapeRectangls[j]->getPosition().y){
                            plate[i].y=shapeArray[k]->ShapeRectangls[j]->getPosition().y;
                            find=1;
                        }
                }
            }
        }
        if(find==0)
            plate[i].y=HEIGHT;
        find=0;
    }

}
void updateHigh(int high){
    for (int i = 0; i <= shapesCounter; i++) {
        for (int j = 0; j <4; j++) {
            if(shapeArray[i]->ShapeRectangls[j]!= nullptr){
                if(shapeArray[i]->ShapeRectangls[j]->getPosition().y<high){
                    shapeArray[i]->ShapeRectangls[j]->setPosition(shapeArray[i]->ShapeRectangls[j]->getPosition().x,shapeArray[i]->ShapeRectangls[j]->getPosition().y+REC_DIM);
                }
            }
        }
    }
    for(int i=0;i<WIDTH/REC_DIM;i++) {
        for (int j = high/REC_DIM; j >0; j--) {
            plates[j][i]=plates[j-1][i];
        }
    }
    for(int i=0;i<WIDTH/REC_DIM;i++) {
        plates[0][i]= nullptr;
    }

}

//    rectangle.setOutlineColor(sf::Color::Red);
//    rectangle.setOutlineThickness(5);
//
//    // Create a graphical text to display
//    sf::Font font;
//    if (!font.loadFromFile("arial.ttf"))
//        return EXIT_FAILURE;
//    sf::Text text("Hello SFML", font, 50);
//
//    // Load a music to play
//    sf::Music music;
//    if (!music.openFromFile("nice_music.ogg"))
//        return EXIT_FAILURE;
//
//    // Play the music
//    music.play();

//        // Draw the sprite
//        window.draw(sprite);

//

//        // Draw the string
//        window.draw(text);
