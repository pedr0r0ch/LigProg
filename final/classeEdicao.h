#ifndef _CLASSE_EDICAO_
#define _CLASSE_EDICAO_

#include <vector>
#include <string>

#include "classeCamada.h"



using namespace std;

class Edicao{
    public:
        

    private:
        vector<Camada> camadas; 
        string arquivo; //arquivo de imagem final e arquivo de pre-visualizacao
};

#endif