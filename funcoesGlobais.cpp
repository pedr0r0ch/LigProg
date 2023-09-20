
#include "funcoesGlobais.h"

void ExibirMensagemErro(tipoErros erro){
    switch ( erro ){
        case(disciplinaNaoConsta):
            cout << "Disciplina nao consta" << endl;
            break;
    }
};

tipoSemestre somaTipo(tipoSemestre semestre, int numero){
    
    while(numero != 0){
        switch(semestre.semestre){
            case 1:
                semestre.semestre = 2;
                if(numero > 0){
                    if (semestre.ano = 0){
                        ExibirMensagemErro(anoNaoConsta);
                        exit(anoNaoConsta);
                    };
                    semestre.ano --;
                    numero --;
                };
                break;
        
            case 2:
                semestre.semestre = 1;
                if(numero < 0){
                    semestre.ano ++;
                    numero ++;
                };
                break;
        }    
    }
    return semestre;
};

/* ------------------- FUNCAO TAMPLATE NAO SE COMPILA
template<typename... tipoGenerico>
void ExibirMensagem (tipoGenerico... argumento){
    ((cout << argumento << " "), ...);
    cout << endl;
};*/
