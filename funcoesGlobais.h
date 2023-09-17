#ifndef __FUNCOES_GLOBAIS__
#define __FUNCOES_GLOBAIS__

#include <iostream>
#include "tipos.h"

void ExibirMensagemErro(tipoErros);

template<typename... tipoGenerico>
void ExibirMensagem(tipoGenerico... argumento)
{
    ((cout << argumento << " "), ...);
    cout << endl;
};

#endif  