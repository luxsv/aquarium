#include "Fish.h"
#include <cctype>

using namespace std;

int Fish::countFish = 0;
int Fish::countLiveFish = 0;
char Fish::field[boundY][boundX] = {};

void Fish::initField() {
    memset(field,46, boundY*boundX);
}


void Fish::showField() {
    for (int i = 0; i <boundY;i++) {
        for(int j = 0; j< boundX;j++ ) {
            cout<<field[i][j];
        }
        cout<<endl;
    }     
}


void Fish::isPotion() {
    if (field[y][x] == '@') {
        hp+=20;
        if (hp > 100) { hp = 100;}
    }
}


bool Fish::isDead(){
    if (hp <= 0 ) {
        if (live) {--countLiveFish;}
        field[y][x] = 'X';
        hp = 0;
        live = false;
        return true;
    }
    return false;
}


void Fish::moveIsWall(){
    isWall = true; 
    if ((int)(name) %2) {
        y > boundY-2 ? y = 0:  ++y; 
        if(hp > 50 && y < boundY-2) ++y; 
    } else {
        y < 1 ? y = boundY-1 : --y; 
        if(hp < 50 && y > 2) --y; 
    } 
}


void Fish::move() {    
    if (!isDead()) {
        field[y][x] = '.';
        if (x < boundX-1 && isWall) {
            if (isalpha(field[y][x-1])) { y >  (boundY-2) ? --y :++y;}
            ++x;
        } else  if(x > 0) {
            if (isWall) { moveIsWall();}
            if (isalpha(field[y][x+1])) { y >  (boundY-2) ? --y :++y;}
            --x;
             isWall = false;    
        } else {
           moveIsWall(); 
        }
        isPotion();
        field[y][x] = name;
        hp-= 0.2; 
    }
}

void Fish::MoveFishs(Fish * school) {
    for (int i = 0; i < countFish;i++) {
            school[i].move();
    }
}


void Fish::initFish() {
    hp = 100;
    srand(time(NULL));        
    usleep(100000); 
    x = rand()% boundX;
    y = rand()% boundY;
    if (!isFree()) {
         return initFish();
    }
    name = (char) countFish+65;
    field[y][x] = name;
    isWall = true;
    live = true;
}


bool Fish::isFree() {
    if(field[y][x] == '.') {
        return true;
     }   
    return false;
}


void Fish::FishsInfo(Fish * school) {
    cout<<"[Count fish]| all : "<<countFish<<" live : "<<countLiveFish<<endl;
    for (int i = 0; i < countFish;i++) {
        school[i].fishInfo();
    }
    cout<<endl;
}


void Fish::fishInfo(){
    char arrayHp[50];
    memset(arrayHp,45, 50); 
    memset(arrayHp,35, hp/2);
    cout<<name<<" : ";
    for (int i =0;i < 50;i++) {
        cout<<arrayHp[i]; 
    }
    cout<<" : "<<(int)hp<<endl;
}

