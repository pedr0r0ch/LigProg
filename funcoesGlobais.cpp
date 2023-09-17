
#include "funcoesGlobais.h"

void ExibirMensagemErro(tipoErros erro){
    switch ( erro ){
        case(disciplinaNaoConsta):
            cout << "Disciplina nao consta" << endl;
            break;
    }
};

/*
template<typename... tipoGenerico>
void ExibirMensagem (tipoGenerico... argumento){
    ((cout << argumento << " "), ...);
    cout << endl;
};*/
