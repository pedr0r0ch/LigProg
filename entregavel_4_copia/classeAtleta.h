#ifndef CLASSE_ATLETA
#define CLASSE_ATLETA

#include <iostream>
#include <string>

using namespace std;

class Atleta{
    
    public:
        Atleta(string, string, double, int);

        string nome;
        string nacionalidade;
        double altura;
        int idade;

        string getNome();

};

#endif