#include <iostream>
#include "Commands.h"
#include <string>

using namespace std;

void chamaComando(Fila* listaFilas, int obtemDigitado, string detail, Fila* filaAux)
{   
    int obtemComandos1;
    int obtemComandos2;
    string auxString;

    if (detail.substr(0,4) == "INFO")
    {   
        cout << "entrei info" << endl;
        obtemComandos1 = stoi(detail.substr(5,6));
        auxString = detail.substr(8, detail.size()-9);
        info(listaFilas, obtemDigitado, obtemComandos1, auxString);
    }
    else if (detail.substr(0,4) == "WARN")
    {
        cout << "entrei warn" << endl;
        obtemComandos1 = stoi(detail.substr(5,6));
        obtemComandos2 = stoi(detail.substr(7,8));
        warn(listaFilas, obtemDigitado, obtemComandos1, obtemComandos2);
    }
    else if (detail.substr(0,4) == "TRAN")
    {
        cout << "entrei tran" << endl;
        obtemComandos1 = stoi(detail.substr(5,6));
        obtemComandos2 = stoi(detail.substr(7,8));
        tran(listaFilas, obtemDigitado, obtemComandos1, obtemComandos2);
    }
    else if (detail.substr(0,4) == "ERRO")
    {
        cout << "entrei erro" << endl;
        obtemComandos1 = stoi(detail.substr(5,6));
        error(listaFilas, obtemDigitado, obtemComandos1);
    }
    else if (detail.substr(0,4) == "SEND")
    {
        cout << "entrei send" << endl;
        send(listaFilas, obtemDigitado, filaAux);
    }
    else if (detail.substr(0,5) == "FLUSH")
    {
        cout << "entrei flush" << endl;
        flush(listaFilas, obtemDigitado, filaAux);
    }
}
void info(Fila* listaFilas, int obtemDigitado, int id, string detail) 
{
    listaFilas[id].enfileirarElemento(detail);
}
void flush(Fila* listaFilas, int obtemDigitado, Fila* filaAux)
{
    filaAux->ImprimeHistorico();
    for (int i = 0; i < obtemDigitado; i++)
    {
        listaFilas[i].ImprimeHistorico();
    }
}
void send(Fila* listaFilas, int obtemDigitado, Fila* filaAux)
{
    string aux;
    for (int i = 0; i < obtemDigitado; i++)
    {
        aux = listaFilas[i].desenfileirarElemento();
        filaAux->enfileirarElemento(aux);
    }
}
void error(Fila* listaFilas, int obtemDigitado, int id)
{
    cout << "ERRO " << id << endl;
    listaFilas[id].ImprimeHistorico();
}
void tran(Fila* listaFilas, int obtemDigitado, int id, int id2)
{   
    string detail;
    while (!listaFilas[id].vazia())
    {
         detail = listaFilas[id].desenfileirarElemento();
         listaFilas[id2].enfileirarElemento(detail);
    }
    listaFilas[id].limparFila();
}
void warn(Fila* listaFilas, int obtemDigitado, int id, int id2)
{
    No* aux1;
    No* aux2;
    No* aux3;
    aux1 = listaFilas[id].getCabeca();
    aux3 = aux1;
    for (int i = 0; i < id2 -1; i++)
    {
        aux1 = aux1->obtemProx();
    }
    aux2 = aux1->obtemProx();
    aux1->setProx(aux2->obtemProx());
    listaFilas[id].setCabeca(aux2);
    listaFilas[id].getCabeca()->setProx(aux3);
    delete aux1;
}