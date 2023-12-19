#ifndef _FUNCOES_GLOBAIS_
#define _FUNCOES_GLOBAIS_

#include "/usr/include/python3.10/Python.h"

#include <iostream>
#include <ncurses.h>
#include <vector>
#include <string>

#include "tipos.h"


using namespace std;

int exibirOpcoes(vector<string>&);

void exibirImagem(string);

void setCor(int);

void resetCor();

void copiarConteudo(string *, string);

string obterDiaHoraAtual();


#endif