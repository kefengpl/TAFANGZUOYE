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
    Tower(QPoint towerpoint,const char *OSpath=":/new/pics/Tower1.png");   //�����������·����Ϊ�˺���ʵ�ֶ�̬
    QPoint GetTowerCNPlace();
    int GetAttackHurt();
    bool GetTowerCanAttack();

    bool CoverAttackRange(const QPoint &thept);                    //����Ƿ��������˹�����Χ
    void ChangeCanAttack(bool attack=true);
    void DrawTower(QPainter & painter);
private:
    QPixmap T_pic;
    QPoint  T_CTpos;   //�����õ����ĵ�����ʾ
    int AttackRange;
    int AttackHurt;
    bool TowerCanAttack;
    static int SIZE;
signals:

public slots:
};

#endif // TOWER_H
