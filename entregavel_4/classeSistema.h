#ifndef CLASSE_SISTEMA
#define CLASSE_SISTEMA

#include <iostream>
#include <fstream>
#include <sstream>     

#include "classeAtleta.h"
#include "classeAtletaDerivacoes.h"
#include "classeArvore.h"

class Sistema : public Arvore<Atleta*>
{
    public:

        Sistema(string = "arquivoPadrao.txt");
        ~Sistema();
        int insere();
        Atleta* busca();
        void imprime();
        
    private:

        string arquivoPadrao;
        Arvore<Atleta*> arvore;


};

#endif