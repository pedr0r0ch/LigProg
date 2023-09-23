#include <iostream>
#include <string>
#include <cstdlib>

#include "classeAlunos.h"
#include "classeDisciplina.h"
#include "classeGestorAcademico.h"
#include "tipos.h"
using namespace std;


int
main(int argc, char**)
{
    short resposta = 0;
    string mensagem;

    GestorAcademico objetoGestorAcademico(2023, 2);
    cout << "Pressione Enter para continuar..." << endl;  
    cin.ignore();             
    cin.get();
    
    system("clear");
    ExibirMensagem("Gestor academico inicializado!");

    while(1){

         system("clear");

        ExibirMensagem("Por favor escolha a acao desejada indicando o numero correspondente.");
        ExibirMensagem();   
        ExibirMensagem("Opcao 0: Sair e encerrar execucao.");
        ExibirMensagem("Opcao 1: Exibir a evolução da média das notas finais dos alunos.");
        ExibirMensagem("Opcao 2: Exibir de forma agrupada as disciplinas que apresentaram melhoria de desempenho.");
        ExibirMensagem("Opcao 3: Exibir o desempenho dos alunos de forma agrupada.");
        ExibirMensagem("Opcao 4: Exibir a disciplina com maior média de notas finais.");
        ExibirMensagem("Opcao 5: Exibir a disciplina que teve a maior evolução.");
        ExibirMensagem("Opcao 6: Exibir aluno com maior media.");
        ExibirMensagem();   
        resposta = getMensagem( 0, 6);

        switch(resposta){
            case 1:
                objetoGestorAcademico.evolucaoNotasFinais();
                cout << "Pressione Enter para continuar..." << endl;  
                cin.ignore();             
                cin.get();
                break;

            case 2:
                objetoGestorAcademico.exibirDisciplinasAgrupadas();
                ExibirMensagem();

                ExibirMensagem("Pressione enter para continuar");
                cin.ignore();             
                cin.get();
                break;

            case 3:
                objetoGestorAcademico.agruparDisciplinasAlunos();
                ExibirMensagem();

                ExibirMensagem("Pressione enter para continuar");
                cin.ignore();             
                cin.get();
                break;

            case 4:
                objetoGestorAcademico.exibirDisciplinaMaiorMedia();
                ExibirMensagem();
                ExibirMensagem("Pressione enter para continuar");
                cin.ignore();             
                cin.get();
                break;

            case 5:
                objetoGestorAcademico.exibirDisciplinaMaiorEvolucao();
                ExibirMensagem();
                ExibirMensagem("Pressione enter para continuar");
                cin.ignore();             
                cin.get();
                break;

            case 6:
                objetoGestorAcademico.exibirAlunoMaiorMedia();
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
        };

    };
    
    return sucesso;
};