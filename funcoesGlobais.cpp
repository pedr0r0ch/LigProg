
#include "funcoesGlobais.h"

void ExibirMensagemErro(tipoErros erro){
    switch ( erro ){
        case(disciplinaNaoConsta):
            cout << "Disciplina nao consta" << endl;
            break;
        case(periodosInsuficientes):
            ExibirMensagem("periodos cadastrados insuficientes para completar a operacao");
            break;
    }
};

string getMensagem(){
    string mensagem;

    cout << "Digite o que foi pedido: ";
    cin >> mensagem;

    return mensagem;
};

tipoSemestre somaTipo(tipoSemestre semestre, int numero){
    while(numero != 0){
        if(numero < 0){
            switch(semestre.semestre){
                case 1:
                    semestre.semestre = 2;
                    if (semestre.ano == 0){
                        ExibirMensagemErro(anoNaoConsta);
                        exit(anoNaoConsta);
                    };
                    semestre.ano --;

                    numero++;
                    break;
            
                case 2:
                    semestre.semestre = 1;
                    numero++;
                    break;
            };
            
        }; 

            if(numero > 0){
            switch(semestre.semestre){
                case 1:
                    semestre.semestre = 2;   
                    numero--;
                    break;
            
                case 2:
                    semestre.semestre = 1;
                    semestre.ano++;
                    numero--;
                    break;
            }; 
        };

    };
    return semestre;
};

short getMensagem(float limiteInferior, float limiteSuperior){
    
    short numero = 0;
    string mensagem;

    do{
        ExibirMensagem("Por favor digite um numero entre ", limiteInferior, "e ", limiteSuperior);
        cout << "===:";
        cin >> mensagem;

        try {
            numero = stof(mensagem);
        } catch (const std::invalid_argument& e) {
            cout << "Erro: A entrada não é um número valido!" << endl;
            continue;
        }

        if(numero < limiteInferior || numero > limiteSuperior)
            cout << "O numero nao esta dentro do limite estipulado" << endl;

    }while(numero < limiteInferior && numero > limiteSuperior);
    return numero;
}

short getMensagem(int limiteInferior, int limiteSuperior){
    
    short numero = 0;
    string mensagem;

    do{
        ExibirMensagem("Por favor digite um numero entre ", limiteInferior, "e ", limiteSuperior);
        cout << "===:";
        cin >> mensagem;

        try {
            numero = stof(mensagem);
        } catch (const std::invalid_argument& e) {
            cout << "Erro: A entrada não é um número valido!" << endl;
            continue;
        }

        if(numero < limiteInferior && numero > limiteSuperior)
            cout << "O numero nao esta dentro do limite estipulado" << endl;

    }while(numero < limiteInferior || numero > limiteSuperior);
    return numero;
}
