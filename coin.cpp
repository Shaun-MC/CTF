#include "coin.h"

Coin::Coin(int boardWidth, int boardHeight){
    srand(time(0)); //seed rand() with current time
    //generate random lcoation
    location_.x = rand() % boardWidth;
    location_.y = rand() % boardHeight;
}

string coin::toString(){
        string esc = "\033[";
        return esc + tostring(BOLD) + ";" + tostring(colorCode_) + "m" + symbol_ + esc + RESET + "m";
}