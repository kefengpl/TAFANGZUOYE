#ifndef TOWERS_H
#define TOWERS_H

#include <QObject>
#include"gameobj.h"
#include<QPainter>
class Towers : public QObject,public GAMEobj   //防御塔类，这里作为物体类
{
    Q_OBJECT
public:
    explicit Towers(QObject *parent = nullptr);
    void showtower(QPainter *painter);
    bool hadtower;
signals:

public slots:
};

#endif // TOWERS_H
