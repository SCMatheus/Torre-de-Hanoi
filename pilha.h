#ifndef PILHA_H
#define PILHA_H
#include<ipilha.h>
#include<lista.h>
namespace ED1{
template <class tipo>
class Pilha: public IPilha<tipo>
{
public:
    Pilha(){composicao = new ED1::Lista<tipo>;}//Chama construtor Pai e inicializa o aributo do tipo Lista
    void inserirDado(tipo dado){composicao->ColocarInicio(dado);}//push()
    tipo removerDado(){return composicao->RemoverInicio();}//pop()
    tipo acessarDado(){return (*composicao)[1];}//top()
    int quantidadeDeElementos(){return composicao->getQtdNo();}//quantidadeDeElementos
    bool eVazia(){return composicao->listaVazia();}//Lista Vazia

private:
    ED1::Lista<tipo> *composicao;

};
}

#endif // PILHA_H
