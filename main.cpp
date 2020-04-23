#include "mainwindow.h"
#include <QApplication>
#include<pilha.h>
#include<iostream>
#include<dialog.h>
#include<dialog.h>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
