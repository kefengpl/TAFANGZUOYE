#include "mainwindow.h"
#include <QApplication>
#include <QImage>
#include<iostream>
#include<Qpainter>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
