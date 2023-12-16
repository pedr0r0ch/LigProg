#include <iostream>
#include <string>
#include <vector>

#include "funcoesGlobais.h"
#include "tipos.h"
#include "classeSistema.h"

using namespace std;

int
main(int argc, char**)
{   
    Sistema sistema;
    int opcao;
    const char* menu[] = {  "Voltar",\
                            "Adicionar Atletas ao sistema",\
                            "Buscar Atletas no sistema",\
                            "Exibir Atletas cadastrados no sistema"};
    while(1){
        opcao = exibirMenu(menu, 4);
        switch(opcao){
            case 0:
                continue;
            
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