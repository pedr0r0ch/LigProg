#ifndef __FUNCOES_GLOBAIS__
#define __FUNCOES_GLOBAIS__

#include <iostream>
#include "tipos.h"

void ExibirMensagemErro(tipoErros);

template<typename tipoGenerico>
short getNumero(tipoSinal sinal, tipoGenerico limiteInferior, tipoGenerico limiteSuperior)
{
 if (sinal = habilitado){
    short numeroComSinal;
    return numeroComSinal;
 };
  unsigned short numeroSemSinal;
 return numeroSemSinal;
};

template<typename... tipoGenerico>
void ExibirMensagem(tipoGenerico... argumento)
{
    ((cout << argumento << " "), ...);
    cout << endl;
};
tipoSemestre somaTipo(tipoSemestre, int);

#endif  