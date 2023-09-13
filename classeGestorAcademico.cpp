#include "classeGestorAcademico.h"

GestorAcademico :: GestorAcademico (tipoSemestre periodoVigenteConstrutor, vector<Disciplina> vetorDisciplinasConstrutor, vector<Aluno> vectorAlunosConstrutor) {

    vetorDisciplinas = vetorDisciplinasConstrutor;
    vetorAlunos = vectorAlunosConstrutor;
    periodoVigente = periodoVigenteConstrutor;
};