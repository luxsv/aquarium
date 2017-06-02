#include "Fish.h"
#include "Potion.h"

int main(int argc, const char * argv[]) {
    Fish::initField();
    Fish *a = new Fish[5];
    Potion *p = new Potion[12];
    
    while(Fish::countLiveFish) {
        std::cout<<string(100,'\n');
        Fish::MoveFishs(a);
        Fish::showField(); 
        Fish::FishsInfo(a);
        usleep(200000);
    }
    
    delete[] a; 
    delete[] p;
    
    return 0;
}
