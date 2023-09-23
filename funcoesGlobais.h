#ifndef __FUNCOES_GLOBAIS__
#define __FUNCOES_GLOBAIS__

#include <iostream>
#include "tipos.h"

template<typename... tipoGenerico>
void ExibirMensagem(tipoGenerico... argumento)
{
    ((cout << argumento << " "), ...);
    cout << endl;
};

void ExibirMensagemErro(tipoErros);

short getMensagem(float , float );

short getMensagem(int , int );

string getMensagem();

tipoSemestre somaTipo(tipoSemestre, int);

#endif  