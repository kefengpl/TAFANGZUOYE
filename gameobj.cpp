#include "gameobj.h"
GAMEobj::GAMEobj()
{

}

void GAMEobj::initOBJ(string objname, string format)  //初始化地图中的每个图标，输入物体名称即可初始化，默认为png格式
{
    _icon=ICON::findICON(objname);
    QImage allpic;
    string pathname=":/new/prefix1/"+objname+"."+format;
    char* path=(char*)pathname.c_str();
    allpic.load(path);
   _pic=allpic.scaled(_icon.getwidth()*ICON::SET_SIZE, _icon.getheight()*ICON::SET_SIZE, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);   //将图片压缩成32*32像素的图片

}
void GAMEobj::show(QPainter * painter){
    int gSize = ICON::SET_SIZE;
    painter->drawImage(_pos_x*gSize,_pos_y*gSize,_pic); //这里依然是像素坐标，包含了换算,_pic是Qimage对象
}

int GAMEobj::getnextX(int direction)
{
    switch (direction) {    //1,2,3,4按照常理，分别代表上下左右,通过方向来获取游戏中物体的下一个坐标
    case 1:
        return _pos_x;
    case 2:
        return _pos_x;
    case 3:
        return _pos_x-1;
    case 4:
        return _pos_x+1;

    }
}
int GAMEobj::getnextY(int direction)
{
    switch (direction) {    //1,2,3,4按照常理，分别代表上下左右,通过方向来获取游戏中物体的下一个坐标
    case 1:
        return _pos_y-1;
    case 2:
        return _pos_y+1;
    case 3:
        return _pos_y;
    case 4:
        return _pos_y;

    }
}
