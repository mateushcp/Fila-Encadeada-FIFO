
#include <string>
#include "No.h"

using namespace std;

 No::No(string v)
 {
     this->v = v;
     this->prox = NULL;
 }
 No::No()
 {
     this->v = -1;
 }
 No::~No()
 {
     delete this->prox;
 }
 string No::obtemValor()
 {
     return v;
 }
 No *No::obtemProx()
 {
     return prox;
 }
 No *No::setProx(No *p)
 {
     prox = p;
     return p;
 }
