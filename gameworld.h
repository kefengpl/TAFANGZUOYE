#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#include <iostream>
#include <string>
#include<vector>
#include"gameobj.h"
#include"monsters.h"
using namespace std;
class GameWorld
{
public:
    GameWorld();
    ~GameWorld();
    void initWorld();
        //输入的文件中定义了初始状态下游戏世界有哪些对象，出生点在哪
        /*e.g.
           player 5 5
           stone 3 3
           fruit 7 8
         */
    void show(QPainter * painter);
    void themove(int direction=4,int steps=1);
    bool tothecastle=false;
private:
    vector<GAMEobj *> _objs;
    Monsters* _mons;
};

#endif // GAMEWORLD_H
