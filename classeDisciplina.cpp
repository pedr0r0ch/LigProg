#include "classeDisciplina.h"

Disciplina :: Disciplina( string nome, tipoSemestre semestreConstrutor,\
                          vector<Aluno> vetorAlunos){
    nomeDisciplina = nome;
    semestre = semestreConstrutor;
    alunosCursantes = vetorAlunos;
    setMediaTurma();
};

void Disciplina :: setMediaTurma(){
    
    unsigned short indice,
                   soma;

    for(indice = 0; indice < alunosCursantes.size(); indice++)
        soma =+ alunosCursantes[indice].getGrauObtido(nomeDisciplina);
    
    mediaTurma = (soma / (indice + 1));

};

float Disciplina :: getMediaTurma(){
    return mediaTurma;
};