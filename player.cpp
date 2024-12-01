#include "player.h"

//returns the string representing the player
string player::toString(){
    string esc = "\033[";
    if(alive_)
        return esc + tostring(BOLD) + ";" + tostring(colorCode_) + "m" + symbol_ + esc + RESET + "m";
    else   
        return esc + tostring(BOLD) + ";" + tostring(STRIKETHROUGH) + ";" + tostring(colorCode_) + "m" 
            + symbol_ + esc + RESET + "m";
}

//moves in direction given and returns new location. Does not move if player dead
Coordinates player::move(kDirection direction){
    if(!alive_) return location_;
    return Entity::move(direction); //call base class move()
}

//returns true if alive, else does not add amount and returns false
bool player::addScore(int amount){
    if(!alive_) return false;
    score_ += amount;
    return true;
}

//returns score
int player::getScore(){
    returns score_;
}

//sets alive to false
void player::kill(){
    alive_ = false;
}