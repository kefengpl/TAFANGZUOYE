#include "monster.h"

/*Monster::Monster(QObject *parent) : QObject(parent)
{

}*/
const int Monster::SIZE=100;
int Monster::MonAmount=0;
int Monster::MonWave=1;
//template<class MW>
Monster::Monster(Navigation *nowpt, const char * OSpath):QObject(0),M_CNpos(nowpt->GetPos()),M_TargetPoint(nowpt->GetNextPoint())
{
    GeneralHP=15;
    NowHP=15;
    MoveSpeed=3;
    HurtValue=1;
    CanMove=false;
    DeleteMonster=false;

    M_pic.load(OSpath);
    M_pic=M_pic.scaled(SIZE,SIZE,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}

void Monster::MonsterMove()
{
    if(CanMove==false)
    {
        return;
    }
    if(CollisionCircle(M_TargetPoint->GetPos(),2))
    {
        bool flag1=M_TargetPoint->GetPos().x()==M_TargetPoint->GetNextPoint()->GetPos().x();
        bool flag2=M_TargetPoint->GetPos().y()==M_TargetPoint->GetNextPoint()->GetPos().y();
        if(flag1&&flag2)
        {
           NowHP=0;
           return;
        }
        if(M_TargetPoint)
        {
             M_CNpos=M_TargetPoint->GetPos(); //ÕýÈ·
             M_TargetPoint=M_TargetPoint->GetNextPoint();

        }
    }
    QPoint TempPt = M_TargetPoint->GetPos();
    double MovementSpeed = MoveSpeed;
    QVector2D normalized(TempPt - M_CNpos);
    normalized.normalize();
    M_CNpos = M_CNpos + normalized.toPoint() * MovementSpeed;
    return;
}
bool Monster::CollisionCircle(QPoint CircleCenter,int Radius)
{
    int xx0=M_CNpos.x()-CircleCenter.x();
    int yy0=M_CNpos.y()-CircleCenter.y();
    double Distance=sqrt(xx0*xx0+yy0*yy0);
    if(Distance<=Radius)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int Monster::GetMons()
{
    return MonAmount;
}
int Monster::GetWaves()
{
    return MonWave;
}
void Monster::AddWaves()
{
    MonWave++;
}

int Monster::GetNowHP()
{
    return NowHP;
}
void Monster::ChangeCanMove()
{
    CanMove=true;
}

void Monster::DrawMonster(QPainter &painter)
{
    static const int Health_Bar_Width = 60;
    painter.save();
    QPoint healthBarPoint = M_CNpos + QPoint(-50, -50);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::red);
    QRect healthBarBackRect(healthBarPoint, QSize(Health_Bar_Width, 6));
    painter.drawRect(healthBarBackRect);
    painter.setBrush(Qt::green);
    QRect healthBarRect(healthBarPoint, QSize((double)NowHP / GeneralHP * Health_Bar_Width, 6));
    painter.drawRect(healthBarRect);

    painter.translate(M_CNpos);
    QPoint BiaPt(-SIZE/2,-SIZE/2);
    painter.drawPixmap(BiaPt,M_pic);
    painter.restore();
}
