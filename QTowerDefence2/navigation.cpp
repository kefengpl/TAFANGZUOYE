#include "navigation.h"

Navigation::Navigation(QPoint pos):N_pos(pos)
{

    N_NextPoint=NULL;
}
QPoint Navigation::GetPos()
{
    return N_pos;
}
Navigation *Navigation::GetNextPoint()
{
    return N_NextPoint;
}
void Navigation::SetNextPoint(Navigation * TempNav)
{
    N_NextPoint=TempNav;
}
void Navigation::DrawNavigation(QPainter & painter)
{
    painter.save();
    painter.setPen(Qt::red);
    painter.drawEllipse(N_pos,12,12);
    painter.drawEllipse(N_pos,6,6);
    if(N_NextPoint)
    {
        painter.drawLine(N_pos,N_NextPoint->GetPos());
    }
    painter.restore();
}
