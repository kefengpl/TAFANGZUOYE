#include "gameworld.h"
#include "mapfile.h"
GameWorld::GameWorld()
{
    this->_mons=new Monsters;
}
GameWorld::~GameWorld(){
    delete this->_mons;       //析构函数，删除怪物
}
MapFile map_file[]=
{
    //MapFile("BACKGROUND","jpg",0,0),
    MapFile("PATH","png",0,5),
    //MapFile("MONSTER1R","png",0,5),
    MapFile("PATH","png",1,5),
    MapFile("PATH","png",2,5),
    MapFile("PATH","png",2,6),
    MapFile("PATH","png",2,7),
    MapFile("PATH","png",2,8),
    MapFile("PATH","png",3,8),
    MapFile("PATH","png",4,8),
    MapFile("PATH","png",4,7),
    MapFile("PATH","png",4,6),
    MapFile("PATH","png",4,5),
    MapFile("PATH","png",4,4),
    MapFile("PATH","png",4,3),
    MapFile("PATH","png",4,2),
    MapFile("PATH","png",5,2),
    MapFile("PATH","png",6,2),
    MapFile("PATH","png",7,2),
    MapFile("PATH","png",7,3),
    MapFile("PATH","png",7,4),
    MapFile("PATH","png",7,5),
    MapFile("PATH","png",8,5),
    MapFile("PATH","png",9,5),
    MapFile("PATH","png",10,5),
    MapFile("PATH","png",11,5),
    MapFile("PATH","png",12,5),
    MapFile("CASTLE","png",12,4)
 //   MapFile("MONSTER1R","png",0,20)
};

void GameWorld::initWorld(){
    //TODO 下面的内容应该改为从地图文件装载
    //player 5 5
    int n=sizeof(map_file)/sizeof(map_file[0]);
    for (int i=0;i<n;i++)
    {
        GAMEobj *p0 = new GAMEobj;
        p0->initOBJ(map_file[i].getname(),map_file[i].getformat());
        p0->setposX(map_file[i].getx());
        p0->setposY(map_file[i].gety());
        _objs.push_back(p0);

    }
  /*  GAMEobj *p1 = new GAMEobj;
    p1->initOBJ("CASTLE");
    p1->setposX(12);
    p1->setposY(4);

    GAMEobj *p2=new GAMEobj;
    p2 ->initOBJ("BACKGROUND","jpg");
    p2->setposX(0);
    p2->setposY(0);
    _objs.push_back(p2);  //向vector容器中添加元素！
    _objs.push_back(p1);*/

   /* QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sounds/hdl.mp3"));  //这个应该是背景音乐！
    player->setVolume(30);
    player->play();*/


}


void GameWorld::show(QPainter * painter){
    int n = this->_objs.size();
    for (int i=0;i<n;i++){
        this->_objs[i]->show(painter);   //画地图场景，即静态物体
    }
    if(!tothecastle&&!(_mons->HPzero())){
    _mons->initOBJ("MONSTER1R","png");
    _mons->show(painter);
    }
}


/*void World::eraseObj(int x, int y){  //这回是擦去物体
    vector<RPGObj*>::iterator it;   //迭代器
    it = _objs.begin();
    while(it!=_objs.end()){
        int flag1 = ((*it)->getObjType()!="stone"); //不是石头
        int flag2 = ((*it)->getPosX() == x) && ((*it)->getPosY()==y);//位置重叠

        if (flag1 && flag2){
            cout<<(*it)->getObjType()<<endl;
            (*it)->onErase();  //播放撞上的声音
            delete (*it);
            it = this->_objs.erase(it);
            break;
         }
        else{
            it++;
        }
    }

}
*/
//void GameWorld::eraseMonster(){  //这回是擦去物体


    /*  vector<RPGObj*>::iterator it;   //迭代器
    it = _objs.begin();
    while(it!=_objs.end()){
        int flag1 = ((*it)->getObjType()!="stone"); //不是石头
        int flag2 = ((*it)->getPosX() == x) && ((*it)->getPosY()==y);//位置重叠

        if (flag1 && flag2){
            cout<<(*it)->getObjType()<<endl;
            (*it)->onErase();  //播放撞上的声音
            delete (*it);
            it = this->_objs.erase(it);
            break;
         }
        else{
            it++;
        }
    }*/
//}
void GameWorld::themove(int direction,int steps)   //在游戏世界中设定好怪物走动的脚本
{
    this->_mons->move(direction,steps);
}
