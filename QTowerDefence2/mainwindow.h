#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QPainter>
#include<QMainWindow>
#include<QPixmap>
#include<QPoint>       //Qpoint可以十分方便地管理游戏中的坐标点
#include<Qlist>        //用Qlist管理主界面中的元素，可以经过相应操作后添加各种类的对象
#include<QTimer>
#include"towerplace.h"
#include"tower.h"
#include"navigation.h"
#include"monster.h"
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
    void mouseDoubleClickEvent(QMouseEvent *event);
   // void timerEvent(QTimerEvent *s);

    void initTowerPlace();
    void initNavigation();
    int initMonsterWave();

public slots:
    void UpdateGame();
  //  void EraseTower(Tower * thetower);
    void EraseMonster(Monster *enemy);
private:
    QList<TowerPlace > TowerPlaceList;
    QList<Tower *> TowerList;
    QList<Navigation *> NavigationList;
    QList<Monster *> MonsterList;

    int TimerId;
    bool WinGame;

private:
   Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
