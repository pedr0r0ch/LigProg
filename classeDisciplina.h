#ifndef __CLASSE_DISCIPLINA__
#define __CLASSE_DISCIPLINA__ 

#include <iostream>
#include <vector>
#include <string>

#include "tipos.h"
#include "classeAlunos.h"

using namespace std;


class Disciplina {
    
    public:

        Disciplina(string, tipoSemestre, vector<Aluno>, vector<float>);

        string nomeDisciplina;

        void setMediaTurma();
        float getMediaTurma();
        //void getAlunosCursantes(); 
        //void getNotasFinais();
        tipoSemestre getSemestre();
    
    private:
        tipoSemestre semestre;
        unsigned short mediaTurma;
        vector <Aluno> alunosCursantes;
};

#endif