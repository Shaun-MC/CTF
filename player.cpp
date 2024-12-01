#include "player.h"

//returns the string representing the player
string toString(){
    string esc = "\033[";
    return esc + tostring(BOLD) + ";" + tostring(colorCode_) + symbol_ + esc + RESET + "m";
}

//returns true if alive, else does not add amount and returns false
bool addScore(int amount){
    if(!alive_) return false;
    score_ += amount;
    return true;
}