#include "classeDisciplina.h"

Disciplina :: Disciplina( string nome, tipoSemestre semestreConstrutor){
    nomeDisciplina = nome;
    semestre = semestreConstrutor;
};

void Disciplina :: setMediaTurma(){
    
    unsigned short  indice,
                    contador = 0;
    float soma = 0;

    for(indice = 0; indice < alunosCursantes.size(); indice++){
        soma += alunosCursantes[indice].getGrauObtido(nomeDisciplina, semestre);
        contador++;
    };
    
    mediaTurma = (soma / contador);
};

void Disciplina :: inserirAlunos(Aluno aluno){
    alunosCursantes.push_back(aluno);
};

float Disciplina :: getMediaTurma(){
    return mediaTurma;
};

tipoSemestre Disciplina :: getSemestre (){
    return semestre;
};