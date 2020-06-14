#include "tower.h"
int Tower::SIZE=100;
Tower::Tower(QPoint towerpoint):T_CTpos(towerpoint)
{
    AttackHurt=10;
    AttackRange=100;
    T_pic.load(":/new/pics/Tower1.png");
    T_pic=T_pic.scaled(SIZE,SIZE,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}
void Tower::DrawTower(QPainter &painter)
{
    painter.save();
    QPoint SetPoint(-SIZE/2, -SIZE/2);
    painter.translate(T_CTpos);
    painter.drawPixmap(SetPoint,T_pic);
    painter.restore();
}
