#ifndef LISTA_H
#define LISTA_H
#include<no.h>
#include<QString>


namespace ED1{

template <class tipo>

class Lista
{
private:
    int quantidadeDeNos;
    No<tipo>* ponteiroInicio;
    No<tipo>* ponteiroFim;


public:
    Lista();
    Lista(tipo info);

    bool listaVazia() const{return (quantidadeDeNos == 0);}
    void ColocarInicio(tipo info);
    tipo RemoverInicio();
    void ColocarFim(tipo info);
    tipo RemoverFim();

    void setQtdNo(int QtdNo){this->quantidadeDeNos= QtdNo;}
    int getQtdNo() const { return quantidadeDeNos;}
    void setPonteiroInicio(No<tipo> *ptInicio) {this->ponteiroInicio = ptInicio;}
    void setPonteiroFim(No<tipo> *ptFim) { this->ponteiroFim = ptFim;}

    void ColocarMeio(tipo info, int posicao);
    tipo RemoverMeio(int posicao);
    void ColocarOrdenado(tipo info);
    tipo operator[](int posicao);
    tipo RemoverInfo(tipo info);
    tipo AcessarInfo(tipo info);



    ~Lista();
};
}
#include "lista.h"

template <class tipo>
ED1::Lista<tipo>::Lista():

    ponteiroFim(0),

    ponteiroInicio(0),

    quantidadeDeNos(0)

{

}

template <class tipo>
ED1::Lista<tipo>::Lista(tipo info)
{
    ColocarInicio(info);
}

template <class tipo>
void ED1::Lista<tipo>::ColocarInicio(tipo info)
{
    No<tipo>* ptCriar = new No<tipo>(info);

    if(listaVazia())
    {
        ptCriar->setPonteiroProximo(ptCriar);

        ptCriar->setPonteiroAnterior(ptCriar);

        setPonteiroInicio(ptCriar);

        setPonteiroFim(ponteiroInicio);
    }
    else{

        ptCriar->setPonteiroProximo(ponteiroInicio);

        ponteiroInicio->setPonteiroAnterior(ptCriar);

        ponteiroInicio = ptCriar;

        ponteiroFim->setPonteiroProximo(ponteiroInicio);

        ponteiroInicio->setPonteiroAnterior(ponteiroFim);
    }
    quantidadeDeNos++;

}

template <class tipo>
tipo ED1::Lista<tipo>::RemoverInicio()
{
    if(getQtdNo() == 0) throw QString ("Lista vazia! Sem elementos para remoção!");

    No<tipo> *ptAux = ponteiroInicio;

    tipo valor;

    if(getQtdNo() == 1)
    {
        setPonteiroInicio(0);

        setPonteiroFim(ponteiroInicio);

        ptAux->setPonteiroProximo(0);

        ptAux->setPonteiroAnterior(0);

        valor = ptAux->getInfo();

        delete ptAux;
    }
    else{
        ponteiroInicio = ptAux->getPonteiroProximo();

        ponteiroFim->setPonteiroProximo(ponteiroInicio);

        ponteiroInicio->setPonteiroAnterior(ponteiroFim);

        ptAux->setPonteiroProximo(0);

        ptAux->setPonteiroAnterior(0);

        valor = ptAux->getInfo();

        delete ptAux;
    }
    quantidadeDeNos--;

    return valor;
}

template <class tipo>
void ED1::Lista<tipo>::ColocarFim(tipo info)
{
    No<tipo>* ptCriar = new No<tipo>(info);

    if(getQtdNo() == 0)
    {
        ptCriar->setPonteiroProximo(ptCriar);

        ptCriar->setPonteiroAnterior(ptCriar);

        setPonteiroInicio(ptCriar);

        setPonteiroFim(ponteiroInicio);
    }
    else{

        ptCriar->setPonteiroAnterior(ponteiroFim);

        ponteiroFim->setPonteiroProximo(ptCriar);

        ponteiroFim = ptCriar;

        ponteiroFim->setPonteiroProximo(ponteiroInicio);

        ponteiroInicio->setPonteiroAnterior(ponteiroFim);
    }
    quantidadeDeNos++;
}

template <class tipo>
tipo ED1::Lista<tipo>::RemoverFim()
{
    if(quantidadeDeNos == 0) throw QString ("Lista vazia! Sem elementos para remoção!");

    No<tipo>* ptAux = ponteiroFim;

    tipo valor;

    if(quantidadeDeNos == 1)
    {
        setPonteiroInicio(0);

        setPonteiroFim(ponteiroInicio);

        ptAux->setPonteiroProximo(0);

        ptAux->setPonteiroAnterior(0);

        valor = ptAux->getInfo();

        delete ptAux;
    }
    else{

        ponteiroFim = ptAux->getPonteiroAnterior();

        ponteiroFim->setPonteiroProximo(ponteiroInicio);

        ponteiroInicio->setPonteiroAnterior(ponteiroFim);

        ptAux->setPonteiroProximo(0);

        ptAux->setPonteiroAnterior(0);

        valor = ptAux->getInfo();

        delete ptAux;
    }
    quantidadeDeNos--;

    return valor;
}

template <class tipo>
ED1::Lista<tipo>::~Lista()
{
    while(!(listaVazia())){
        RemoverInicio();
    }
}

template <class tipo>
void ED1::Lista<tipo>::ColocarMeio(tipo info, int posicao)
{
    if(posicao <= 0 || posicao > quantidadeDeNos+1) throw QString ("Posição Inválida para Inserção!");

    No<tipo>* ptCriar = new No<tipo>(info);

    if(posicao == 1)
    {
        ColocarInicio(info);
    }
    else{
        if(posicao == quantidadeDeNos+1)
        {
            ColocarFim(info);
        }
        else{
            No<tipo> *ptAux = ponteiroInicio;

            for(int i =1; i < posicao; i++)
            {
                ptAux = ptAux->getPonteiroProximo();
            }

            ptAux->getPonteiroAnterior()->setPonteiroProximo(ptCriar);

            ptCriar->setPonteiroAnterior(ptAux->getPonteiroAnterior());

            ptAux->setPonteiroAnterior(ptCriar);

            ptCriar->setPonteiroProximo(ptAux);

            quantidadeDeNos++;
        }
    }

}

template <class tipo>
tipo ED1::Lista<tipo>::RemoverMeio(int posicao)
{
    if(posicao <=0 || posicao > quantidadeDeNos) throw QString ("Posição Inválida para Remoção!");

    tipo valor = 0;

    if(posicao == 1)
    {
       valor = RemoverInicio();
    }
    else{
        if(posicao == quantidadeDeNos)
        {
            valor = RemoverFim();
        }
        else{
            No<tipo> *ptAux = ponteiroInicio;

            for(int i = 1; i < posicao; i++)
            {
                ptAux = ptAux->getPonteiroProximo();
            }

            valor = ptAux->getInfo();

            ptAux->getPonteiroAnterior()->setPonteiroProximo(ptAux->getPonteiroProximo());

            ptAux->getPonteiroProximo()->setPonteiroAnterior(ptAux->getPonteiroAnterior());

            ptAux->setPonteiroProximo(0);

            ptAux->setPonteiroAnterior(0);

            delete ptAux;

            quantidadeDeNos--;
        }
    }


    return valor;

}

template <class tipo>
void ED1::Lista<tipo>::ColocarOrdenado(tipo info)
{
    if(quantidadeDeNos == 0)
    {
        ColocarInicio(info);

    }else{
        No<tipo> *ptAux = ponteiroInicio;

        No<tipo> *ptCriar = new No<tipo>(info);

        if(quantidadeDeNos == 1)
        {
            if(ptCriar->getInfo() >= ptAux->getInfo())
            {
                ColocarFim(info);
            }
            else{
                ColocarInicio(info);
            }
        }
        else{
            if(quantidadeDeNos > 1)
            {
                No<tipo> *ptAux = ponteiroInicio;

                No<tipo> *ptCriar = new No<tipo>(info);

                while(ptAux->getPonteiroProximo() != ponteiroInicio && ptCriar->getInfo() > ptAux->getInfo())
                {
                    ptAux = ptAux->getPonteiroProximo();
                }

                if(ptAux->getPonteiroProximo() == ponteiroInicio && ptCriar->getInfo() > ptAux->getInfo())
                {
                    ColocarFim(info);
                }else{
                    ptCriar->setPonteiroAnterior(ptAux->getPonteiroAnterior());

                    ptAux->getPonteiroAnterior()->setPonteiroProximo(ptCriar);

                    ptAux->setPonteiroAnterior(ptCriar);

                    ptCriar->setPonteiroProximo(ptAux);

                    if(ptAux == ponteiroInicio)
                        setPonteiroInicio(ptCriar);

                    quantidadeDeNos++;

                }
            }
        }
    }
}


template <class tipo>
tipo ED1::Lista<tipo>::operator [](int posicao)
{
    if(posicao <= 0 || posicao > quantidadeDeNos) throw QString ("Posição Inválida para acesso!");

    No<tipo> *ptAux = ponteiroInicio;

    tipo infoAcesso;

    for(int i = 1; i < posicao; i++)
    {
        ptAux = ptAux->getPonteiroProximo();

    }

    infoAcesso = ptAux->getInfo();

    return infoAcesso;
}

template <class tipo>
tipo ED1::Lista<tipo>::RemoverInfo(tipo info)
{
    if(quantidadeDeNos == 0) throw QString ("Lista Vazia! Não há elementos para remoção!");

    No<tipo> *ptAux = ponteiroInicio;

    int posicao = 1;

    tipo valor;

    for(int i = 1; i < quantidadeDeNos; i++)
    {
        if(info == ptAux->getInfo())
        {
            valor = RemoverMeio(posicao);

            return valor;

        }else{
            ptAux = ptAux->getPonteiroProximo();

            posicao++;
        }
    }

    throw QString ("Elemento não pertence a lista!");

}

template <class tipo>
tipo ED1::Lista<tipo>::AcessarInfo(tipo info)
{
   if(quantidadeDeNos == 0) throw QString ("Lista vazia! Sem elementos para acesso!");

   No<tipo> *ptAux = ponteiroInicio;

   int posicao = 1;

   for(int i = 1; i < quantidadeDeNos; i++)
   {
       if(info == ptAux->getInfo())
       {
           return posicao;

       }else{
           ptAux = ptAux->getPonteiroProximo();

           posicao++;
       }
   }

   throw QString ("Elemento não pertence a lista!");
}


#endif // LISTA_H
