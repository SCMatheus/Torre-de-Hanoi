#include<disco.h>

ED1::Disco::Disco(int x, int y, int larguraDisco, int alturaDisco, int pValorDisco):
    valorDisco(pValorDisco)
{
    setRect(x, y, larguraDisco, alturaDisco);
}



