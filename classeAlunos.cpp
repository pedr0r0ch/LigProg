#include "classeAlunos.h"
#include "funcoesGlobais.h"

Aluno::Aluno(string nome, vector<tipoNota> informacoesAcademicas){
    nomeAluno = nome;
    grauDisciplinaPeriodo = informacoesAcademicas;
    setMediaAluno();
};

void Aluno::setMediaAluno(){
    
    unsigned short indice,
                   soma;

    for(indice = 0; indice < grauDisciplinaPeriodo.size(); indice++)
        soma = grauDisciplinaPeriodo[indice].grau_obtido;

    media = (soma / (indice + 1));
};

float Aluno :: getGrauObtido(string disciplina){
    unsigned short indice;
    for(indice = 0; indice < grauDisciplinaPeriodo.size(); indice++){
        if (grauDisciplinaPeriodo[indice].nome_disciplina == disciplina)
            return grauDisciplinaPeriodo[indice].grau_obtido;
    }
    
    ExibirMensagemErro(disciplinaNaoConsta);
    return disciplinaNaoConsta;
};

float Aluno :: getMedia (){
    return media;

};