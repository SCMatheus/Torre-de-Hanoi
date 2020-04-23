#include "jogo.h"
#include<QDebug>
#include<QtCore>
#include<QtGui>
#include<torre.h>

ED1::Jogo::Jogo()
{
    this->cenaJogo = new QGraphicsScene;
}

void ED1::Jogo::inserirDisco(int quantidadeDisco)
{
    int x = 0;
    int y = 0;
    int larguraDisco = 10;
    int alturaDisco = 10;
    int auxL = 35;
    int auxL2 = 90;

    auxL = auxL +(quantidadeDisco*5);

    auxL2 = auxL2 + (15*(quantidadeDisco-1));

    QBrush corDisco(Qt::AutoColor);

    QPen corBordaDisco(Qt::black);

    //Setando Torres e Bases

    Torre *objTorre = new Torre(2.5, y, larguraDisco/2, quantidadeDisco*10+10);

    this->cenaJogo->addRect((quantidadeDisco+1)*(-5),quantidadeDisco*10+10, quantidadeDisco*10+20, alturaDisco/2, corBordaDisco, corDisco);

    Torre *objTorre2 = new Torre(auxL+(quantidadeDisco*5)+7.5, y, larguraDisco/2, quantidadeDisco*10+10);

    this->cenaJogo->addRect(auxL, quantidadeDisco*10+10, quantidadeDisco*10+20, alturaDisco/2, corBordaDisco, corDisco);

    Torre *objTorre3 = new Torre(auxL2+(quantidadeDisco*5)+7.5, y, larguraDisco/2, quantidadeDisco*10+10);

    this->cenaJogo->addRect(auxL2, quantidadeDisco*10+10, quantidadeDisco*10+20, alturaDisco/2, corBordaDisco, corDisco);

    this->cenaJogo->addItem(objTorre);

    this->cenaJogo->addItem(objTorre2);

    this->cenaJogo->addItem(objTorre3);

    objTorre->setActive(true);
    //Setando Discos
    ED1::Pilha<Disco*> *pilhaAux = 0;
    pilhaAux = new ED1::Pilha<Disco*>();
    for(int i = 0; i< quantidadeDisco; i++)
    {
        x = x-5;
        y = y+10;
        larguraDisco = larguraDisco + 10;

        Disco* objDisco = new Disco(x, y, larguraDisco, alturaDisco, i);
        pilhaAux->inserirDado(objDisco);
        this->cenaJogo->addItem(objDisco);
    }
    for(int i = pilhaAux->quantidadeDeElementos(); i != 0; i--)
    {

    }
}
