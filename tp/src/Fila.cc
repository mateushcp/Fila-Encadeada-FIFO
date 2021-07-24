#include "Fila.h"
#include <string>

using namespace std;

Fila::Fila()
{
    cabeca = new No();
    cauda = cabeca;
    tamanho = 0;
}
Fila::~Fila()
{
    if (!vazia())
    {
        desenfileirarElemento();
    }
}
No* Fila::getCabeca()
{
    return this->cabeca;
}
void Fila::setCabeca(No* aux)
{
    this->cabeca = aux;
}
int Fila::obtemTamanho()
{
    return tamanho;
}
void Fila::limparFila()
{
    No *novo = cabeca->prox;
    while (novo != NULL)
    {
        cabeca->prox = novo->prox;
        novo = cabeca->prox;
    }
    cauda = cabeca;
    tamanho = 0;
}
bool Fila::vazia()
{
    return tamanho == 0;
}
void Fila::enfileirarElemento(string v)
{
    No *novoNo = new No(v);
    if (vazia())
    {
        cabeca = novoNo;
        cauda = novoNo;
    }
    else
    {
        cauda->setProx(novoNo);
        cauda = novoNo;
    }
    tamanho++;
}
string Fila::desenfileirarElemento()
{   
    string aux;
    if (!vazia())
    {
        aux = cabeca->v;
        cabeca = cabeca->obtemProx();
        if (cabeca == NULL)
        {
            cauda = NULL;
        }
    }
    tamanho--;
    return aux;
}

void Fila::ImprimeHistorico()
{
    if (tamanho > 0)
    {
        No *celula;

        celula = cabeca;
        while (celula != NULL)
        {
            cout << celula->obtemValor() << endl;
            celula = celula->prox;
        }
    }
}
