#include "monsters.h"

Monsters::Monsters():HP(10)
{
    _pos_x=0;
    _pos_y=40;  //Ϊ����ĳ�ʼλ��д������
}
Monsters::move(int direction,int steps)
{
    switch (direction) {  //1,2,3,4�ֱ�����ϣ��£�����
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


