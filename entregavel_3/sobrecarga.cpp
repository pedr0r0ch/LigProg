#include "sobrecarga.h"

//exibe no terminal o catalogo de disciplinas ou uma disciplina individual
ostream& operator<<(ostream& os, const Historico& historico){
    for(short indice = 0; indice < (short) historico.vetorDisciplinas.size(); indice++){
        cout << (historico.vetorDisciplinas[indice]);
        if(indice != (short)historico.vetorDisciplinas.size() - 1)
            os << "-----------------------------------------------" << '\n';
    }

    return os;
};

ostream& operator<<(ostream& os, const Disciplina& disciplina){

    os << "Nome da disciplina: " << disciplina.nome << '\n';
    os << "Periodo em que a disciplina foi cursada: " << disciplina.periodo << '\n';
    os << "Grau obtido na disciplina: " << to_string(disciplina.grau) << '\n';
    os << "Creditos da disciplina: " << to_string(disciplina.credito) << '\n';

    return os;

};

//realiza a insercao ordenada de disciplinas no historico;
int operator+=(Historico& historico, const Disciplina& disciplina){
    for (unsigned short indice = 0; indice < historico.vetorDisciplinas.size(); ++indice) {
        if (historico.vetorDisciplinas[indice] == disciplina) {
            return -1;  // Disciplina igual já existe no vetor
        }
    }

    for (unsigned short indice = 0; indice < historico.vetorDisciplinas.size(); ++indice) {
        if (disciplina < historico.vetorDisciplinas[indice]) {
            historico.vetorDisciplinas.insert(historico.vetorDisciplinas.begin() + indice, disciplina);
            return indice;  // Disciplina inserida em uma posição específica
        }
    }

    historico.vetorDisciplinas.push_back(disciplina);
    return historico.vetorDisciplinas.size() - 1;
}

int operator+=(Historico& historico, const vector<Disciplina>& disciplina){
    
    int indice = -1;

    for(unsigned short indice_ = 0; indice_ < disciplina.size(); indice_++)
        indice = (historico += disciplina[(int) indice_]);
    
    return indice;
};

//faz a comparacao de discilinas
bool operator<(const Disciplina& disciplina_1, const Disciplina& disciplina_2) {
    
    // Compara com base no período
    //se periodo estiver formatado nao eh presiso fazer conversao numerica
    if (disciplina_1.periodo < disciplina_2.periodo) {
        return true;
    } else if (disciplina_1.periodo == disciplina_2.periodo) {
        // Se o período for o mesmo, compara com base no nome
        return disciplina_1.nome < disciplina_2.nome;
    }
    return false;
}

bool operator==(const Disciplina& disciplina_1, const Disciplina& disciplina_2){
    if (disciplina_1.nome == disciplina_2.nome)
        return true;
    return false;
};

istream& operator>>(istream& input, Disciplina& disciplina) {
        cout << "Digite o nome da disciplina: ";
        input >> disciplina.nome;
        
        disciplina.periodo = getPeriodo();
        disciplina.grau = getMensagem("Grau obtido na disciplina: ", 0.0, 10.0);
        disciplina.credito = getMensagem("Creditos da disciplina: ", 1, 10);

        return input;
};
