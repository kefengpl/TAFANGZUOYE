#ifndef NAVIGATION_H
#define NAVIGATION_H
#include<QPoint>
#include<QPainter>
class Navigation
{
public:
    Navigation(QPoint pos);
    QPoint GetPos();
    Navigation* GetNextPoint();
    void SetNextPoint(Navigation *TempNav);

    void DrawNavigation(QPainter & painter);
private:
    QPoint N_pos;
    Navigation* N_NextPoint;
};

#endif // NAVIGATION_H
