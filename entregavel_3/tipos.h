#ifndef _TIPOS_
#define _TIPOS_

#include <string>
#include <iostream>
#include <sstream>

#include "funcoesGlobais.h"

using namespace std;

struct Disciplina{

    Disciplina& operator=(const string linha){
    
        short indice = 0;
        string vetorArgumentos[4];
        string argumento;
        istringstream argumentos(linha);

        while(getline(argumentos, argumento, ',')){
            vetorArgumentos[indice] = argumento;
            indice++;
        }

        this-> nome = vetorArgumentos[0];
        this->periodo = vetorArgumentos[1];
        this->grau= stod(vetorArgumentos[2]);
        this->credito = stoul(vetorArgumentos[3]);

        return *this;

    };

    friend istream& operator>>(istream&, Disciplina&);


    string nome;
    string periodo;
    double grau;
    unsigned int credito;

};

#endif