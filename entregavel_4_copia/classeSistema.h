#ifndef CLASSE_SISTEMA
#define CLASSE_SISTEMA

#include <iostream>

#include "classeAtleta.h"
#include "classeAtletaDerivacoes.h"
#include "classeArvore.h"

class Sistema : public Arvore<Atleta>
{
    public:

        Sistema();

        void insere();
        Atleta* busca();
        void imprime();
        
    private:

        Atleta* operator()(const string);
        Arvore<Atleta>* operator+(const Atleta);
        friend ostream &operator<<(ostream &out, Arvore<Atleta>);

};

#endif