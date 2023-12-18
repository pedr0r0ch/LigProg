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
        ~Camada();

        void edicoesGerais();
        void exibirCamada();
        void setTransparencia();
        double getTransparencia();
        string getArquivo();
        string getDescricao();

    private:

        void removerFundo();
        void profundidadeCampo();
        void menuLuzCor();

        double transparencia;
        string imagem;
        string descricao;
};      


#endif