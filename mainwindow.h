#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"gameworld.h"
#include <QImage>
#include<QTimer>
#include<QPushButton>
#include <QPainter>
#include"monsters.h"
#include<QKeyEvent>
#include<monsters.h>
#include"towers.h"
#include<QList>
#include"buttons.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *e);
    void timerEvent(QTimerEvent *s);
  //  Gamewindow * scene=new Gamewindow;
   // void keyPressEvent(QKeyEvent *e);
    void set_tower();
    void set_tower2();
private slots:
    void on_exit_clicked();

    void on_pushButton_clicked();

    void on_Pause_released();

    void on_Start_clicked();

private:
    Ui::MainWindow *ui;
    GameWorld _game;
    int timerID;
    int steps=0;
    QList<Towers *> tower_list;
    QList<Buttons *> button_list;
};

#endif // MAINWINDOW_H
