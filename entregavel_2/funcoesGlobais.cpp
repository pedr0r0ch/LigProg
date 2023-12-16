#include "funcoesGlobais.h"

void ExibirMensagemErro(tipoErros erro){
    switch ( erro ){
        case(arquivoNEncontrado):
            cout << "Arquivo nao encontrado, insira um arquivo valido ou tente novamente mais tarde." << endl;
            cout << "Pressione Enter para continuar..." << endl;  
            cin.ignore();             
            cin.get();
            break;
            
        case(verticeNExiste):
            ExibirMensagem("Erro! Um ou mais dos vertices solicitados nao existem!");
            break;
    }
};

string getMensagem(){
    string mensagem;

    cout << "Digite o que foi pedido: ";
    cin >> mensagem;

    return mensagem;
};

tipoErros getMensagem(float limiteInferior, float limiteSuperior, float* numero){
    
    float numero_ = 0;
    string mensagem;

    do{
        ExibirMensagem("Por favor digite um numero entre ", limiteInferior, "e ", limiteSuperior);
        cout << "===:";
        cin >> mensagem;

        try {
            numero_ = stof(mensagem);
        } catch (const std::invalid_argument& e) {
            cout << "Erro: A entrada não é um número valido!" << endl;
            return EntradaInvalida;
        }

        if(numero_ < limiteInferior || numero_ > limiteSuperior)
            cout << "O numero nao esta dentro do limite estipulado" << endl;

    }while(numero_ < limiteInferior && numero_ > limiteSuperior);
    
    *numero = numero_;
    return sucesso;
};

tipoErros getMensagem(int limiteInferior, int limiteSuperior, int* numero_){
    
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
            return EntradaInvalida;
        }

        if(numero < limiteInferior && numero > limiteSuperior)
            cout << "O numero nao esta dentro do limite estipulado" << endl;

    }while(numero < limiteInferior || numero > limiteSuperior);
    *numero_ = numero;
    return sucesso;
};