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
        
        Edicao();
        Edicao(string);
        ~Edicao();

        void addCamada(); // inclui uma nova camada
        void alterarPrioridade(); //altera a sobreposicao de camadas
        int selecionarCamada(); //seleciona uma camada para edicao
        void edicoesGerais(int);
        void exibirEdicao(); //exibe a edicao atual, que é todas as camadas sobrepostas
        friend void exibirImagem();
    
    private:

        vector<Camada*> operator+(Camada*); //sobrecarga do operador + para adicionar novas camadas a edicao
        string sobreporCamadas(); //faz a sobreposicao das camadas respeitando suas prioridades
        void obterNomesArquivos(const string, vector<string>*);
        int fazerCopia(const string&, const string&, string&); //faz uma copia do arquivo recebido no primeiro argumento, para o diretorio do segundo argumento.

        vector<Camada*> camadas;

};

#endif