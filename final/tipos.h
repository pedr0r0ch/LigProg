#ifndef _TIPOS_
#define _TIPOS_

#include <string>

struct edicao{
    string arquivo;
    string descricao;
}; // decricao de um processo realizado na imagem

struct Descricao{
    string arquivo;
    string descricao;
}; // descricao do contexto de cada imagem do campo arquivo

typedef enum{
    sucesso = 0,
    operacao_nao_concluida,
}tipoErros;

#endif