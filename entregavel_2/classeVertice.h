#ifndef _CLASSE_VERTICE_
#define _CLASSE_VERTICE_

#include <list>
#include <vector>
#include <string>

#include "classeAresta.h"
#include "tipos.h"

using namespace std;

class Aresta;

class Vertice {
    
    public:

        Vertice(string);
        
        string getNome();
        vector <Aresta *> getArestas();
        void setArestas( Aresta* );

    private:
        
        string nome;
        vector < Aresta* > listaArestas;
};

#endif