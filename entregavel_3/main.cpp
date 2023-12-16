#include <iostream>
#include <string>

#include "classeHistorico.h"
#include "funcoesGlobais.h"
#include "sobrecarga.h"
#include "tipos.h"

using namespace std;

int
main(int argc, char**)
{   
    
    Historico historico("historico.txt", 10);
    vector<Disciplina> vetorDisciplina;
    Disciplina disciplina;
    string nome;
    int verificao;
    int indice;
    int numero;
    double nota;



    system("clear");

    while(1){

        system("clear"); 

        ExibirMensagem("Por favor escolha a acao desejada indicando o numero correspondente.", '\n');
        ExibirMensagem("Opcao 0: Sair e encerrar execucao.");
        ExibirMensagem("Opcao 1: Exibir catalogo de disciplinas.");
        ExibirMensagem("Opcao 2: Exibir disciplina.");
        ExibirMensagem("Opcao 3: Inserir disciplinas no historico.");
        ExibirMensagem("Opcao 4: Remover disciplina do historico.");
        ExibirMensagem("Opcao 5: Editar nota de disciplina.");
        ExibirMensagem("Opcao 6: Calcular CRA.", '\n');

        int resposta = getMensagem("Digite o numero correspondente: ", 0, 6);

        switch(resposta){
            case 1: //exibir catalogo

                cout << '\n' << endl;
                cout << "Todas as disciplinas do historico estao listadas abaixo:" << '\n';
                
                cout << "---------------------COMECO--------------------" << '\n';
                cout << historico;
                cout << "-----------------------FIM---------------------" << '\n';

                getMensagem();
                break;

            case 2: //exibir disciplina individualmente

                cout << '\n' << endl;

                nome = getMensagem("Qual o nome da disciplina a ser exibida? :");
                indice = historico(nome);

                cout << "---------------------COMECO--------------------" << '\n';

                if(indice == -1){
                    cout << "Nenhuma disciplina nao encontrada" << endl;
                    cout << "-----------------------FIM---------------------" << '\n';

                    getMensagem();
                    break;
                }
                
                disciplina = (historico.getDisciplina(indice));

                cout << disciplina;
                cout << "-----------------------FIM---------------------" << '\n';


                getMensagem();
                break;

            case 3: //inserir disciplina
                
                cout << '\n' << endl;
                numero = getMensagem("Quantas disciplinas serao inseridas no historico? :", 1, 100);
                
                cout << '\n' << endl;
                cout << "-------------------------------------------------" << endl;

                if (numero == 1){
                    cin >> disciplina;
                    verificao = (historico += disciplina); // inclusao unitaria


                }else{
                    while(numero != 0){
                        cin >> disciplina;
                        vetorDisciplina.push_back(disciplina);
                        numero--;

                        cout << "-------------------------------------------------" << endl;
                    }

                    verificao = (historico += vetorDisciplina); //inclusao 'por lote'

                    if(verificao == -1)
                        cout << "Erro! Nao eh permitida a inclusao de disciplinas com o mesmo nome" << endl;
                    
                    cout << "Inclusao de disciplinas realizada com sucesso!" << endl;

                    getMensagem();
                    break;
                }

                cout << "-------------------------------------------------" << endl;

                getMensagem();
                break;
                            
            case 4: //remover disciplina
                cout << '\n' << endl;
                nome = getMensagem("Qual o nome da disciplina que deve ser removida? :");
                indice = historico(nome);

                cout << '\n' << endl;


                if((historico -= historico.getDisciplina(indice)) == -1){
                    cout << "Disciplina nao encontrada" << endl;
                    getMensagem();
                    break;
                }               

                cout << "Disciplina removida com sucesso!" << endl;

                getMensagem();
                break;

            case 5: //editar nota
                
                cout << '\n' << endl;

                nome = getMensagem("Em qual disciplina sera feita a alteracao? :");
                nota = getMensagem("Qual sera a nova nota? :", 0.0, 10.0);
                
                cout << '\n' << endl;


                verificao = historico(nome, nota);
                
                if(verificao == -1){
                    cout << "Erro! A disciplina solicitada nao existe. Alteracao no historico nao concluida." << endl;
                    getMensagem();
                    break;
                }
                
                cout << "Alteracao no historico realizada com sucesso!" << endl;

                getMensagem();
                break;
            
            case 6://calcular CRA

                cout << '\n' << endl;
                nota = 0; // nota = cra 

                historico >> nota; // nota = cra
                cout << "O cra do historico eh: " << to_string(nota) << endl;
                getMensagem();
                break;


            case 0:

                ExibirMensagem("Encerrando programa.");
                getMensagem();
                return 0;
            
            default:
                continue;
        };
    };

    return 0;
};