#include "Potion.h"
#include "Fish.h"
#include <ctime>
int Potion::count = 0;

void Potion::setPotion() {
    srand(time(NULL));        
    usleep(90000); 
    xp = rand()%Fish::boundX;
    usleep(90000); 
//    usleep(800000); 
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
