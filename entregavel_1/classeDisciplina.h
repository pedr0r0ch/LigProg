#ifndef __CLASSE_DISCIPLINA__
#define __CLASSE_DISCIPLINA__ 

#include <iostream>
#include <vector>
#include <string>

#include "tipos.h"
#include "funcoesGlobais.h"
#include "classeAlunos.h"

using namespace std;


class Disciplina {
    
    public:

        Disciplina(string, tipoSemestre);

        string nomeDisciplina;

        void setMediaTurma();
        float getMediaTurma();
        tipoSemestre getSemestre();
        void inserirAlunos(Aluno);
    
    private:

        tipoSemestre semestre;
        unsigned short mediaTurma;
        vector <Aluno> alunosCursantes;
};

#endif