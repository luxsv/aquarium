#ifndef FISH_H
#define FISH_H

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <ctime>
#include <unistd.h>

using namespace std;

class Fish{
public:
Fish(){
    initFish();
    cout<<"init Fishhh "<<countLiveFish+1<<endl;
    ++countFish;
    ++countLiveFish;
}

bool isDead();
bool isFree();
void initFish();
void isPotion();
void fishInfo() const;
void move();


friend class Potion;

static void MoveFishs(Fish * school);
static void FishsInfo(Fish * school);
static void showField();
static void initField();

enum Limits{ boundX = 80, boundY = 25};

static int countLiveFish;
private:
    int x, y;
    double hp;
    char name;
    static char field[boundY][boundX]; 
    static int countFish;
    bool isWall;
    bool live;
    void moveIsWall();
};

#endif
