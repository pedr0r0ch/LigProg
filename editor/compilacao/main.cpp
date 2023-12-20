#include <unistd.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>

#include "/usr/include/python3.10/Python.h"


#include "funcoesGlobais.h"
#include "classeCamada.h"
#include "classeEdicao.h"

#include "tipos.h"

using namespace std;

int
main(int argc, char**)
{
    char buffer[PATH_MAX];
    int opcao;
    int indice_camada;

    if (getcwd(buffer, sizeof(buffer)) != NULL)
    {
        // Define a macro DIR_PROGRAMA com o valor do diretório atual
    }else
        return -1;
    
    initscr(); //inicializa o modulo ncurses
    start_color(); //habilita cores no terminal



    if(has_colors()){
        //inicializa pares de cor [cor fonte, cor fundo]
        init_pair(1, COLOR_WHITE, COLOR_BLACK);//opcoes nao selecionadas
        init_pair(2, COLOR_RED, COLOR_WHITE);  //opcoes de voltar selecionadas
        init_pair(3, COLOR_GREEN, COLOR_WHITE);//opcoes de avancar selecionadas
        init_pair(4, COLOR_YELLOW, COLOR_BLACK); //orientacoes de uso
        init_pair(5, COLOR_RED, COLOR_BLACK);
    }

    Edicao* edicao = new Edicao();
    vector<string> menu = {  "Voltar (! encerrar programa)",\
                            "Adicionar nova camada",\
                            "Alterar prioridade entre as camadas",\
                            "Selecinar camada para edicao",\
                            "Exibir edicao atual",\
                            "Salvar edicao e encerrar programa"};

    Py_Initialize();
    while(edicao){
        opcao = exibirOpcoes(menu);
        switch(opcao){
            case -1:
                refresh();
                endwin();
                exit(1);

            case 0:
                (*edicao).adicionarCamada();
                break;
            
            case 1:
                (*edicao).alterarPrioridade();
                break;

            case 2:
                indice_camada = (*edicao).selecionarCamada();
                if (indice_camada == -1)
                    break;
                (*edicao).edicoesGerais(indice_camada);
                break;

            case 3:
                (*edicao).exibirEdicao();
                break;
            
            case 4:
                delete edicao;
                edicao = nullptr;
                refresh();
                endwin();
                break;
        }
    }

    Py_Finalize();//finaliza a API


    return 0;
};