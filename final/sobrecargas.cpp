#include "sobrecargas.h"

void operator<<(vector<Imagem>& vetorImagem, Imagem& imagem){
    vetorImagem.push_back(imagem);
};       
