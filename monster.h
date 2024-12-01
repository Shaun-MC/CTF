#ifndef MONSTER_H_
#define MONSTER_H_
#include "colors.h"
#include "entity.h"
#include "player.h"
using namespace std;

class Monster : private Entity {
public:
    Monster(char symbol, int colorCode, Coordinates location) 
        : symbol_(symbol), colorCode_(colorCode), location_(location) {};
    string toString();
    Coordinates hunt(int totalPrey, Player* prey); //takes array of players and determines next move. returns new coordinates.
private:
};

#endif