#ifndef PLAYER_H_
#define PLAYER_H_
#include "colors.h"
#include "entity.h"
using namespace std;

class Player : private Entity {
public:
    Player(char symbol, int colorCode, Coordinates location) 
        : symbol_(symbol), colorCode_(colorCode), location_(location), score_(0), alive_(1) {};
    string toString();
    Coordinates move(kDirection direction); //move in direction and return new coordinates
    bool addScore(int amount); //returns true if alive, else does not add amount and returns false
    int getScore();
    void kill(); //sets alive_ to false

private:
    int score_;     //current player score;
    bool alive_;    
};

#endif