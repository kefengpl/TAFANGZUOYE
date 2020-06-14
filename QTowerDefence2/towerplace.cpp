#include "towerplace.h"
int TowerPlace::SIZE=100;
TowerPlace::TowerPlace(QPoint position):TP_pos(position)
{
    HasTower=false;
    TP_pic.load(":/new/pics/TowerPlace.png");
    TP_pic=TP_pic.scaled(SIZE,SIZE,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);   //½«Í¼Æ¬Ñ¹Ëõ³É72*72ÏñËØµÄÍ¼Æ¬
}

bool TowerPlace::CheckHasTower()
{
    return HasTower;
}

void TowerPlace::ChangeHasTower(bool hastow)
{
    HasTower=hastow;
}

QPoint TowerPlace::CenterPoint()
{
    QPoint HalfLength(SIZE/2,SIZE/2);
    return TP_pos+HalfLength;
}

bool TowerPlace::CoverTP(const QPoint &thept)
{
    bool Xinit=(thept.x()>=TP_pos.x())&&(thept.x()<=TP_pos.x()+SIZE);
    bool Yinit=(thept.y()>=TP_pos.y())&&(thept.y()<=TP_pos.y()+SIZE);
    if(Xinit&&Yinit)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void TowerPlace::DrawTP(QPainter & painter)
{
    painter.drawPixmap(TP_pos.x(),TP_pos.y(),TP_pic);
}

