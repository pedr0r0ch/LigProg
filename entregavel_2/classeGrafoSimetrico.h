#ifndef _CLASSE_GRAFO_SIMETRICO_
#define _CLASSE_GRAFO_SIMETRICO_

#include <vector>
#include <string>
#include <sstream>
#include <list>

#include "tipos.h"
#include "classeAresta.h"
#include "classeVertice.h"

using namespace std;

class GrafoSimetrico{
    
    public:
        GrafoSimetrico(bool* verificador, string nomeArquivo = "grafoSimetrico.txt" );
        ~GrafoSimetrico();
        
        void inserirVertice(Vertice*);
        void inserirAresta(Aresta*);
        void setMatrizAdjacencia();

        void exibirGrafoSimetrico();
        void exibirEnlaces();
        void exibirMatrizAdjacencias();
        tipoErros exibirCaminhoMenorCusto(string, string, float* = NULL);
        void exibirDensidadeGrafo();
        void exibirVerticeMaiorCentralidade();
        
    private:
        
        vector <Vertice*> listaVertices;
        vector <Aresta*> listaArestas;
        float** matrizAdjacencia;
       
      
};

#endif