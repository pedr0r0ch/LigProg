#include "classeGestorAcademico.h"

GestorAcademico :: GestorAcademico (tipoSemestre periodoVigenteConstrutor, vector<Disciplina> vetorDisciplinasConstrutor, vector<Aluno> vectorAlunosConstrutor) {

    vetorDisciplinas = vetorDisciplinasConstrutor;
    vetorAlunos = vectorAlunosConstrutor;
    periodoVigente = periodoVigenteConstrutor;
};

void GestorAcademico :: evolucaoNotasFinais(){
    for()
};

void GestorAcademico :: agruparDisciplinasAdm(){

};

void GestorAcademico :: agruparDisciplinasAlunos(){

};

void GestorAcademico :: exibirDisciplinaMaiorMedia(){

};

void GestorAcademico :: exibirDisciplinaMaiorEvolucao(){

};

void GestorAcademico :: exibirAlunoMaiorMedia(){
    unsigned short  indice,
                    indiceMaiorMedia,
                    maiorMedia = 0;

    for(indice = 0; indice < vetorAlunos.size(); indice++){
        if (vetorAlunos[indice].getMedia > maiorMedia){
            maiorMedia = vetorAlunos[indice].getMedia;
            indiceMaiorMedia = indice;
        }
    }
    Print( "O aluno que possui a maior media eh o aluno:",  vetorAlunos[indiceMaiorMedia].nomeAluno,
           "Com media equivalente de: ", vetorAlunos[indiceMaiorMedia].getMedia, ".");

};