#include <iostream>
#include <limits>
#include <vector>
#include <string>

#include "funcoesGlobais.h"
#include "classeHistorico.h"
#include "tipos.h"

using namespace std;

string getMensagem(string exibir){
    
    string mensagem;

    cout << exibir;
    cin >> mensagem;

    return mensagem;
};

double getMensagem(string mensagem, double limiteInferior, double limiteSuperior){
    
    double resposta = limiteInferior - 1;
    string resposta_;

    do{
        cout << mensagem;
        cin >> resposta_;

        try {
            resposta = stod(resposta_);
        } catch (const std::invalid_argument& e  ) {
            cout << "Erro: A entrada não é um número valido! Tente novamente" << endl;
            continue;
        }

        if(resposta < limiteInferior || resposta > limiteSuperior){
            cout << "O numero nao esta dentro do limite estipulado" << endl;
            cout << "Somente sao aceitos numeros maiores que " << limiteInferior << " e maiores que " << limiteSuperior << "!"<< endl;
        }

    }while(resposta < limiteInferior || resposta > limiteSuperior);

    return resposta;
};

int getMensagem(string mensagem, int limiteInferior, int limiteSuperior){
    
    int resposta = limiteInferior-1;
    string resposta_;

    do{
        cout << mensagem;
        cin >> resposta_;

        try {
            resposta = stoi(resposta_);
        } catch (const std::invalid_argument& e) {
            cout << "Erro: A entrada não é um número valido! Tente novamente" << endl;
            continue;
        }

        if(resposta < limiteInferior || resposta > limiteSuperior){
            cout << "O numero nao esta dentro do limite estipulado" << endl;
            cout << "Somente sao aceitos numeros maiores que " << to_string(limiteInferior) << " e maiores que " << to_string(limiteSuperior) << "!"<< endl;
        }

    }while(resposta < limiteInferior || resposta > limiteSuperior);

    return resposta;
};

void getMensagem(){
    cout << '\n' << endl;
    cout << "Pressione enter para concluir a operacao";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    //numeric_limits<streamsize>::max() eh o tamanho maximo do buffer para ser limpo pelo ignore()
};

string getPeriodo(){

    string mensagem;
    int mensagem_ = -1;
    string mensagemRetorno = "";

    cout << "Digite o periodo em que a disciplina foi cursada" << endl;
    
    do{
        cout << "Digite o ano:";
        cin >> mensagem;

        try {
            mensagem_ = stoi(mensagem);
        } catch (const std::invalid_argument& e) {
            cout << "Erro: A entrada não é um número valido! Tente novamente" << endl;
            continue;
        }

        if(mensagem_ < 0)
            cout << "Nao sao permitidos anos negativos!" << endl;
    
    }while(mensagem_ < 0);
    
    mensagemRetorno = mensagem + '.';
    mensagem_ = -1;
    mensagem = "";

    do{
        cout << "Digite o semestre:";
        cin >> mensagem;

        try {
            mensagem_ = stoi(mensagem);
        } catch (const std::invalid_argument& e) {
            cout << "Erro: A entrada não é um número valido! Tente novamente" << endl;
            continue;
        }

        if(mensagem_ != 2 && mensagem_ != 1 && mensagem_ != 3)
            cout << "Numero de semestre invalido" << endl;

        if(mensagem_ < 0)
            cout << "Nao sao permitidos semestres negativos!" << endl;
    
    }while(mensagem_ < 0 || (mensagem_ != 1 && mensagem_ != 2 && mensagem_ != 3));

    mensagemRetorno = mensagemRetorno + mensagem;

    return mensagemRetorno;

};



