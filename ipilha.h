#ifndef IPILHA_H
#define IPILHA_H

template <class tipo>

class IPilha
{
public:
    virtual void inserirDado(tipo dado)=0;
    virtual tipo removerDado()=0;
    virtual tipo acessarDado()=0;
    virtual int quantidadeDeElementos()=0;
    virtual bool eVazia()=0;
};


#endif // IPILHA_H
