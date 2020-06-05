#ifndef ICON_H
#define ICON_H
#include <map>
#include<string>
#include<iostream>
using namespace std;
class ICON         //创建图标类
{
public:
    ICON(string name, int x, int y, int w, int h);
    ICON(){}  //这里重载
    static ICON findICON(string type);  //根据名称找对应的素材属性
    static int SET_SIZE;   //设置一格的像素数
    static map<string,ICON> GAME_ICON_SET;  //设置配对，让名字和特定的图片位置，大小对应起来
    int getitsX(){return itsX;}
    int getitsY(){return itsY;}
    int getwidth(){return width;}
    int getheight(){return height;}
    string getICONname(){return name;}
protected:
    int itsX;
    int itsY;
    int width;
    int height;
    string name;
};

#endif // ICON_H
