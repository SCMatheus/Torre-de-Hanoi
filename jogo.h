#ifndef JOGO_H
#define JOGO_H
#include <disco.h>
#include <QGraphicsScene>



namespace ED1{
class Jogo
{
private:
    QGraphicsScene* cenaJogo;
public:

    Jogo();
    void inserirDisco(int quantidadeDisco);
    QGraphicsScene* getCenaJogo(){return this->cenaJogo;}
};
}


#endif
