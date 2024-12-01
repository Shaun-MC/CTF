#include "entity.h"

Coordinates Entity::move(kDirection direction){
    switch(direction){
        case UP:
            location_.y++;
            break;
        case DOWN:
            location_.y--;
            break;
        case LEFT:
            location_.x--;
            break;
        case RIGHT:
            location_.x++;
            break;
        default: //STAY
            //do nothing
    }
    return location_;
}

Coordinates Entity::getLocation(){
    return location_;
}