#include <iostream>
#include <string>
#include <cstdlib>

#include "classeAresta.h"
#include "classeVertice.h"
#include "classeGrafoSimetrico.h"
#include "funcoesGlobais.h"
#include "tipos.h"

using namespace std;


int
main(int argc, char**)
{   
    GrafoSimetrico * grafoSimetrico;
    bool verificador = false;
    while(!verificador){
        ExibirMensagem("Por favor insira o nome do arquivo (em .txt) que contem os dados referentes ao Grafo Simetrico");
        //string nomeArquivo = getMensagem();
        system("clear");
        static GrafoSimetrico grafoSimetrico_(&verificador);
        grafoSimetrico = &grafoSimetrico_;
    }

    cout << "Pressione Enter para continuar..." << endl;  
    cin.ignore();             
    cin.get();

    system("clear");

    while(1){

        system("clear"); 

        ExibirMensagem("Por favor escolha a acao desejada indicando o numero correspondente.");
        ExibirMensagem();   
        ExibirMensagem("Opcao 0: Sair e encerrar execucao.");
        ExibirMensagem("Opcao 1: Exibir a enlaces existentes.");
        ExibirMensagem("Opcao 2: Exibir matriz de adjacencias.");
        ExibirMensagem("Opcao 3: Exibir caminho de menor custo.");
        ExibirMensagem("Opcao 4: Exibir densidade do grafo.");
        ExibirMensagem("Opcao 5: Exibir vertice com maior centralidade de proximidade.");
        ExibirMensagem();   

        int resposta;
        if(getMensagem(0, 5, &resposta) == sucesso){
        switch(resposta){
            case 1:
                (*grafoSimetrico).exibirEnlaces();
                ExibirMensagem();

                cout << "Pressione Enter para continuar..." << endl;  
                cin.ignore();             
                cin.get();
                break;

            case 2:
                
                (*grafoSimetrico).exibirMatrizAdjacencias();
                ExibirMensagem();

                ExibirMensagem("Pressione enter para continuar");
                cin.ignore();             
                cin.get();
                break;

            case 3:
                {
                ExibirMensagem("Por favor, insira os vertices de origem e de destino:");
                ExibirMensagem("Origem:");
                string vertice_A = getMensagem();
                ExibirMensagem("Destino:");
                string vertice_B = getMensagem();

                (*grafoSimetrico).exibirCaminhoMenorCusto(vertice_A, vertice_B, NULL);
                }
                ExibirMensagem();
                ExibirMensagem("Pressione enter para continuar");
                cin.ignore();             
                cin.get();
                break;
                            
            case 4:
                (*grafoSimetrico).exibirDensidadeGrafo();
                ExibirMensagem();
                ExibirMensagem("Pressione enter para continuar");
                cin.ignore();             
                cin.get();
                break;

            case 5:
                (*grafoSimetrico).exibirVerticeMaiorCentralidade();
                ExibirMensagem();
                ExibirMensagem("Pressione enter para continuar");
                cin.ignore();             
                cin.get();
                break;

            case 0:
                ExibirMensagem("Encerrando programa.");
                ExibirMensagem();
                ExibirMensagem("Pressione enter para continuar");
                cin.ignore();             
                cin.get();
                return sucesso;
            
            default:
                continue;
        };
    };

    };
    
    return sucesso;
};