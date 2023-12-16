#include <iostream>
#include <limits>
#include <vector>
#include <string>

#include "funcoesGlobais.h"
#include "tipos.h"

using namespace std;

string getMensagem(string exibir){
    
    initscr(); //inicializa o modulo ncurses
    start_color(); //habilita cores no terminal

    if(has_colors()){
        //inicializa pares de cor [cor fonte, cor fundo]

        init_pair(1, COLOR_WHITE, COLOR_BLACK);//opcoes nao selecionadas
        init_pair(2, COLOR_RED, COLOR_WHITE);  //opcoes de voltar selecionadas
        init_pair(3, COLOR_GREEN, COLOR_WHITE);//opcoes de avancar selecionadas
        init_pair(4, COLOR_YELLOW, COLOR_BLACK); //orientacoes de uso
    } 

    char mensagem[100];

    if(has_colors())
        attron(COLOR_PAIR(4));
    mvprintw(ESPACAMENTO-3, 1, "! Por favor digite o que foi pedido e pressione enter.");
    if(has_colors())
        attroff(COLOR_PAIR(4));

    
    if(has_colors())
        attron(COLOR_PAIR(1));
    mvprintw(ESPACAMENTO, 1, exibir.c_str());
    getstr(mensagem);
    if(has_colors())
        attroff(COLOR_PAIR(1));
    
    noecho();  //nao exibe as teclas pressinadas
    curs_set(0); //desbilita o cursor

    refresh();
    getch();

    return string(mensagem);
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

int exibirMenu(const char* menu[], const unsigned nOpcoes){ //funcao que exibe o menu interativo

    initscr(); //inicializa o modulo ncurses
    cbreak();  //desbilita o buffer de linha
    noecho();  //nao exibe as teclas pressinadas
    curs_set(0); //desbilita o cursor
    keypad(stdscr, TRUE);  //identifica teclas especiais como as setas

    start_color(); //habilita cores no terminal


    unsigned opcao = 0; //posicao do "voltar"
    if(has_colors()){
        //inicializa pares de cor [cor fonte, cor fundo]

        init_pair(1, COLOR_WHITE, COLOR_BLACK);//opcoes nao selecionadas
        init_pair(2, COLOR_RED, COLOR_WHITE);  //opcoes de voltar selecionadas
        init_pair(3, COLOR_GREEN, COLOR_WHITE);//opcoes de avancar selecionadas
        init_pair(4, COLOR_YELLOW, COLOR_BLACK); //orientacoes de uso
    }    


    char tecla;

    while(1){
        
        clear();
        refresh();

        for(unsigned indice = 0; indice < nOpcoes; indice++){
            
            if(indice == opcao)
            {   
                if(has_colors())
                    attron(COLOR_PAIR(4));
                mvprintw(ESPACAMENTO-3, 1, "! Use as teclas W, S e 'enter' para alternar");
                mvprintw(ESPACAMENTO-2, 1, "entre as opcoes e selecionar - las");
                
                if(has_colors())
                    attroff(COLOR_PAIR(4));

                if(opcao == 0){
                    
                    if(has_colors())
                        attron(COLOR_PAIR(2));
                    
                    mvprintw((indice+ESPACAMENTO), 1, "<<-");
                    mvprintw((indice+ESPACAMENTO), 4, "%s", menu[indice]);
                    
                    if(has_colors())
                        attroff(COLOR_PAIR(2));
                    

                    continue;
                } // se a opcao voltar estiver selecionada, a fonte deve ficar vermelha
                
                //caso contrario deve ser na cor verde
                if(has_colors())
                    attron(COLOR_PAIR(3));

                mvprintw((indice+ESPACAMENTO), 1, "->>"); 
                mvprintw((indice+ESPACAMENTO), 4, "%s",menu[indice]);
                
                if(has_colors())
                    attroff(COLOR_PAIR(3));

                continue;
            }

            if(has_colors())
                attron(COLOR_PAIR(1));

            mvprintw((indice+ESPACAMENTO), 1, "%s", menu[indice]);

            if(has_colors())
                attroff(COLOR_PAIR(1));
        }

        tecla = getch();

        if(tecla == 'W' || tecla == 'w' || tecla == KEY_UP){
            
            if(opcao == 0){
                opcao = (nOpcoes-1);    
                continue;
            }

            opcao--;
            continue;
        }

        if(tecla == 'S' || tecla == 's' || tecla == KEY_DOWN){
            
            if(opcao == (nOpcoes-1)){
                opcao = 0;
                continue;
            }

            opcao++;
            continue;
        }

        if(tecla == 10 || tecla == 13){
            //endwin();

            return opcao;
        }

    };
};





