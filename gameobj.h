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
    void setposY(int y){_pos_y=y;}      //����ĳ����ڳ����е�λ��
    int getposX(){return _pos_x;}
    int getposY(){return _pos_y;}      //��ȡ��Ӧλ�ã�����Ϸ������λΪ����
    int getheight() {return _icon.getheight();}
    int getwidth() {return _icon.getwidth();}   //��ȡĳ����ĳ����
    int getnextX(int direction);
    int getnextY(int direction);    //ͨ����������ȡ��Ϸ���������һ������
protected:
    QImage _pic;
    ICON _icon;//���Դ�ICON�л�ȡ������زģ��ߴ����Ϣ
    int _pos_x, _pos_y;//����������Ϸ�е�ǰλ�ã����Ͻ����꣩
};

#endif // GAMEOBJ_H
