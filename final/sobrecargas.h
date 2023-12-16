#ifndef _SOBRECARGA_
#define _SOBRECARGA_

#include <vector>
#include "classeImagem.h"

void operator<<(vector<Imagem>&, Imagem&); // adiciona uma nova imagem ao vetor de imagens  
     
ostream& operator<<(ostream&, const vector<Imagem>&); //Exibe na tela todo vetor de objetos imagem

#endif