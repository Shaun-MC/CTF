#ifndef PAWN_H_
#define PAWN_H_

enum kDirection {UP, DOWN, LEFT, RIGHT, STAY};

typedef struct {
    int x;
    int y;
} Coordinates;

//abstract class
class Entity {
public:
    virtual string toString() = 0; //=0 so must be overridden in derived class
    virtual Coordinates move(kDirection); //move and return new coordinates
    Coordinates getLocation();

protected: //protected so derived classes have access
    Coordinates location_; 
    char symbol_;   //symbol to represent monster on board
    int colorCode_; //ANSI color code for printing monster symbol
};

#endif