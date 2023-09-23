#include <iostream>
#include <string>
#include <vector>

#include "classeAlunos.h"
#include "classeDisciplina.h"
#include "tipos.h"
    
using namespace std;

class GestorAcademico{
    public:

        GestorAcademico(unsigned short, unsigned short);
        //construtor

        tipoErros setDesempenhoDisciplinas(unsigned short, tipoSemestre); //calcula as medias moveis das disciplinas\
        e guarda em um vetor com elementos do tipo estrutura tipoDesempenhoDisciplina que guarda a media movel,\
        o nome da disciplina e a quantidade de periodos utilizados para fazer a media movel

        void exibirDisciplinasAgrupadas(); //exibe as disciplinas que foram agrupadas em agruparDiscipinas()

        void evolucaoNotasFinais(); 
        //exibe a evolucao das notas finais dos alunos em 5 disciplinas nos ultimos periodos\
        calculando a media movel de n periodos anteriores ao atual

        void agruparDisciplinas();
        //agrupa disciplinas que obtiveram uma melhoria no \
        desempenho em relacao as notas finais do ultimo periodo

        void agruparDisciplinasAlunos();
        //faz o mesmo que o metodo agruparDisciplinasAdm() so que\
        considerando cada aluno individualmente

        void exibirDisciplinaMaiorMedia();
        //exibe a disciplina com maior media de notas finais em um intervalo

        void exibirDisciplinaMaiorEvolucao();
        //Exibe a disciplina com maior evolucao no ultimo periodo \
        em relacao as notas finais

        void exibirAlunoMaiorMedia();
        //Exibe o aluno com maior media de ultimo periodo
    
    private:

        tipoSemestre semestreVigente;
        
        vector <tipoStatusDisciplinas>    vetorStatusDisciplinas;
        vector <tipoDesempenhoDisciplina> desempenhoDisciplinas; 
        vector <Disciplina>               vetorDisciplinas;
        vector <Aluno>                    vetorAlunos;
};