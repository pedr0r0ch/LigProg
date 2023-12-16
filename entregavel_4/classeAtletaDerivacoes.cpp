#include "classeAtletaDerivacoes.h"

string AtletaFutebol :: descricao(){
    return (nome + " tem " + to_string(idade) + " anos e eh praticante de Futebol");
};

string AtletaFutebol :: getTipo(){
    return "Futebol";
};

string AtletaGinastica :: descricao(){
    return ( nome + " tem " + to_string(idade) + " anos e eh praticante de Ginastica Olimpica");
};

string AtletaGinastica :: getTipo(){
    return "Ginastica Olimpica";
};

string AtletaSurf :: descricao(){
    return (nome + " tem " + to_string(idade) + " anos e eh praticante de Surf");
};
string AtletaSurf :: getTipo(){
    return "Surf";
};