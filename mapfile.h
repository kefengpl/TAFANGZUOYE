#ifndef MAPFILE_H
#define MAPFILE_H
#include<iostream>
#include<string>
using namespace std;
class MapFile             //��������������ͼ������Ԫ�ص����ƣ���ʽ��λ��
{
public:
    MapFile(string names,string forms,int x , int y);
    string getname(){return itsname;}
    string getformat(){return itsformat;}
    int getx(){return itsx;}
    int gety(){return itsy;}
private:
    string itsname;
    string itsformat;
    int itsx;
    int itsy;
};

#endif // MAPFILE_H
