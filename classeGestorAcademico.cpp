#include "classeGestorAcademico.h"
#include "funcoesGlobais.h"

GestorAcademico :: GestorAcademico (tipoSemestre semestreVigenteConstrutor, vector<Disciplina> vetorDisciplinasConstrutor, vector<Aluno> vectorAlunosConstrutor) {

    vetorDisciplinas = vetorDisciplinasConstrutor;
    vetorAlunos = vectorAlunosConstrutor;
    semestreVigente = semestreVigenteConstrutor;
};

void GestorAcademico :: evolucaoNotasFinais(){
    
};

void GestorAcademico :: agruparDisciplinasAdm(){

};

void GestorAcademico :: agruparDisciplinasAlunos(){

};

void GestorAcademico :: exibirDisciplinaMaiorMedia(){
    unsigned short  indice,
                    indiceMaiorMedia,
                    maiorMedia = 0;

    for(indice = 0; indice < vetorDisciplinas.size(); indice++){
        if (vetorDisciplinas[indice].getMediaTurma() > maiorMedia){
            maiorMedia = vetorDisciplinas[indice].getMediaTurma();
            indiceMaiorMedia = indice;
        }
    }
    //verificar implementacionabilidade da funcao Print()
    ExibirMensagem( "A disciplina que obteve a maior media foi:",  vetorDisciplinas[indiceMaiorMedia].nomeDisciplina,
                    "Com media equivalente de: ", vetorDisciplinas[indiceMaiorMedia].getMediaTurma(), ".");


};

void GestorAcademico :: exibirDisciplinaMaiorEvolucao(){

};

void GestorAcademico :: exibirAlunoMaiorMedia(){
    unsigned short  indice,
                    indiceMaiorMedia,
                    maiorMedia = 0;

    for(indice = 0; indice < vetorAlunos.size(); indice++){
        if (vetorAlunos[indice].getMedia() > maiorMedia){
            maiorMedia = vetorAlunos[indice].getMedia();
            indiceMaiorMedia = indice;
        }
    }
    //verificar implementacionabilidade da funcao Print()
    ExibirMensagem( "O aluno que possui a maior media eh o aluno:",  vetorAlunos[indiceMaiorMedia].nomeAluno,
                    "Com media equivalente de: ", vetorAlunos[indiceMaiorMedia].getMedia(), ".");

};