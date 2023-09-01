#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include<Qpoint>
#include<QPixmap>
#include<QPainter>
#include<QMovie>
class Tower : public QObject
{
    Q_OBJECT
public:
    explicit Tower(QObject *parent = nullptr);
    Tower(QPoint towerpoint,const char *OSpath=":/new/pics/Tower1.png");   //可以添加塔的路径，为了后续实现多态
    QPoint GetTowerCNPlace();
    int GetAttackHurt();
    bool GetTowerCanAttack();

    bool CoverAttackRange(const QPoint &thept);                    //检测是否怪物进入了攻击范围
    void ChangeCanAttack(bool attack=true);
    void DrawTower(QPainter & painter);
private:
    QPixmap T_pic;
    QPoint  T_CTpos;   //这里用的中心点来表示
    int AttackRange;
    int AttackHurt;
    bool TowerCanAttack;
    static int SIZE;
signals:

public slots:
};

#endif // TOWER_H
