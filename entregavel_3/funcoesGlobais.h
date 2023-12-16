#ifndef _FUNCOES_GLOBAIS_
#define _FUNCOES_GLOBAIS_

#include <iostream>

#include "classeHistorico.h"
#include "tipos.h"

class Historico;
struct Disciplina;

using namespace std;

template<typename... tipoGenerico>
void ExibirMensagem(tipoGenerico... argumento)
{
    ((cout << argumento << " "), ...);
    cout << endl;
};

double getMensagem(string, double, double);

int getMensagem(string, int, int);

string getMensagem(string);

void getMensagem();

string getPeriodo();

#endif