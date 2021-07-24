#include <iostream>
#include "Test.h"
#include "Fila.h"
#include <fstream>
#include <string>
#include "Commands.h"

using namespace std;

int main(int argc, char const *argv[])
{   
    fstream comandos(argv[1]);
    string comandosDetail;
    
    int obtemDigitado;
    Fila *listaFilas;
    Fila* historico = new Fila();

    getline(comandos, comandosDetail);
    obtemDigitado = stoi(comandosDetail);
    listaFilas = new Fila[obtemDigitado];

    while (getline(comandos, comandosDetail))
    {
        chamaComando(listaFilas, obtemDigitado, comandosDetail, historico);
    }

    comandos.close();
    delete historico;
    delete[] listaFilas;
    return 0;
}