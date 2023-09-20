#include "classeGestorAcademico.h"
#include "funcoesGlobais.h"

GestorAcademico :: GestorAcademico (tipoSemestre semestreVigenteConstrutor, vector<Disciplina> vetorDisciplinasConstrutor, vector<Aluno> vectorAlunosConstrutor) {

    vetorDisciplinas = vetorDisciplinasConstrutor;
    vetorAlunos = vectorAlunosConstrutor;
    semestreVigente = semestreVigenteConstrutor;
};

tipoErros GestorAcademico :: setDesempenhoDisciplinas(unsigned short nPeriodos, tipoSemestre semestreVigente_){
    
    unsigned short  indice,
                    indice_,
                    __NOT_FOUND__;

    tipoSemestre indiceSemestre;

    indiceSemestre = somaTipo( semestreVigente_, nPeriodos*(-1));
    
    while(  (indiceSemestre.ano != semestreVigente.ano) && \
            (indiceSemestre.semestre != semestreVigente.semestre)){

        for (indice = 0; indice < vetorDisciplinas.size(); indice++){
            
            if((vetorDisciplinas[indice].getSemestre().ano == indiceSemestre.ano) && \
               (vetorDisciplinas[indice].getSemestre().semestre == indiceSemestre.semestre))
            {
                __NOT_FOUND__ = 0;
                for(indice_ = 0; indice_ < desempenhoDisciplinas.size(); indice_++){
                    if( desempenhoDisciplinas[indice_].nome_disciplina == vetorDisciplinas[indice].nomeDisciplina){
                        desempenhoDisciplinas[indice_].media_movel += vetorDisciplinas[indice].getMediaTurma();   
                        desempenhoDisciplinas[indice_].n_periodo = nPeriodos; 
                        __NOT_FOUND__ = 1;    
                    };    
                }

                if( __NOT_FOUND__ == 1){
                    tipoDesempenhoDisciplina elemento;
                    elemento.nome_disciplina = vetorDisciplinas[indice].nomeDisciplina;
                    elemento.media_movel = vetorDisciplinas[indice].getMediaTurma();
                    elemento.n_periodo = 0; //valor eh alterado posteriormante nesta implementacao
                    desempenhoDisciplinas.push_back(elemento);
                    __NOT_FOUND__ = 0;
                };
            }

            indiceSemestre = somaTipo( indiceSemestre, 1);
        };
    };

    for(indice_ = 0; indice_ < desempenhoDisciplinas.size(); indice_++){
        desempenhoDisciplinas[indice_].media_movel *= (1/nPeriodos);
        desempenhoDisciplinas[indice_].n_periodo = nPeriodos;
    };

    
    return sucesso;
}

void GestorAcademico :: evolucaoNotasFinais(){
    unsigned short  nPeriodos,
                    indice;
    
    nPeriodos = getNumero(desabilitado, 3, 7);
    ExibirMensagemErro ( setDesempenhoDisciplinas(nPeriodos, semestreVigente));
    
    ExibirMensagem("A seguir estao dispostas as disciplinas e suas respectivas medias moveis calculadas a partir de",\
    nPeriodos, ".");

    for(indice = 0; indice < desempenhoDisciplinas.size(); indice++){
        ExibirMensagem(desempenhoDisciplinas[indice].nome_disciplina, ":", desempenhoDisciplinas[indice].media_movel);
    };
};

void GestorAcademico :: agruparDisciplinasAdm(){
    vector<tipoDesempenhoDisciplina> desempenhoDisciplinasPeriodoAnterior;
    unsigned short  nPeriodos,
                    __NOT_FOUND__;

    ExibirMensagem();
    nPeriodos = getNumero(desabilitado, 3, 7);
    setDesempenhoDisciplinas(nPeriodos, somaTipo(semestreVigente, -1));
    desempenhoDisciplinasPeriodoAnterior = desempenhoDisciplinas;
    setDesempenhoDisciplinas(nPeriodos, semestreVigente);

    if(desempenhoDisciplinas.size() != desempenhoDisciplinasPeriodoAnterior.size()){
        ExibirMensagem();
    };

    for(    short indice = 0; indice < desempenhoDisciplinas.size(); indice++){
        for (short indice_ = 0; indice_ < desempenhoDisciplinasPeriodoAnterior.size(); indice_++){
            if(desempenhoDisciplinas[indice].nome_disciplina == desempenhoDisciplinasPeriodoAnterior[indice_].nome_disciplina){
                
                __NOT_FOUND__ = 1;

                for(int indice__ = 0; indice__ < vetorStatusDisciplinas.size(); indice__++){
                    if(vetorStatusDisciplinas[indice__].nome_disciplina == desempenhoDisciplinas[indice].nome_disciplina){
                        
                        vetorStatusDisciplinas[indice__].diferenca_percentual = \
                        (((desempenhoDisciplinasPeriodoAnterior[indice_].media_movel - desempenhoDisciplinas[indice].media_movel)*100)/\
                        desempenhoDisciplinas[indice].media_movel);

                        vetorStatusDisciplinas[indice__].semestre = semestreVigente;
                        
                        __NOT_FOUND__ = 0;
                    };
                };
                
                if(__NOT_FOUND__ == 1){
                    
                    tipoStatusDisciplinas elemento;

                    elemento.nome_disciplina = desempenhoDisciplinas[indice].nome_disciplina;
                    
                    elemento.diferenca_percentual = (((desempenhoDisciplinasPeriodoAnterior[indice_].media_movel - desempenhoDisciplinas[indice].media_movel)*100)/desempenhoDisciplinas[indice].media_movel);
                    
                    elemento.semestre = semestreVigente;

                    vetorStatusDisciplinas.push_back(elemento);
                };
            };
        };
    };

    //implentar prints

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