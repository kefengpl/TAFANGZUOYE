#include "tower.h"
int Tower::SIZE=100;
Tower::Tower(QObject *parent) : QObject(parent)
{

}
Tower::Tower(QPoint towerpoint,const char * OSpath):T_CTpos(towerpoint)
{
    AttackHurt=2;
    AttackRange=120;
    TowerCanAttack=false;
    T_pic.load(OSpath);
    T_pic=T_pic.scaled(SIZE,SIZE,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}
QPoint Tower::GetTowerCNPlace()
{
    return T_CTpos;
}
int Tower::GetAttackHurt()
{
    return AttackHurt;
}
bool Tower::GetTowerCanAttack()
{
    return TowerCanAttack;
}

bool Tower::CoverAttackRange(const QPoint &thept)
{
    int xx0=T_CTpos.x()-thept.x();
    int yy0=T_CTpos.y()-thept.y();
    double Distance=sqrt(xx0*xx0+yy0*yy0);
    if(Distance<=AttackRange)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Tower::ChangeCanAttack(bool attack)
{
    TowerCanAttack=attack;
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
