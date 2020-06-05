#include "monsters.h"

Monsters::Monsters():HP(10)
{
    _pos_x=0;
    _pos_y=40;  //为怪物的初始位置写下坐标
}
Monsters::move(int direction,int steps)
{
    switch (direction) {  //1,2,3,4分别代表上，下，左，右
    case 1:
        _pos_y-=steps;
        break;
    case 2:
        _pos_y+=steps;
         break;
    case 3:
        _pos_x-=steps;
         break;
    case 4:
        _pos_x+=steps;
         break;
    case 0:
         break;
    }
}


