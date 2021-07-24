#ifndef NO_H
#define NO_H
#include <iostream>
#include <cstddef>
#include <string>
#include "Fila.h"

using namespace std;

class No
{
private:
    string v;
    No* prox;
public:
    No();
    No(string v);
    ~No();
    string obtemValor();
    No* obtemProx();
    No* setProx(No* p);


    friend class Fila;
};


#endif