#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QMovie>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setFixedSize(1344,960);        //设定固定大小的窗口，游戏格数14*10(*64)，对应像素1344*960
  // move(0,0); //设置窗口初始位置
    setWindowTitle("PROTECT CASTLE");
   // timerID=startTimer(90);
    _game.initWorld();//TODO 应该是输入有效的地图文件
    connect(ui->exit,SIGNAL(clicked()),this,SLOT(on_exit_clicked()));
    connect(ui->Start,SIGNAL(clicked()),this,SLOT(on_Start_clicked()));
    connect(ui->Pause,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->Pause,SIGNAL(relsased()),this,SLOT(on_Pause_released()));

    Buttons *btn1= new Buttons(":/new/prefix1/BASEBUTTON.png");
    btn1->setParent(this);
    btn1->move(5*96,3*96);
    btn1->setFlat(true);
    button_list.push_back(btn1);

    Buttons *btn2= new Buttons(":/new/prefix1/BASEBUTTON.png");
    btn2->setParent(this);
    btn2->move(6*96,3*96);
    btn2->setFlat(true);
    button_list.push_back(btn2);

    connect(button_list[0],&Buttons::clicked,this,&MainWindow::set_tower);
    connect(button_list[1],&Buttons::clicked,this,&MainWindow::set_tower2);
}
void MainWindow::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
  //  pa->setCompositionMode(QPainter::CompositionMode_SourceOver);
    this->_game.show(pa);
    pa->end();
    pa->begin(this);
    foreach(Towers * tower,tower_list)
    {
        tower->showtower(pa);
    }
    pa->end();
    delete pa;
}
void MainWindow::timerEvent(QTimerEvent *s)
{
    int dir;
    if(steps<9*2||(steps>=22*2&&steps<=28*2)||(steps>=53*2&&steps<=64*2)||(steps>=77*2&&steps<=96*2))
    {
        dir=4;
    }
    if((steps>=10*2&&steps<=21*2)||(steps>=65*2&&steps<=76*2))
    {
        dir=2;
    }
    if(steps>=29*2&&steps<=52*2)
    {
        dir=1;
    }
    if(steps==9*2)
    {
        dir=0;
    }
    if(steps>96*2)
    {
        _game.tothecastle=true;
        killTimer(timerID);
    }
    steps=steps+1;
    _game.themove(dir);
    repaint();
}
/*void MainWindow::keyPressEvent(QKeyEvent *e)
{
    //direction = 1,2,3,4 for 上下左右
    if(e->key() == Qt::Key_A)
    {
        this->_game.themove(3,1);
    }
    else if(e->key() == Qt::Key_D)
    {
       this->_game.themove(4,1);
    }
    else if(e->key() == Qt::Key_W)
    {
        this->_game.themove(1,1);
    }
    else if(e->key() == Qt::Key_S)
    {
        this->_game.themove(2,1);
    }
    this->repaint();
}*/
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exit_clicked()
{
    this->close();
}
void MainWindow::set_tower()
{
    Towers *a_tower=new Towers;
    a_tower->setposX(5*8);
    a_tower->setposY(3*8);
    tower_list.push_back(a_tower);
    update();
}

void MainWindow::set_tower2()
{
    Towers *a_tower=new Towers;
    a_tower->setposX(6*8);
    a_tower->setposY(3*8);
    tower_list.push_back(a_tower);
    update();
}
void MainWindow::on_pushButton_clicked()
{
     killTimer(timerID);
}

void MainWindow::on_Pause_released()
{
    startTimer(timerID);
}

void MainWindow::on_Start_clicked()
{
    timerID=startTimer(110);
}
