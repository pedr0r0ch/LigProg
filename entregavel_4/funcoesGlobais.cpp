#include <iostream>

#include "funcoesGlobais.h"

using namespace std;

int exibirOpcoes(const char* menu[], const unsigned nOpcoes){ //funcao que exibe o menu interativo

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





