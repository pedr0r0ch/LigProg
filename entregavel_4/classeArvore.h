#ifndef CLASSE_ARVORE
#define CLASSE_ARVORE

#include <iostream>
#include <string>

#include "classeAtleta.h"
#include <vector>
#include <string>

using namespace std;

template <class T> 
class No {
public:
    T conteudo;
    No<T>* esquerda;
    No<T>* direita;

    No(T conteudo, No<T>* esquerda = nullptr, No<T>* direita = nullptr)
        : conteudo(conteudo), esquerda(esquerda), direita(direita) {}
};

template <class T>
class Arvore {
public:
    Arvore(No<T>* raiz = nullptr) : raiz(raiz) {}

    Arvore<T> operator+(T conteudo) {
        raiz = adicionarNo(raiz, conteudo);
        return *this;
    }

    T operator()(const string& nome){
        return buscarConteudo(raiz, nome);
    }

    void getAtributosObjetos(vector<string>* atributosObjetos){
         getAtributosObjetos(raiz, atributosObjetos);
    }

    void desalocarMemoria() {
        desalocarMemoriaRecursivo(raiz);
        raiz = nullptr;
    }

    friend ostream& operator<<(ostream& os, const Arvore<Atleta*> arvore);

private:
    T buscarConteudo(const No<T>* no, const string nome){
        if (no != nullptr) {
            if (((*no).conteudo)->getNome() == nome)
                return (*no).conteudo;
            if (nome < (*no).conteudo->getNome()) 
                return buscarConteudo((*no).esquerda, nome);
            else
                return buscarConteudo((*no).direita, nome);
        }

        return nullptr;
    }

    No<T>* adicionarNo(No<T>* no, T conteudo) {
        if (no == nullptr)
            return new No<T>(conteudo);

        if (conteudo->getNome() < ((*no).conteudo)->getNome())
            (*no).esquerda = adicionarNo((*no).esquerda, conteudo);
        else if (conteudo->getNome() > ((*no).conteudo)->getNome())
            (*no).direita = adicionarNo((*no).direita, conteudo);

        return no;
    }

    void percorrerArvore(const No<T>* no, vector<string>* descricao){
        if (no != nullptr) {
            percorrerArvore((*no).esquerda, descricao);
            (*descricao).push_back(((*no).conteudo)->descricao());
            percorrerArvore((*no).direita, descricao);
        }
    }

    void getAtributosObjetos(const No<T>* no, vector<string>* atributosObjetos){
        
        if(no != nullptr){
            string atributos = "";
            atributos = atributos + ((*no).conteudo)->getNome() + ",";
            atributos = atributos + to_string(((*no).conteudo)->getIdade()) + ",";
            atributos = atributos + ((*no).conteudo)->getTipo();
            (*atributosObjetos).push_back(atributos);

            getAtributosObjetos((*no).esquerda, atributosObjetos);
            getAtributosObjetos((*no).direita, atributosObjetos);
        }
    }

    void desalocarMemoriaRecursivo(No<T>* no) {
        if (no != nullptr) {
            desalocarMemoriaRecursivo(no->esquerda);
            desalocarMemoriaRecursivo(no->direita);
            delete no->conteudo;
            delete no;
        }
    }

    No<T>* raiz;
};
#endif