#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<pilha.h>
#include<QColor>
#include<QtCore>
#include<QtGui>
#include<dialog.h>
#include <QMessageBox>
#include<jogo.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    try{
        ED1::Jogo* aux = new ED1::Jogo;
        int numberDisc = ui->lineEdit->text().toInt();

        aux->inserirDisco(numberDisc);

        ui->graphicsView->setScene(aux->getCenaJogo());

    }catch(QString &erro){

        QMessageBox::information(this, " Erro", erro);
    }





}
