#ifndef _FUNCOES_GLOBAIS_
#define _FUNCOES_GLOBAIS_

#include <iostream>
#include "tipos.h"

using namespace std;

template<typename... tipoGenerico>
void ExibirMensagem(tipoGenerico... argumento)
{
    ((cout << argumento << " "), ...);
    cout << endl;
};

void ExibirMensagemErro(tipoErros);

tipoErros getMensagem(float , float, float*);

tipoErros getMensagem(int , int, int*);

string getMensagem();

#endif