#ifndef POTION_H
#define POTION_H
#include "Fish.h"

class Potion {
public: 
    Potion(){ 
        setPotion();
        ++count;
    }

    void setPotion();
    bool isFree();
private:
    int xp,yp;
    static int count;
};
#endif
