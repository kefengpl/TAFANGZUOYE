#ifndef ICON_H
#define ICON_H
#include <map>
#include<string>
#include<iostream>
using namespace std;
class ICON         //����ͼ����
{
public:
    ICON(string name, int x, int y, int w, int h);
    ICON(){}  //��������
    static ICON findICON(string type);  //���������Ҷ�Ӧ���ز�����
    static int SET_SIZE;   //����һ���������
    static map<string,ICON> GAME_ICON_SET;  //������ԣ������ֺ��ض���ͼƬλ�ã���С��Ӧ����
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
