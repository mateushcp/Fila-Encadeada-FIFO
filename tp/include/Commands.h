#ifndef COMMANDS_H
#define COMMANDS_H
#include <iostream>
#include <cstddef>
#include <string>
#include "No.h"

using namespace std;

void flush(Fila* listaFilas, int obtemDigitado, Fila* filaAux);
void send(Fila* listaFilas, int obtemDigitado, Fila* filaAux);
void error(Fila* listaFilas, int obtemDigitado, int id);
void tran(Fila* listaFilas, int obtemDigitado, int id, int id2);
void warn(Fila* listaFilas, int obtemDigitado, int id, int id2);
void info(Fila* listaFilas, int obtemDigitado, int id, string detail);

#endif