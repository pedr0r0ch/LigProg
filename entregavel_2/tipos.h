#ifndef _TIPOS_
#define _TIPOS_

using namespace std;

typedef enum {
    sucesso = 0,
    arquivoNEncontrado,
    arestaJaExiste,
    verticeNExiste,
    EntradaInvalida,
} tipoErros;


typedef struct{
    void* elemento;
    void* proximo;
    void* anterior;
}lista;

#endif