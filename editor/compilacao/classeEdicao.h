#ifndef CLASSE_EDICAO
#define CLASSE_EDICAO

#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <ncurses.h>


#include "classeCamada.h"
#include "funcoesGlobais.h"
#include "tipos.h"


class Edicao{
    public:
        
        Edicao(string);
        ~Edicao();

        void adicionarCamada(); // inclui uma nova camada
        void alterarPrioridade(); //altera a sobreposicao de camadas
        int selecionarCamada(); //seleciona uma camada para edicao
        void edicoesGerais(int); //chama o metodo edicoes gerais da camada do indice recebido
        void exibirEdicao(); //exibe a edicao atual, que é todas as camadas sobrepostas
    
    private:

        void converterArquivo(string&); //converte arquivos de outros formatos para .png
        string sobreporCamadas(); //faz a sobreposicao das camadas respeitando suas prioridades
        void obterNomesArquivos(const string, vector<string>*); //obtem todos os nomes de arquivos validos de diretorio de trabalho

        vector<Camada*> camadas; //guarda todos os objetos do tipo camada

};

#endif