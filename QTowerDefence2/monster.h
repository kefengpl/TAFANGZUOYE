#ifndef MONSTER_H
#define MONSTER_H

#include<QPoint>
#include<QPainter>
#include<QVector2D>
#include"navigation.h"
#include <QObject>
#include<math.h>

class Monster : public QObject
{
    Q_OBJECT
public:
    //explicit Monster(QObject *parent = nullptr);
    Monster(Navigation* nowpt,const char *OSpath=":/new/pics/Monster1.png");
    void MonsterMove();
    bool CollisionCircle(QPoint CircleCenter,int Radius);
    static int GetMons();
    static int GetWaves();
    static void AddWaves();

    QPoint GetNowPos();
    int GetNowHP();
    void GetHurt(int attackvalue=2);

    void DrawMonster(QPainter &painter);
private:
    int GeneralHP;
    int NowHP;
    double MoveSpeed;
    int HurtValue;
    bool CanMove;
    bool DeleteMonster;

    Navigation *M_TargetPoint;

    QPixmap M_pic;
    QPoint M_CNpos;

    static const int SIZE;
    static int MonAmount;
    static int MonWave;

public slots:
    void ChangeCanMove();
};

#endif // MONSTER_H
