#include "buttons.h"
#include<QPixmap>
Buttons::Buttons(QString pix) : QPushButton(0)
{
    QPixmap thebut(pix);
    thebut=thebut.scaled(96,96, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);   //½«Í¼Æ¬Ñ¹Ëõ³É32*32ÏñËØµÄÍ¼Æ¬
    this->setFixedSize(96,96);
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(thebut);
    this->setIconSize(QSize(96,96));

}
