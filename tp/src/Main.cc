#include "Test.h"
#include "Fila.h"
#include <iostream>
#include "Commands.h"

int main(int argc, char *argv[])
{

    Fila *listaFilas;

    int obtemDigitado;
    cin >> obtemDigitado;
    listaFilas = new Fila[obtemDigitado];

    Fila* historico = new Fila();
    
    listaFilas[2].enfileirarElemento("2");
    listaFilas[1].enfileirarElemento("1");
    listaFilas[1].enfileirarElemento("2");
    listaFilas[1].enfileirarElemento("3");
    listaFilas[1].enfileirarElemento("4");
    listaFilas[1].enfileirarElemento("5");

    warn(listaFilas, obtemDigitado, 1, 3);

    // listaFilas[1].ImprimeHistorico();


    // cout << f.obtemTamanho();

    // f.limparFila();

    // f.mostrarFila();

    // listaFilas[2].ImprimeHistorico();
    // listaFilas[1].ImprimeHistorico();
    //    f.~Fila();

    delete historico;
    delete[] listaFilas;
    return 0;
}