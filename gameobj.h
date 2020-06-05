#ifndef GAMEOBJ_H
#define GAMEOBJ_H
#include"icon.h"
#include<QImage>
#include<QPainter>
#include<string>
class GAMEobj
{
public:
    GAMEobj();
    void initOBJ(string objname, string format="png");
    void show(QPainter * painter);
    void setposX(int x){_pos_x=x;}
    void setposY(int y){_pos_y=y;}      //设置某物件在场景中的位置
    int getposX(){return _pos_x;}
    int getposY(){return _pos_y;}      //获取相应位置，以游戏格数单位为坐标
    int getheight() {return _icon.getheight();}
    int getwidth() {return _icon.getwidth();}   //获取某物件的长宽高
    int getnextX(int direction);
    int getnextY(int direction);    //通过方向来获取游戏中物体的下一个坐标
protected:
    QImage _pic;
    ICON _icon;//可以从ICON中获取对象的素材，尺寸等信息
    int _pos_x, _pos_y;//该物体在游戏中当前位置（左上角坐标）
};

#endif // GAMEOBJ_H
