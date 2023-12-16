#ifndef _CLASSE_CAMADA_
#define _CLASSE_CAMADA_

#include <string>
#include <vector>


using namespace std;

class Camada {
    public:
        Camada(unsigned int, string); //prioridade da camada e nome da camada

    private:

        unsigned int prioridade;
        string nome;
};

#endif