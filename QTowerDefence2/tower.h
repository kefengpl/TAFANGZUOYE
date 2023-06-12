#ifndef TOWER_H
#define TOWER_H
#include<Qpoint>
#include<QPixmap>
#include<QPainter>
class Tower
{
public:
    Tower(QPoint towerpoint,const char *OSpath=":/new/pics/Tower1.png");   //�����������·����Ϊ�˺���ʵ�ֶ�̬

    void DrawTower(QPainter & painter);
private:
    QPixmap T_pic;
    QPoint  T_CTpos;   //�����õ����ĵ�����ʾ
    int AttackRange;
    int AttackHurt;
    static int SIZE;
};

#endif // TOWER_H
