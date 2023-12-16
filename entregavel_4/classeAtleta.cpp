#include "classeAtleta.h"

Atleta :: Atleta(string nome, int idade){
    this->nome = nome;
    this->idade = idade;
};

string Atleta :: getNome(){
    return nome;
};

string Atleta :: descricao(){
    return (nome + " tem " + to_string(idade) + "e eh um(a) atleta");
};

int Atleta :: getIdade(){
    return idade;
};

string Atleta :: getTipo(){
 return "Generico";
};