#include "classeSistema.h"

Sistema :: Sistema (){
};

void Sistema :: insere(){
    

};

Atleta* Sistema :: busca(){
};

void Sistema :: imprime(){
};

Atleta* Sistema :: operator()(const string nomeAtleta){
    return buscarConteudo(this->raiz, nomeAtleta);
};

Arvore<Atleta>* Sistema :: operator+(const Atleta conteudo){
    this->raiz = adicionarNo(this->raiz, conteudo);
    return this;
};

ostream &operator<<(ostream &out, Arvore<Atleta> arvore){

    arvore.percorrerArvore();
    
    return out;
};

