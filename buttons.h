#ifndef BUTTONS_H
#define BUTTONS_H

#include <QWidget>
#include<QPushButton>
class Buttons : public QPushButton
{
    Q_OBJECT
public:
    Buttons(QString pix);
    int _pos_x;
    int _pos_y;
    //QAbstractButton::clicked(bool checked);
signals:

public slots:
};

#endif // BUTTONS_H
