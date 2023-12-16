#ifndef CLASSE_ATLETA_FUTEBOL
#define CLASSE_ATLETA_FUTEBOL

#include <iostream>
#include <string>

#include "classeAtleta.h"

using namespace std;

class AtletaFutebol : public Atleta{
    void descricao();

};

class AtletaGinastica : public Atleta{
    void descricao();
};

class AtletaSurf : public Atleta{
    void descricao();

};



#endif