#include <iostream>
#include <filesystem>

#include "classePrograma.h"
#include "funcoesGlobais.h"
#include "sobrecargas.h"


namespace fs = std::filesystem;

//construtor
ProgramaPrincipal :: ProgramaPrincipal(string diretorioTrabalho){
    this->diretorioTrabalho = diretorioTrabalho;

    system("clear");

    cout << "Diretorio de trabalho:" << diretorioTrabalho << endl;
    cout << "Estes sao todos os aquivos de imagem do diretorio:" << endl;


    for (const string& nome_arquivo : fs::directory_iterator(diretorioTrabalho)) {
        cout << "-" << nome_arquivo << endl;
        Imagem imagem((diretorioTrabalho + nome_arquivo));
        this->imagens << imagem;
    }

};

//menu de inicio, para selecionar o arquivo de imagem base
tipoErros ProgramaPrincipal :: iniciar(){
    
    unsigned int indice_imagem;

    cout << "Eh necessario selecionar um dos arquivos de imagen a seguir para continuar coma a edicao" << endl;
    
    cout << '\n' << "0 - Sair (digite 0 para encerrar a operacao)" << endl;
    
        cout << imagens;

    indice_imagem = (unsigned) getMensagem("Por favor selecione um arquivo usando o numero correnspondente: ", 0, imagens.size());

    if (indice_imagem == 0)
        return operacao_nao_concluida;

    Edicao edicao;
    edicao.arquivo = 
};