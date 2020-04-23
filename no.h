#ifndef NO_H
#define NO_H

namespace ED1{
template <class tipo>
class No
{
private:
    tipo info;
    No* ponteiroProximo;
    No* ponteiroAnterior;

public:
    No();
    No(tipo conteudo);
    void setInfo(tipo conteudo) { this->info = conteudo;}
    void setPonteiroProximo(No *pt) { this->ponteiroProximo = pt;}
    void setPonteiroAnterior(No *pt) {this->ponteiroAnterior = pt;}
    tipo getInfo() const { return info; }
    No* getPonteiroProximo() const { return ponteiroProximo;}
    No* getPonteiroAnterior() const { return ponteiroAnterior;}
};
}
template <class tipo>
ED1::No<tipo>::No():
    ponteiroProximo(0),
    ponteiroAnterior(0)
{

}
template<class tipo>
ED1::No<tipo>::No(tipo conteudo):
    ponteiroProximo(0),
    ponteiroAnterior(0),
    info(conteudo)
{

}

#endif // NO_H
