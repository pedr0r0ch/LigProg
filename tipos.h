#ifndef __TIPOS__ 
#define __TIPOS__

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

typedef struct{
    unsigned short ano;
    unsigned short semestreLetivo;
}tipoSemestre;

typedef struct{
    float grauObtido;
    tipoSemestre semestre;
    string disciplina;
}tipoNota;

typedef enum{
    sucesso=0,
    tamanhosDiferentes, //Erro indica que os tamnhos dos vetores de notas e disciplinas nao sao compativeis,\
    ou seja, alguma disciplina esta sem nota ou alguma nota esta sem disciplina.
    disciplinaNaoConsta //uma disciplina que estava sendo procurada nao consta no sitema.
}tipoErros;

#endif