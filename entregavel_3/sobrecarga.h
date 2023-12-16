#ifndef _SOBRECARGA_
#define _SOBRECARGA_

#include <iostream>
#include <vector>

#include "classeHistorico.h"
#include "tipos.h"

using namespace std;

//exibe uma disciplina individualmente ou todas as disciplinas de um historico
ostream& operator<<(ostream&, const Historico&);
ostream& operator<<(ostream&, const Disciplina&);

//realiza a insercao de disciplinas no historico;
int operator+=(const vector<Disciplina>&, const Disciplina&);
int operator+=(const vector<Disciplina>&, const vector<Disciplina>&);

//faz a comparacao de discilinas
bool operator<(const Disciplina&, const Disciplina&);
bool operator==(const Disciplina&, const Disciplina&);

#endif