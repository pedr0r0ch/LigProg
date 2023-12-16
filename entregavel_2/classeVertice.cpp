#include "funcoesGlobais.h"
#include "classeAresta.h"
#include "classeVertice.h"

using namespace std;

Vertice :: Vertice(string nome_){
    nome = nome_;
};

string Vertice :: getNome(){
    return nome;
};

void Vertice :: setArestas(Aresta* novaAresta){
    bool verificador = true;

    //O proximo escopo verifica se a nova aresta ja nao foi adicionada
    for (Aresta* aresta : listaArestas){
        if( (*aresta).getVertice_A() == (*novaAresta).getVertice_A() &&
            (*aresta).getVertice_B() == (*novaAresta).getVertice_B() &&
            (*aresta).getPeso() == (*novaAresta).getPeso()){
                verificador = false;
            }
    }

    if(verificador)
        listaArestas.push_back(novaAresta);
        
    
};

vector<Aresta*> Vertice::getArestas(){
    return listaArestas;
};