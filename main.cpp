#include "Fish.h"
#include "Potion.h"
//#include <>

int main(int argc, const char * argv[]) {
    Fish::initField();
    Fish *a = new Fish[5];
    Potion *p = new Potion[12];
    int z; 
    while(Fish::countLiveFish) {
        std::cout<<string(100,'\n');
        Fish::MoveFishs(a);
        Fish::showField(); 
        Fish::FishsInfo(a);
        usleep(200000);
   //     std::cout<<"add potion press 1 ";
     //   std::cin>>z;
    }
    
    delete[] a; 
    delete[] p;
    
    return 0;
}
