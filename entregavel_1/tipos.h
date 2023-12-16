#ifndef __TIPOS__ 
#define __TIPOS__

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

typedef struct{
    unsigned short ano;
    unsigned short semestre;
}tipoSemestre;

typedef struct{
    float grau_obtido;
    tipoSemestre semestre;
    string nome_disciplina;
}tipoNota;

typedef struct{
    string nome_disciplina;
    float media_movel;
    unsigned short n_periodo;
} tipoDesempenhoDisciplina;

typedef struct{
    string nome_disciplina;
    float diferenca_percentual;
    tipoSemestre semestre;
}tipoStatusDisciplinas;

typedef enum{
    sucesso=0,
    tamanhosDiferentes, //Erro indica que os tamnhos dos vetores de notas e disciplinas nao sao compativeis,\
    ou seja, alguma disciplina esta sem nota ou alguma nota esta sem disciplina.
    disciplinaNaoConsta, //uma disciplina que estava sendo procurada nao consta no sitema.
    anoNaoConsta,
    periodosInsuficientes
}tipoErros;

typedef enum {
    desabilitado = 0, //sinal desabilitado (pegar um numero sem sinal)
    habilitado = 1 //sinal habilitadado (pegar um numero com sinal) 
}tipoSinal;


#endif