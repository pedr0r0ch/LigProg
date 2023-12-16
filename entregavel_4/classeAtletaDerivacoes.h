#ifndef CLASSE_ATLETA_FUTEBOL
#define CLASSE_ATLETA_FUTEBOL

#include <iostream>
#include <string>

#include "classeAtleta.h"

using namespace std;

class AtletaFutebol : public Atleta{
    public:
        AtletaFutebol(string nome, int idade) : Atleta(nome, idade){};
        
        string descricao();
        string getTipo();
};

class AtletaGinastica : public Atleta{
    public:
        AtletaGinastica(string nome, int idade) : Atleta(nome, idade){};
        
        string descricao();
        string getTipo();
};

class AtletaSurf : public Atleta{
    public:
        AtletaSurf(string nome, int idade) : Atleta(nome, idade){};
        
        string descricao();
        string getTipo();
};



#endif