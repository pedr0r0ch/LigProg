#ifndef _CLASSE_HISTORICO_
#define _CLASSE_HISTORICO_

#include <iostream>
#include <string>
#include <vector>

#include "tipos.h"

using namespace std;

class Historico{
    public:
        Historico(string, unsigned int);
        ~Historico();

        Disciplina& getDisciplina(int);

        //exibe no terminal o catalogo de disciplinas ou uma disciplina individual
        friend ostream& operator<<(ostream&, const Historico&);
        friend ostream& operator<<(ostream&, const Disciplina&);

        //realiza a insercao de disciplinas no historico;
        friend int operator+=(Historico&, const Disciplina&);
        friend int operator+=(Historico&, const vector<Disciplina>&);

        //faz a comparacao de discilinas
        friend bool operator<(const Disciplina&, const Disciplina&);
        friend bool operator==(const Disciplina&, const Disciplina&);
        
        //remove discipinas do historico
        friend int operator-=(const Historico&, string);

        //busca disciplina no historico
        int operator()(string) const;

        //altera uma nota em determinada disciplina
        int operator ()(string, double);

        //remove discipinas do historico
        int operator-= (Disciplina&);

        //calcular cra
        void operator>>(double&);


    private:

        unsigned int numeroMaximoDisciplinas;
        vector<Disciplina> vetorDisciplinas;
        string nomeArquivo;
};

#endif