#ifndef _CLASSE_ARESTA_
#define _CLASSE_ARESTA_

#include "classeVertice.h"
#include "tipos.h"  

using namespace std;

class Vertice;

class Aresta {
    
    public:

        Aresta(float, Vertice*, Vertice*);
        
        Vertice* getVertice_A();
        Vertice* getVertice_B();
        float getPeso();
    
    private:

        Vertice* vertice_A;
        Vertice* vertice_B;
        float peso;

};

#endif