#include "classeAlunos.h"
#include "funcoesGlobais.h"

Aluno::Aluno(string nome, vector<tipoNota> informacoesAcademicas){
    nomeAluno = nome;
    grauDisciplinaPeriodo = informacoesAcademicas;
};

void Aluno::setMediaAluno(){
    
    unsigned short  indice,
                    contador= 0;
    float soma = 0;

    for(indice = 0; indice < grauDisciplinaPeriodo.size(); indice++){
        soma += grauDisciplinaPeriodo[indice].grau_obtido;
        contador++;
        }

    media = (soma / (contador));

};

float Aluno :: getGrauObtido(string disciplina, tipoSemestre semestre){
    unsigned short indice;
    for(indice = 0; indice < grauDisciplinaPeriodo.size(); indice++){
        if (grauDisciplinaPeriodo[indice].nome_disciplina == disciplina &&
            grauDisciplinaPeriodo[indice].semestre.ano == semestre.ano &&
            grauDisciplinaPeriodo[indice].semestre.semestre == semestre.semestre)
            return grauDisciplinaPeriodo[indice].grau_obtido;
    }
    
    ExibirMensagemErro(disciplinaNaoConsta);
    return disciplinaNaoConsta;
};

float Aluno :: getMedia (){
    return media;
};

vector <tipoNota> Aluno :: getGrauDisciplinaPeriodo(){
    return grauDisciplinaPeriodo;
};