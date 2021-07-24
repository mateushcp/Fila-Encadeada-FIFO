#ifndef FILA_H
#define FILA_H
#include <iostream>
#include <cstddef>
#include <string>
#include "No.h"

using namespace std;

class No;

class Fila
{
private:
    No* cabeca;
    No* cauda;
    int tamanho;
public:
    Fila();
    ~Fila();
    bool vazia();
    void mostrarFila();
    void enfileirarElemento(string v);
    string desenfileirarElemento();
    void ImprimeHistorico();
    int obtemTamanho();
    void limparFila();
    No* getCabeca();
    void setCabeca(No* aux);
};

#endif