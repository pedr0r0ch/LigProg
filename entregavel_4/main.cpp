#include <iostream>
#include <string>
#include <vector>

#include "funcoesGlobais.h"
#include "classeSistema.h"

using namespace std;

int
main(int argc, char**)
{   
    Sistema sistema;
    int opcao;
    const char* menu[] = {  "Voltar (! encerrar programa)",\
                            "Adicionar Atletas ao sistema",\
                            "Buscar Atletas no sistema",\
                            "Exibir Atletas cadastrados no sistema"};
    while(1){
        opcao = exibirOpcoes(menu, 4);
        switch(opcao){
            case 0:
                return 1;

            case 1:
                sistema.insere();
                break;
            
            case 2:
                sistema.busca();
                break;

            case 3:
                sistema.imprime();
                break;
        }
    }

    return 0;
};