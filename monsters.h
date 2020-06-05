#ifndef MONSTERS_H
#define MONSTERS_H
#include"gameobj.h"

class Monsters:public GAMEobj      //小怪类继承了GAMEobj类，属于游戏里面的物体
{
public:
    Monsters();
    ~Monsters(){}
    move(int direction=4,int steps=1);
    bool HPzero(){
     if(HP==0)
     {
         return true;
     }
     else
     {
         return false;
     }
    }
private:
    int HP;
};

#endif // MONSTERS_H
