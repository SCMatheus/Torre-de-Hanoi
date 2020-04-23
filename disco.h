#ifndef DISCO_H
#define DISCO_H
#include<QGraphicsRectItem>

namespace ED1{
class Disco: public QGraphicsRectItem
{
private:
    int valorDisco;
public:
    Disco(int x, int y, int larguraDisco, int alturaDisco, int pValorDisco);
    int getValorDisco()const{return valorDisco;}

};
}
#endif // DISCO_H
