#include "classeAtletaDerivacoes.h"

void AtletaFutebol :: descricao(){
    cout << this->nome << " eh " << this->nacionalidade << ", tem " << this->idade\
         << "anos " << "tem " << this->altura << "m de altura e eh praticante de Futebol" <<endl;
};

void AtletaGinastica :: descricao(){
    cout << this->nome << " eh " << this->nacionalidade << ", tem " << this->idade\
         << "anos " << "tem " << this->altura << "m de altura e eh praticante de Ginastica Artistica" <<endl;
};

void AtletaSurf :: descricao(){
    cout << this->nome << " eh " << this->nacionalidade << ", tem " << this->idade\
         << "anos " << "tem " << this->altura << "m de altura e eh praticante de Surf" <<endl;
};