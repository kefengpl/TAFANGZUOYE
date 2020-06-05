#include "towers.h"

Towers::Towers(QObject *parent) : QObject(parent)
{
    initOBJ("TOWER1","png");
    _pos_x=0;
    _pos_y=0;
    hadtower=true;
}
void Towers::showtower(QPainter *painter)
{
    GAMEobj::show(painter);
}
