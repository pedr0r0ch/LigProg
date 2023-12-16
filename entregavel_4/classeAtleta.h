#ifndef CLASSE_ATLETA
#define CLASSE_ATLETA

#include <iostream>
#include <string>

using namespace std;

class Atleta{
    
    public:
        Atleta(string, int);

        string nome;
        int idade;

        string getNome();
        int getIdade();
        
        virtual string getTipo();
        virtual string descricao();

};

#endif