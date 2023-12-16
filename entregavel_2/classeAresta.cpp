#include "classeAresta.h"
#include "classeVertice.h"
#include "funcoesGlobais.h"

Aresta :: Aresta(float peso_, Vertice* vertice_A_, Vertice* vertice_B_){
    vertice_A = vertice_A_;
    vertice_B = vertice_B_;
    peso = peso_;
};

Vertice* Aresta :: getVertice_A()
{
    return vertice_A;
};

Vertice* Aresta :: getVertice_B()
{
    return vertice_B;
};

float Aresta :: getPeso()
{
    return peso;
};