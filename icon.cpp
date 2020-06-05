#include "icon.h"
int ICON::SET_SIZE =12;  //一个游戏格相当于96像素,修改成前12为24
ICON::ICON(string names,int x,int y,int w,int h)  //构造函数
{
   name=names;
   itsX=x;
   itsY=y;
   width=w;
   height=h;
}
pair<string,ICON> pairArray[] =   //pair是一个模板类型，将两种数据合成为一种数据，map用来储存键值对，这里构造了一个数组，下面的3个属于数组中的元素
{                                 //make——pair返回pair<>类型
    make_pair("CASTLE",ICON("CASTLE",0,0,8*2,8*2)),                  //这里ICON构造函数，设定了名称和对应区域！
    make_pair("BACKGROUND",ICON("BACKGROUND",0,0,14*8,10*8)),
    make_pair("PATH",ICON("PATH",0,0,4*2,4*2)),
    make_pair("MONSTER1R",ICON("MONSTER1R",0,0,3*2,4*2)),
    make_pair("TOWER1",ICON("TOWER1",0,0,4*2,4*2)),
    make_pair("BASEBUTTON",ICON("BASEBUTTON",0,0,4*2,4*2)),
};

map<string,ICON> ICON::GAME_ICON_SET(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));
//静态成员在类外进行初始化！这两个参数标志了这一范围内的所有键值对
ICON ICON::findICON(string type){
    map<string,ICON>::iterator kv;           //map类的迭代器，通俗地说，就相当于计数变量I
    kv = ICON::GAME_ICON_SET.find(type);  //.find函数用于查找，参数为键，返回对应的迭代器
    if (kv==ICON::GAME_ICON_SET.end()){    //end基本上指找不到了

       cout<<"Error: cannot find ICON"<<endl;
       return ICON();                   //返回一个默认值
    }
    else{
        return kv->second;        //返回对应键值对的那个值,也就是对应图片
    }
}
