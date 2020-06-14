#ifndef TOWER_H
#define TOWER_H
#include<Qpoint>
#include<QPixmap>
#include<QPainter>
class Tower
{
public:
    Tower(QPoint towerpoint);

    void DrawTower(QPainter & painter);
private:
    QPixmap T_pic;
    QPoint  T_CTpos;   //这里用的中心点来表示

    int AttackRange;
    int AttackHurt;
    static int SIZE;
};

#endif // TOWER_H
