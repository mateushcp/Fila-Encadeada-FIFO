#ifndef NO_H
#define NO_H

class No
{
private:
    int v;
    No* prox;
public:
    No();
    ~No();
    int obtemValor();
    No* obtemProx();
    No* setProx(No* p);
};


#endif