#ifndef _FUNCOES_GLOBAIS_
#define _FUNCOES_GLOBAIS_

#include <iostream>
#include <string>
#include <vector>
#include <ncurses.h>

#define ESPACAMENTO 3

using namespace std;

int exibirMenu(vector<string>, string); //exibe o menu, e pega a opcao do usuario

//[numero da getline] getMensagem([mensagem], [limite inferior], [limite superior])
double getMensagem(string, double, double);

int getMensagem(string, int, int);

string getMensagem(string);

void getMensagem();

int exibirMenu(const char* menu[], const unsigned);

#endif