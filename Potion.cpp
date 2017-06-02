#include "Potion.h"
#include "Fish.h"
int Potion::count = 0;

void Potion::setPotion() {
    srand(time(0));        
    xp = rand()%Fish::boundX;
    //usleep(500000); 
    usleep(800000); 
    yp = rand()% Fish::boundY;
    if (!isFree()) {
         return setPotion();
    }
    Fish::field[yp][xp] = '@';
}

bool Potion::isFree() {
    if(Fish::field[yp][xp] == '.') {
        return true;
     }   
    return false;
}
