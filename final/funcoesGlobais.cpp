
#include <limits>

#include "funcoesGlobais.h"

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

unsigned int exibirMenu(const vector<string> menu){ //funcao que torna mais faci a interacao do usuario com o programa
    
    initscr();
    cbreak();  //Desabilita buffering de linha
    keypad(stdscr, TRUE); //Habilita teclas especiais
    
    unsigned int opcao = 0;
    while(1){
        
        for(unsigned int indice = 0; indice < menu.size(); indice++){
            if(indice == opcao);
            {   
                if(opcao == 0){
                    cout << ANSI_BACKGROUND_WHITE << ANSI_COLOR_RED << menu[indice] << ANSI_COLOR_RESET << endl;
                    continue;
                }
                
                cout << ANSI_BACKGROUND_WHITE << ANSI_COLOR_GREEN << menu[indice] << ANSI_COLOR_RESET << endl;
                continue;
            }

            cout << menu[indice] << endl;
        }

        if(getch() == 'W' || getch() == 'w'){
            
            if(opcao == 0){
                opcao = menu.size();    
                continue;
            }

            opcao--;
            continue;
        }

        if(getch() == 'S' || getch() == 's'){
            
            if(opcao == menu.size()){
                opcao = 0;
                continue;
            }

            opcao++;
            continue;
        }

        if(getch() == 13){
            
            endwin();
            return opcao;
        }

        refresh();

    };
};
