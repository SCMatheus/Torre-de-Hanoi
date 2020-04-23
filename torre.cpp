#include "torre.h"
namespace ED1{

Torre::Torre():
    torrePilha(new ED1::Pilha<Disco*>()),
    torre(0)
{

}

Torre::Torre(int x, int y, int larguraTorre, int alturaTorre)
{
       setRect(x, y, larguraTorre, alturaTorre);

       this->torrePilha = new ED1::Pilha<Disco*>();
}
void Torre::setPilha(ED1::Pilha<Disco*> torrePilha){
    this->torrePilha = torrePilha;
}
}
