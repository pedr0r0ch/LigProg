#ifndef _CLASSE_IMAGEM_
#define _CLASSE_IMAGEM_

#include <string>
#include <vector>

#include "tipos.h"

using namespace std;

class Imagem {
    public:
        Imagem(string); //nome do arquivo de imagem

    private:

        string arquivo;
        
        unsigned int altura;
        unsigned int largura; // altura e largura em pixels/px
        
        vector<edicao> edicoesFeitas; // vetor que guarda as edicoes feitas na imagem (descricao e arquivo)


};

#endif