#include "dialog.h"
#include "ui_dialog.h"
#include<jogo.h>

Dialog::Dialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Dialog)

{
    ui->setupUi(this);   
}

void Dialog::on_pushButton_clicked()
{
    ED1::Jogo teste;

    teste.inserirDisco(ui->lineEdit->text().toInt());

    ui->Jogo->setScene(teste.getCenaJogo());
}

Dialog::~Dialog()
{
    delete ui;
}

