#include "classeDisciplina.h"

Disciplina :: Disciplina( string nomeDisciplina, tipoSemestre periodoAtual,\
                          vector<Aluno> vetorAlunos, vector<float> vetorNotas){
    nome = nomeDisciplina;
    periodo = periodoAtual;
    
    alunosCursantes = vetorAlunos;
    notasFinais = vetorNotas;
    setMediaTurma();
};

void Disciplina :: setMediaTurma(){
    
    unsigned short indice,
                   soma;

    for(indice = 0; indice < alunosCursantes.size(); indice++)
        soma =+ alunosCursantes[indice].getGrauObtido(nomeDisciplina);
    
    mediaTurma = (soma / (indice + 1));

};

float Disciplina :: getMediaTurma();