#include "gameobj.h"
GAMEobj::GAMEobj()
{

}

void GAMEobj::initOBJ(string objname, string format)  //��ʼ����ͼ�е�ÿ��ͼ�꣬�����������Ƽ��ɳ�ʼ����Ĭ��Ϊpng��ʽ
{
    _icon=ICON::findICON(objname);
    QImage allpic;
    string pathname=":/new/prefix1/"+objname+"."+format;
    char* path=(char*)pathname.c_str();
    allpic.load(path);
   _pic=allpic.scaled(_icon.getwidth()*ICON::SET_SIZE, _icon.getheight()*ICON::SET_SIZE, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);   //��ͼƬѹ����32*32���ص�ͼƬ

}
void GAMEobj::show(QPainter * painter){
    int gSize = ICON::SET_SIZE;
    painter->drawImage(_pos_x*gSize,_pos_y*gSize,_pic); //������Ȼ���������꣬�����˻���,_pic��Qimage����
}

int GAMEobj::getnextX(int direction)
{
    switch (direction) {    //1,2,3,4���ճ����ֱ������������,ͨ����������ȡ��Ϸ���������һ������
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
    switch (direction) {    //1,2,3,4���ճ����ֱ������������,ͨ����������ȡ��Ϸ���������һ������
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
