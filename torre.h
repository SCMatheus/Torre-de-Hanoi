#ifndef TORRE_H
#define TORRE_H
#include<pilha.h>
#include<QgraphicsRectItem>
#include<disco.h>


namespace ED1{
class Torre: public QGraphicsRectItem
{
private:
    ED1::Pilha<Disco*> *torrePilha;
    QGraphicsRectItem *torre;

public:
    Torre();
    Torre(int x, int y, int larguraDisco, int alturaDisco);
    void setPilha(ED1::Pilha<Disco*>);
};
}
#endif // TORRE_H
