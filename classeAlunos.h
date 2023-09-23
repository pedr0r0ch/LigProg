#ifndef __CLASSE_ALUNO__
#define __CLASSE_ALUNO__ 

#include <iostream>
#include <vector>
#include <string>

#include "tipos.h"

using namespace std;

class Aluno {
    
    public:
        Aluno(string, vector<tipoNota>);
        
        string nomeAluno;
        
        float getMedia();
        float getGrauObtido(string, tipoSemestre);
        void setMediaAluno();
        vector <tipoNota> getGrauDisciplinaPeriodo();

    private:
        
        float media; //media aritimetica de todas as disciplinas cursadas
        vector<tipoNota> grauDisciplinaPeriodo;
        //vetor de uma estrutura que possui informacoes\
        da disciplina, periodo, e grau obtido em um determinado \
        intervalo de tempo
};

#endif