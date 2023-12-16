#ifndef _CLASSE_PROGRAMA_
#define _CLASSE_PROGRAMA_

#include <iostream>
#include <vector>
#include <string>

#include "classeCamada.h"
#include "classeImagem.h"
#include "classeEdicao.h"
#include "sobrecargas.h"

using namespace std;

class ProgramaPrincipal{
    public:
        ProgramaPrincipal(string = "/diretorio_de_trabalho"); //construtor recebe o diretorio de trabalho
        tipoErros iniciar(); //Exibe o menu inicial do programa, que seleciona a imagem base da edicao
        tipoErros editar();
        tipoErros salvar(); 

        friend void operator<<(vector<Imagem>&, Imagem&);       

    private:

        Edicao edicao;

        vector<Imagem> imagens;
        vector<Descricao> descricoes;
        
        string diretorioTrabalho;

        
};


#endif