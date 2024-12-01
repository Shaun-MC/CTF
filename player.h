#ifndef PLAYER_H_
#define PLAYER_H_
#include "colors.h"

typedef struct {
    int x;
    int y;
} Coordinates;

class Player {
public:
    Player(char symbol, int colorCode, Coordinates location) : symbol_(symbol), colorCode_(colorCode), location_(location) {};
    string toString();
    bool addScore(int amount); //returns true if alive, else does not add amount and returns false
private:
    Coordinates location_; 
    char symbol_;   //symbol to represent player on board
    int colorCode_; //ANSI color code for printing player symbol
    int score_;     //current player score;
    bool alive_;    
};

#endif