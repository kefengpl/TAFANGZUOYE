#ifndef TOWERPLACE_H
#define TOWERPLACE_H
#include<QPoint>
#include<QPixmap>
#include<QPainter>

class TowerPlace
{
public:
    TowerPlace(QPoint position);
    bool CheckHasTower();
    void ChangeHasTower(bool hastow=true);
    QPoint CenterPoint();
    bool CoverTP(const QPoint &thept);
    void DrawTP(QPainter &painter);  //»­³öËþµÄ»ù×ù



private:
    QPoint TP_pos;
    QPixmap TP_pic;
    bool HasTower;
    static int SIZE;
};

#endif // TOWERPLACE_H
