#ifndef CLASSE_CAMADA
#define CLASSE_CAMADA

#include <iostream>
#include <string>
#include <ncurses.h>

#include "tipos.h"
#include "funcoesGlobais.h"



using namespace std;

class Camada{
    public:
        Camada(string, string); //recebe o caminho de imagem e sua descricao fornecida ppelo usuario
        ~Camada(); //o destrutor remove o arquivo-copia da camada

        void edicoesGerais(); //abre o menu de edicoes gerais (remover objeto, profundidade de campo, menu luz e cor)
        void exibirCamada(); //exibe o arquivo de imagem da camada
        void setTransparencia(); //metodo para definir a opacidade da camada
        double getTransparencia(); //metodo que retorna a opacidade da camada
        string getArquivo(); //retorna o nome do arquivo
        string getDescricao(); //retorna a descricao da camada

    private:

        void removerFundo(); //remove o funco da imagem
        void profundidadeCampo(); //aplica efeito de desfoque na imagem
        void menuLuzCor(); //altera o nivel de brilho, contraste e saturacao

        double transparencia;
        string imagem; //arquivo .png de imagem
        string descricao; //descricao da camada
};      


#endif