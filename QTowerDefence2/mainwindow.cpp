#include "mainwindow.h"
#include "ui_mainwindow.h"

//���캯�����ڳ�ʼ�������еĸ���Ԫ�أ���ͼ�¼����ڻ��Ƹ���ͼƬԪ��
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1024,768);
    initTowerPlace();

}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);


    QPixmap BackGround(":/new/pics/BackGround.png");
    painter.drawPixmap(0,0,BackGround);

    foreach(TowerPlace TPlist,TowerPlaceList)
    {
        TPlist.DrawTP(painter);
    }
    foreach(Tower* Tlist,TowerList)
    {
        Tlist->DrawTower(painter);
    }


}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint PressPos = event->pos();
    auto it=TowerPlaceList.begin();          //Qlist����ѭ��һ�������auto��������������ʽ������
    while(it!=TowerPlaceList.end())
    {
        if(it->CoverTP(PressPos)&&!it->CheckHasTower()){
            it->ChangeHasTower();
            Tower *Atower = new Tower(it->CenterPoint());
            TowerList.push_back(Atower);
            update();
            break;
        }
        it++;
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initTowerPlace()
{
    QPoint PointList[]={

      QPoint(275,100),
      QPoint(350,100),
      QPoint(425,100),
      QPoint(665,175),
      QPoint(665,250),
      QPoint(668,408),
      QPoint(590,408),
      QPoint(745,408)
    };
    int num=sizeof(PointList)/sizeof(PointList[0]);
    for (int i=0;i<num;i++)
    {

        TowerPlaceList.push_back(PointList[i]);
    }
}
