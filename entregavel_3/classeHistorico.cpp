
#include <iostream>
#include <string>
#include <fstream>

#include "classeHistorico.h"
#include "funcoesGlobais.h"
#include "tipos.h"

using namespace std;

Historico::Historico (string nomeArquivo_, unsigned int numeroMaximoDisciplinas_){
    
    fstream arquivo(nomeArquivo_);

    if(arquivo.is_open()){

        cout << "Lendo o arquivo '" << nomeArquivo_ << "' :" << endl;
        
        string linha;
        unsigned int indice = 0;

        while(getline(arquivo, linha))
            {
                if(indice == numeroMaximoDisciplinas_){
                    cout << "Limite maximo de discilinas excedido" << endl;
                    break;
                }

                Disciplina disciplina;
    
                disciplina = linha;
    
                vetorDisciplinas.push_back(disciplina);
                
                cout << linha << endl;

                indice++;
            }

        arquivo.close();
    }else { 
        cout << "Nao foi possivel abrir o arquivo padrao. " << endl;
    }
    
    this->nomeArquivo = nomeArquivo_;
    this->numeroMaximoDisciplinas =  numeroMaximoDisciplinas_;
    getMensagem();

};
Historico::~Historico(){

    std::ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;;
    }

    for (const Disciplina& disciplina : vetorDisciplinas) {
        arquivo << disciplina.nome << ',' << disciplina.periodo << ',' << disciplina.grau << ',' << disciplina.credito << '\n';
    }

    arquivo.close();

    cout << "Dados salvos no arquivo '" << nomeArquivo << "'." << endl;

};

Disciplina& Historico :: getDisciplina(int indice){
    return vetorDisciplinas[indice];
};

//busca disciplina no historico
int Historico :: operator()(string nome) const{
    
    unsigned short indice;

    for(indice = 0; indice < vetorDisciplinas.size(); indice++){
        if(vetorDisciplinas[indice].nome == nome)
            return (int) indice;
    }

    return -1;
};

//altera uma nota em determinada disciplina
int Historico :: operator ()(string nome, double nota){

    unsigned short indice;

    for(indice = 0; indice < vetorDisciplinas.size(); indice++){
        if(vetorDisciplinas[indice].nome == nome){
            vetorDisciplinas[indice].grau = nota;
            return (int) indice;
        }
    }

    return -1;
};

//remove discipinas do historico
int Historico :: operator -= (Disciplina& disciplina){
    
    int indice;
    indice = (*this)(disciplina.nome);
    
    if(indice != -1){
        vetorDisciplinas.erase(vetorDisciplinas.begin() + indice);
        return indice;    
    }

    return -1;
};

void Historico :: operator>>(double& cra){
    
    double somaPontuacao = 0; //pontuacao eh o produto de grau pelo credito de uma disciplina
    int somaCreditos = 0;

    for(unsigned short indice = 0; indice < vetorDisciplinas.size(); indice++){
        somaPontuacao += vetorDisciplinas[indice].grau * (double) vetorDisciplinas[indice].credito;
        somaCreditos += vetorDisciplinas[indice].credito;
    }

    cra = somaPontuacao / (double) somaCreditos;
};




