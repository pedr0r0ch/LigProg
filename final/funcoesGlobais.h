#ifndef _FUNCOES_GLOBAIS_
#define _FUNCOES_GLOBAIS_

#include <iostream>
#include <string>
#include <vector>
#include <ncurses.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_BACKGROUND_WHITE "\x1b[47m"

using namespace std;

double getMensagem(string, double, double);

int getMensagem(string, int, int);

string getMensagem(string);

void getMensagem();

#endif