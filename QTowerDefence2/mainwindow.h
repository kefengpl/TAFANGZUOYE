#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QPainter>
#include <QMainWindow>
#include<QPixmap>
#include<QPoint>       //Qpoint����ʮ�ַ���ع�����Ϸ�е������
#include<Qlist>        //��Qlist�����������е�Ԫ�أ����Ծ�����Ӧ��������Ӹ�����Ķ���
#include"towerplace.h"
#include"tower.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);

    void initTowerPlace();
private:
    QList<TowerPlace > TowerPlaceList;
    QList<Tower *> TowerList;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
