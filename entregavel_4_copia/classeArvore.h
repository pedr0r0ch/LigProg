#ifndef CLASSE_ARVORE
#define CLASSE_ARVORE

#include <iostream>
#include <string>

#include "tipos.h"
#include "classeAtleta.h"

using namespace std;

template <class T> 
class No{

    No(T conteudo, No<T>* noAnterior = nullptr, No<T>* proximoNo = nullptr){
        this->conteudo = conteudo;
        this->noAnterior = noAnterior;
        this->proximoNo = proximoNo;
    };

    public:
        T   conteudo;
        No<T>* noAnterior;
        No<T>* proximoNo;
};

template <class T>
class Arvore {
    public:
        Arvore(No<T>* raiz = nullptr) {
            this->raiz = raiz;
        }

        T* buscarConteudo(No<T>* no, const std::string& nome) {
            if (no != nullptr) {
                buscarConteudo(no->esquerda, nome);
                if (no->conteudo.getNome() == nome)
                    return &no->conteudo;
                buscarConteudo(no->direita, nome);
            }

            return nullptr;
        }

        No<T>* adicionarNo(No<T>* no, T conteudo) {
            if (no == nullptr)
                return new No<T>(conteudo);

            if (conteudo.getNome() < no->conteudo.getNome())
                no->esquerda = adicionarNo(no->esquerda, conteudo);
            else if (conteudo.getNome() > no->conteudo.getNome())
                no->direita = adicionarNo(no->direita, conteudo);

            return no;
        }

        void percorrerArvore(No<T>* no) {
            if (no != nullptr) {
                percorrerArvore(no->esquerda);
                no->conteudo.descricao();
                percorrerArvore(no->direita);
            }
        }

    protected:
        No<T>* raiz;
};

#endif