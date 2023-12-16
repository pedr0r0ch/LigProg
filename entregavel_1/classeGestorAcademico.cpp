#include <ctime>

#include "classeGestorAcademico.h"
#include "funcoesGlobais.h"

GestorAcademico :: GestorAcademico (unsigned short ano, unsigned short periodo) {
    
    srand(time(nullptr));
    semestreVigente.ano = ano;
    semestreVigente.semestre = periodo;

    vetorAlunos = {};
    vetorDisciplinas = {};
    
    tipoNota elemento;
    vector <tipoNota> vetorElementos;
    
    system("clear");
    ExibirMensagem("Inicializador do programa!");


    // construindo os objetos do tipo disciplina -----------

    ExibirMensagem("Cadastrando as disciplinas no sistema...");
   
    vector<string> nomesDisciplinasTeste = {"Lig. Programacao", "Sistemas Op.", "Introd. AM", "Redes 1", "Redes 2"};
    tipoSemestre semestreTeste = semestreVigente ;

    for(unsigned short indice_ = 0; indice_ < 10 ; indice_++){
        for(unsigned short indice =0; indice < nomesDisciplinasTeste.size(); indice++){
        
            Disciplina DisciplinaObj(nomesDisciplinasTeste[indice], semestreTeste);
            string periodo;
            periodo = to_string(semestreTeste.ano) + "." + to_string(semestreTeste.semestre);
            ExibirMensagem("Disciplina adicionada:", DisciplinaObj.nomeDisciplina, " ministrada em:", periodo);
            vetorDisciplinas.push_back(DisciplinaObj);
        };
        semestreTeste = somaTipo(semestreTeste, -1);
    };

    ExibirMensagem();
    ExibirMensagem("Cadastrando os alunos no sistema...");
    ExibirMensagem();

    // construindo objetos da classe Aluno -----------------

    vector<string> vetorTesteNomesAlunos= {"Maria", "Chico", "Joao", "Joaquim", "Joana", "Aloisio", "Joana"};
    
    for(unsigned short indice =0; indice < vetorTesteNomesAlunos.size(); indice++){

        ExibirMensagem();
        ExibirMensagem("Aluno cadastrado:",vetorTesteNomesAlunos[indice]);
        ExibirMensagem(vetorTesteNomesAlunos[indice], "cursou as seguintes disciplinas, nos seguintes periodos com o seguinte grau final:");

        for(unsigned short indice_= 0; indice_< vetorDisciplinas.size(); indice_++){

        elemento.nome_disciplina = vetorDisciplinas[indice_].nomeDisciplina;
        elemento.semestre.ano= vetorDisciplinas[indice_].getSemestre().ano;
        elemento.semestre.semestre= vetorDisciplinas[indice_].getSemestre().semestre;
        elemento.grau_obtido = rand() % 11;

        string periodo = to_string(elemento.semestre.ano) + "." + to_string(elemento.semestre.semestre);
        
        ExibirMensagem("==>", elemento.nome_disciplina, ",", periodo, ", grau:" ,elemento.grau_obtido);

        vetorElementos.push_back(elemento);
        };

        

        Aluno aluno(vetorTesteNomesAlunos[indice], vetorElementos);
        vetorAlunos.push_back(aluno);
    };
    // atualizando os alunos que cursaram as disciplina ------
        for(short indice = 0; indice < vetorDisciplinas.size(); indice++){
            for(short indice_ = 0; indice_ < vetorAlunos.size(); indice_++){
                for(short indice__ = 0; indice__ < vetorAlunos[indice_].getGrauDisciplinaPeriodo().size(); indice__++)
                    if( vetorDisciplinas[indice].nomeDisciplina == vetorAlunos[indice_].getGrauDisciplinaPeriodo()[indice__].nome_disciplina &&
                        vetorDisciplinas[indice].getSemestre().ano == vetorAlunos[indice_].getGrauDisciplinaPeriodo()[indice__].semestre.ano &&
                        vetorDisciplinas[indice].getSemestre().semestre == vetorAlunos[indice_].getGrauDisciplinaPeriodo()[indice__].semestre.semestre)
                        
                        vetorDisciplinas[indice].inserirAlunos(vetorAlunos[indice_]);
            };
        };
        
    // inicializando as medias ------------------------------

        for(short indice = 0; indice < vetorDisciplinas.size(); indice++){
           vetorDisciplinas[indice].setMediaTurma();
        };

        for(short indice = 0; indice < vetorAlunos.size(); indice++){
            vetorAlunos[indice].setMediaAluno();
        };
    ExibirMensagem("Construtor encerrado");
};

tipoErros GestorAcademico :: setDesempenhoDisciplinas(unsigned short nPeriodos, tipoSemestre semestreVigente_){
    
    unsigned short  indice,
                    indice_,
                    __NOT_FOUND__;

    tipoSemestre indiceSemestre;
    indiceSemestre = somaTipo( semestreVigente_, nPeriodos*(-1));

    for(indice_ = 0; indice_ < desempenhoDisciplinas.size(); indice_++){
        desempenhoDisciplinas[indice_].media_movel = 0;
    };


    while(1)
    {   
        if(((indiceSemestre.ano == semestreVigente_.ano) && (indiceSemestre.semestre == semestreVigente_.semestre)))
            break;
        for (indice = 0; indice < vetorDisciplinas.size(); indice++){

            if(((vetorDisciplinas[indice].getSemestre().ano == indiceSemestre.ano) && (vetorDisciplinas[indice].getSemestre().semestre == indiceSemestre.semestre)))
            {
                __NOT_FOUND__ = 1;
                for(indice_ = 0; indice_ < desempenhoDisciplinas.size(); indice_++){
                    if( desempenhoDisciplinas[indice_].nome_disciplina == vetorDisciplinas[indice].nomeDisciplina){

                        desempenhoDisciplinas[indice_].media_movel += vetorDisciplinas[indice].getMediaTurma()/nPeriodos;   
                        desempenhoDisciplinas[indice_].n_periodo = nPeriodos; 

                        __NOT_FOUND__ = 0;    
                    };    
                };

                if( __NOT_FOUND__ == 1){
                    tipoDesempenhoDisciplina elemento;
                    elemento.nome_disciplina = vetorDisciplinas[indice].nomeDisciplina;
                    elemento.media_movel = vetorDisciplinas[indice].getMediaTurma()/nPeriodos;
                    elemento.n_periodo = nPeriodos; 
                    desempenhoDisciplinas.push_back(elemento);
                    __NOT_FOUND__ = 0;
                };
            };

        };

        indiceSemestre =  somaTipo( indiceSemestre, 1);

    };
   
    return sucesso;
}

void GestorAcademico :: evolucaoNotasFinais(){
    unsigned short  nPeriodos,
                    indice;
    
    nPeriodos = getMensagem( 3, 7);
    ExibirMensagemErro ( setDesempenhoDisciplinas(nPeriodos, semestreVigente));
    
    ExibirMensagem("A seguir estao dispostas as disciplinas e suas respectivas medias moveis calculadas a partir de",\
    somaTipo(semestreVigente, (-1)*nPeriodos).ano, ".", somaTipo(semestreVigente, (-1)*nPeriodos).semestre);

    for(indice = 0; indice < desempenhoDisciplinas.size(); indice++){
        ExibirMensagem(desempenhoDisciplinas[indice].nome_disciplina, ":", desempenhoDisciplinas[indice].media_movel);
    };
};

void GestorAcademico :: agruparDisciplinas(){
    vector<tipoDesempenhoDisciplina> desempenhoDisciplinasPeriodoAnterior;
    unsigned short  nPeriodos,
                    __NOT_FOUND__;

    ExibirMensagem("Digite o intervalo desejado.");
    
    nPeriodos = getMensagem( 3, 7);
    
    setDesempenhoDisciplinas(nPeriodos, somaTipo(semestreVigente, -1)); 
    desempenhoDisciplinasPeriodoAnterior = desempenhoDisciplinas;

    setDesempenhoDisciplinas(nPeriodos, semestreVigente);

    if(desempenhoDisciplinas.size() != desempenhoDisciplinasPeriodoAnterior.size()){
        ExibirMensagem();
    };

    for(short indice = 0; indice < desempenhoDisciplinas.size(); indice++){
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

};

void GestorAcademico :: exibirDisciplinasAgrupadas(){
    
    unsigned short indice;
    agruparDisciplinas();
    ExibirMensagem("Abaixo disciplinas que estao em estabilidade:");
        indice = 0;
        do{
            if(vetorStatusDisciplinas.size() == 0){
                ExibirMensagem("!Nenhuma disciplina para ser exibida.");
                break;
            }
            if( (vetorStatusDisciplinas[indice].diferenca_percentual < 5) &&\
                (vetorStatusDisciplinas[indice].diferenca_percentual > -5))

                ExibirMensagem(vetorStatusDisciplinas[indice].nome_disciplina);
            indice ++;
        }while(indice != vetorStatusDisciplinas.size());
    
    ExibirMensagem("Abaixo disciplinas que estao em melhora:");
        indice = 0;
        do{
            if(vetorStatusDisciplinas.size()==0){
                ExibirMensagem("!Nenhuma disciplina para ser exibida.");
                break;
            }
            if(vetorStatusDisciplinas[indice].diferenca_percentual > 5)
                ExibirMensagem(vetorStatusDisciplinas[indice].nome_disciplina);
            indice ++;
        }while(indice != vetorStatusDisciplinas.size());
    
    ExibirMensagem("Abaixo disciplinas que estao em piora:");
        indice = 0;
        do{
            if(vetorStatusDisciplinas.size()==0){
                ExibirMensagem("!Nenhuma disciplina para ser exibida.");
                break;
            }
            if(vetorStatusDisciplinas[indice].diferenca_percentual < -5)
                ExibirMensagem(vetorStatusDisciplinas[indice].nome_disciplina);
            indice ++;
        }while(indice != vetorStatusDisciplinas.size());
}

void GestorAcademico :: agruparDisciplinasAlunos(){
    unsigned short  mediaPeriodoAnterior = 0,
                    contador = 0,
                    indice = 0;

    vector <Aluno> estabilidade;
    vector <Aluno> piora;
    vector <Aluno> melhora;

    for(unsigned short indice_ = 0; indice_ < vetorAlunos.size(); indice_++){
                for(indice = 0; indice < (vetorAlunos[indice_].getGrauDisciplinaPeriodo()).size(); indice++){
                    if (!(((vetorAlunos[indice_].getGrauDisciplinaPeriodo())[indice].semestre.ano == semestreVigente.ano) && \
                    ((vetorAlunos[indice_].getGrauDisciplinaPeriodo())[indice].semestre.semestre == semestreVigente.semestre ))){
                
                mediaPeriodoAnterior += (vetorAlunos[indice_].getGrauDisciplinaPeriodo())[indice].grau_obtido;
                contador++; 
            };
        };

        if(contador == 0){
            ExibirMensagemErro(periodosInsuficientes);
            exit(periodosInsuficientes);
        };

        float diferenca_percentual = (mediaPeriodoAnterior/contador - vetorAlunos[indice_].getMedia()) / vetorAlunos[indice_].getMedia();
        
        if((diferenca_percentual > -5) && (diferenca_percentual < 5))
            estabilidade.push_back(vetorAlunos[indice_]);
        if(diferenca_percentual < -5)
            piora.push_back(vetorAlunos[indice_]);
        if(diferenca_percentual > 5)
            melhora.push_back(vetorAlunos[indice_]);
        
        mediaPeriodoAnterior = 0;
        contador = 0;
    };

    indice = 0;
    ExibirMensagem("A seguir, Alunos que estao em estabilidade.");
    do{
        if( estabilidade.size() == 0){
            ExibirMensagem("Nenhum aluno para ser exibido nesta categoria");
            break;
        };

        ExibirMensagem(estabilidade[indice].nomeAluno);
        indice ++;

    }while(indice < estabilidade.size());
    indice = 0;

    ExibirMensagem("A seguir, Alunos que estao em piora.");
    do{
        if( piora.size() == 0){
            ExibirMensagem("Nenhum aluno para ser exibido nesta categoria");
            break;
        };

        ExibirMensagem(piora[indice].nomeAluno);
        indice++;

    }while(indice < piora.size());
    indice = 0;

    ExibirMensagem("A seguir, Alunos que estao em melhora.");
    do{
        if( melhora.size() == 0){
            ExibirMensagem("Nenhum aluno para ser exibido nesta categoria");
            break;
        };

        ExibirMensagem(melhora[indice].nomeAluno);
        indice++;   

    }while(indice < melhora.size());
    indice = 0;

};

void GestorAcademico :: exibirDisciplinaMaiorMedia(){

    vector<unsigned short> indicesMaioreMedias = {0};

    for(unsigned short indice = 0; indice < vetorDisciplinas.size(); indice++){
        if (vetorDisciplinas[indice].getMediaTurma() > vetorDisciplinas[indicesMaioreMedias[0]].getMediaTurma()){
            indicesMaioreMedias = {indice};
            continue;
        };
        if (vetorDisciplinas[indice].getMediaTurma() == vetorDisciplinas[indicesMaioreMedias[0]].getMediaTurma()){
            indicesMaioreMedias.push_back(indice);
        };

    };

    ExibirMensagem( "A(s) disciplina que obteve a maior media foi:");

    short indice = 0;
    if(indicesMaioreMedias.size()>1)
        indice = 1;
    for(; indice < indicesMaioreMedias.size(); indice++){
        string periodo;
        periodo = to_string(vetorDisciplinas[indicesMaioreMedias[indice]].getSemestre().ano) + "." + to_string(vetorDisciplinas[indicesMaioreMedias[indice]].getSemestre().semestre);
        ExibirMensagem( vetorDisciplinas[indicesMaioreMedias[indice]].nomeDisciplina, "na turma de", periodo ,"com media de notas finais equivalente de: ", vetorDisciplinas[indicesMaioreMedias[indice]].getMediaTurma(), ".");
    };
};

void GestorAcademico :: exibirDisciplinaMaiorEvolucao(){
    unsigned short  indiceMaiorEvolucao = 0,
                    maiorEvolucao = 0,
                    indice = 0;
    
    agruparDisciplinas();

    do{
        if(vetorStatusDisciplinas.size() == 0){
            ExibirMensagem("!Nenhuma disciplina para ser exibida.");
            return;
        };

        if( vetorStatusDisciplinas[indice].diferenca_percentual > maiorEvolucao){
            maiorEvolucao = vetorStatusDisciplinas[indice].diferenca_percentual;
            indiceMaiorEvolucao = indice;
        };

        indice ++;
    }while(indice != vetorStatusDisciplinas.size());

    
    ExibirMensagem("Abaixo a disciplina que obteve a maior evolucao:");
    ExibirMensagem( vetorStatusDisciplinas[indiceMaiorEvolucao].nome_disciplina, \
                    ". Com uma diferenca percentual de", maiorEvolucao);    
};

void GestorAcademico :: exibirAlunoMaiorMedia(){
    vector<unsigned short> indicesMaioreMedias = {0};

    for(unsigned short indice = 0; indice < vetorAlunos.size(); indice++){
        if (vetorAlunos[indice].getMedia() > vetorAlunos[indicesMaioreMedias[0]].getMedia()){
            indicesMaioreMedias = {indice};
            continue;
        };
        if (vetorAlunos[indice].getMedia() == vetorAlunos[indicesMaioreMedias[0]].getMedia()){
            indicesMaioreMedias.push_back(indice);
        };

    };

    ExibirMensagem( "O aluno que possui a maior media eh(sao) o(s) aluno(s):");
    
    short indice = 0;
    if(indicesMaioreMedias.size()>1)
        indice = 1;
    for(; indice < indicesMaioreMedias.size(); indice++){
        ExibirMensagem(vetorAlunos[indicesMaioreMedias[indice]].nomeAluno, "com media equivalente de: ", vetorAlunos[indicesMaioreMedias[indice]].getMedia(), ".");
    };

};