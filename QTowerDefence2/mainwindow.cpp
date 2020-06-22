#include "mainwindow.h"
#include "ui_mainwindow.h"

//构造函数用于初始化界面中的各种元素，绘图事件用于绘制各种图片元素
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1024,768);

    initTowerPlace();
    initNavigation();
    initMonsterWave();


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateGame()));
    timer->start(30);

   // WinGame=false;
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
    foreach(Navigation * Navlist,NavigationList)
    {
        Navlist->DrawNavigation(painter);
    }
    foreach(Monster * Monlist,MonsterList)
    {
        Monlist->DrawMonster(painter);
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint PressPos = event->pos();
    auto it=TowerPlaceList.begin();          //Qlist遍历循环一般可以用auto，比其它迭代方式更方便
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

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    QPoint PressPos = event->pos();
    auto it=TowerPlaceList.begin();          //Qlist遍历循环一般可以用auto，比其它迭代方式更方便
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
/*void MainWindow::timerEvent(QTimerEvent *s)
{
    foreach (Monster *enemy, MonsterList)
    {
        enemy->MonsterMove();
    }
    repaint();
}*/


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

void MainWindow::initNavigation()
{
    QPoint PointList[]={
      QPoint(950,150),
      QPoint(793,150),
      QPoint(793,385),
      QPoint(640,385),
      QPoint(640,230),
      QPoint(335,230),
      QPoint(335,535),
      QPoint(635,535),
      QPoint(635,615),
      QPoint(850,615)
    };
    int num=sizeof(PointList)/sizeof(PointList[0]);
    for(int i=0;i<num;i++)
    {
       Navigation * NavPt=new Navigation(PointList[i]);
       NavigationList.push_back(NavPt);
       if(i>=1){
       NavigationList.at(i-1)->SetNextPoint(NavPt);
       NavigationList.at(i)->SetNextPoint(NavPt);

       }
    }

}

int MainWindow::initMonsterWave()
{
    if(Monster::GetWaves()>=6)
    {
        return 0;
    }
    Navigation *StartPoint=NavigationList.first();
    int MonsWaveaInterval[]={
        100,500,600,1000,3000,6000
    };
    for(int i=0;i<6;i++)
    {
        Monster *Mon = new Monster(StartPoint);
        MonsterList.push_back(Mon);
        //Mon->ChangeCanMove();
        QTimer::singleShot(MonsWaveaInterval[i], Mon,SLOT(ChangeCanMove()));
    }
     return 1;
}

void MainWindow::EraseMonster(Monster * enemy)
{

    Q_ASSERT(enemy);
    MonsterList.removeOne(enemy);
    delete enemy;
   if(MonsterList.empty())
    {
        Monster::AddWaves();
        if(initMonsterWave()==0)
        {

            return;
        }
        else
        {
            WinGame=true;
        }
    }
}

/*void MainWindow::EraseTower(Tower * thetower)
{
    Q_ASSERT(thetower);
    MonsterList.removeOne(thetower);
    delete thetower;
}*/

void MainWindow::UpdateGame()
{
    foreach (Monster *enemy, MonsterList)
    {
        enemy->MonsterMove();
        if(enemy->GetNowHP()==0)
        {
            EraseMonster(enemy);
        }
    }
    update();
}
