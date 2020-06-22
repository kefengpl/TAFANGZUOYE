#include "tower.h"
int Tower::SIZE=100;
Tower::Tower(QPoint towerpoint,const char * OSpath):T_CTpos(towerpoint)
{
    AttackHurt=10;
    AttackRange=120;
    T_pic.load(OSpath);
    T_pic=T_pic.scaled(SIZE,SIZE,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}
void Tower::DrawTower(QPainter &painter)
{
    painter.save();
    painter.setPen(Qt::green);
    painter.drawEllipse(T_CTpos,AttackRange,AttackRange);
    QPoint SetPoint(-SIZE/2, -SIZE/2);
    painter.translate(T_CTpos);
    painter.drawPixmap(SetPoint,T_pic);
    painter.restore();
}
