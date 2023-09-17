#include <iostream>
#include <string>
#include <vector>

#include "classeAlunos.h"
#include "classeDisciplina.h"
#include "tipos.h"
    
using namespace std;

class GestorAcademico{
    public:

        GestorAcademico(tipoSemestre, vector<Disciplina>, vector<Aluno>);
        //construtor

        void evolucaoNotasFinais(); 
        //exibe a evolucao das notas finais dos alunos em 5 disciplinas nos ultimos periodos

        void agruparDisciplinasAdm();
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
        vector<Disciplina> vetorDisciplinas;
        vector<Aluno> vetorAlunos;
};