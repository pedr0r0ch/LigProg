#include "classeAtleta.h"

Atleta :: Atleta(string nome, string nacionalidade, double altura, int idade){
    this->nome = nome;
    this->nacionalidade = nacionalidade;
    this->altura = altura;
    this->idade = idade;
};

string Atleta :: getNome(){
    return nome;
};