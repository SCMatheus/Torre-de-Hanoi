#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QtCore>
#include<QtGui>
#include<QGraphicsItem>
#include<QGraphicsView>
#include<QGraphicsScene>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);

    ~Dialog();

private slots:


private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H


