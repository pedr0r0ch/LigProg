#include "classeEdicao.h"
#include "funcoesGlobais.h"

namespace fs = std::filesystem;

//----CONSTRUTOR-E-DESTRUTOR---------------

Edicao :: Edicao(){
};

Edicao :: Edicao(string imagemFundo){
    Camada* camadaPtr = new Camada(imagemFundo, "Imagem de fundo padrao");
    camadas.push_back(camadaPtr);
};

//remove todos os arquivos utilizados mantendo a image resultante
//libera amemoria alocada para os objetos da classe camada
Edicao :: ~Edicao(){
};

//----IMPLEMENTACAO-DE-METODOS-PUBLICOS----

// inclui uma nova camada
void Edicao :: addCamada(){
    
    vector<string> arquivos;
    string descricao,
           nomeArquivo;
    char entrada[100];

    obterNomesArquivos((string(DIR_COMPILACAO) + string(DIR_TRABALHO)), &arquivos);
    int opcao = exibirOpcoes(arquivos);

    
    if(opcao == -1)
        return;
    
    clear();
    refresh();

    setCor(4); noecho();
    mvprintw(0,0,"Descreva a imagem selecionada (%s) em uma unica frase ou palavra.", arquivos[opcao+1].c_str());
    echo();

    mvprintw(3, 0, "Descricao: ");
    
    curs_set(1);
    getstr(entrada);
    curs_set(0);

    descricao = string(entrada);

    if(descricao == "")
        descricao = "Descricao nao fornecida.";

    nomeArquivo = converterArquivo(("../dir_trabalho/" + arquivos[opcao+1]));
    
    setCor(1);
    mvprintw(15, 0, "%s", nomeArquivo.c_str());
    getch();
    
    Camada* camada_ptr = new Camada(nomeArquivo, descricao);
    
    (*camada_ptr).exibirCamada();

    camadas.push_back(camada_ptr);

}; 

//altera a sobreposicao de camadas
void Edicao :: alterarPrioridade(){
    
        
    char bufer[4];
    int prioridade;
    int soma = 0;
    unsigned indiceLinha = 0;

    vector<Camada*> camadas_copia;
    vector<int> prioridades;
    

    clear();
    refresh();
    setCor(4);

    mvprintw(0, 0, "! Digite o numero correspondente da prioridade de cada camada.");


    for(unsigned indice = 0; indice < camadas.size(); indice++){
        
        do{
            noecho();

            setCor(1);
            mvprintw((indiceLinha + 3), 0, "Camada %i . Caminho do Arquivo: %s", (indice + 1), ((*camadas[indice]).getArquivo()).c_str());
            mvprintw((indiceLinha + 4), 0, "Descricao fornecida anteriormente: %s", ((*camadas[indice]).getDescricao()).c_str());
            mvprintw((indiceLinha + 5), 0, "Prioridade que a camada deve ter (um numero de 1 a %li): ", camadas.size());
            echo(); setCor(2);

            getstr(bufer);  
            
            noecho();
            
            try {
                prioridade = stoi(bufer);

            } catch (const invalid_argument& e) {
                setCor(2);
                mvprintw((indiceLinha + 7), 1, "! Erro: O numero submetido eh invalido.");
                getch(); move((indiceLinha + 7), 0); clrtoeol(); 

                continue;
            }

            if(prioridade < 1 || prioridade > (int) camadas.size()){
                setCor(2);
                mvprintw((indiceLinha + 7), 1, "! Erro: Numero fornecido fora do limite estabelecido");
                
                getch(); move((indiceLinha + 7), 0); clrtoeol();
                
                continue;
            }

            break;


        }while(1);

        indiceLinha += 4;

        prioridades.push_back(prioridade);


    };

    for(unsigned n = 0; n < prioridades.size(); n++){
        for(unsigned j = 0; j < prioridades.size(); j++){
            if(prioridades[n] == prioridades[j])
                soma++;
        }
    }

    if(soma != (int) prioridades.size()){
        setCor(2);
        mvprintw((indiceLinha + 7), 1, "! Erro: Camadas difrentes nao podem possuir a mesma prioridade.");
        getch(); move((indiceLinha + 7), 0); clrtoeol();
    }

    for(unsigned n = 0; n < camadas.size(); n++)
        camadas_copia.push_back(camadas[n]);
    
    for(unsigned n = 0; n < camadas.size(); n++)
        camadas[n] = camadas_copia[prioridades[n]-1];
};

//seleciona uma camada para edicao
int Edicao :: selecionarCamada(){
    
    noecho();
    curs_set(0);
    

    int opcao = -1; //posicao do "voltar"
    int indiceLinha = 0;
    char tecla;
    

    while(1){
        
        clear();
        refresh();
        indiceLinha = 0;

        for(int indice = -1; indice < (int) camadas.size(); indice++){
            setCor(4);
            mvprintw(0, 1, "! Por favor selecione a camada que deve ser editada.");
            mvprintw(1, 1, "! Use as teclas W, S e 'enter' para alternar");
            mvprintw(2, 1, "entre as opcoes e selecionar - las");
            resetCor();
            
            if(indice == opcao)
            {   
                if(opcao == -1){ // se a opcao voltar estiver selecionada, a fonte deve ficar vermelha
                    
                    setCor(2);
                    mvprintw((indiceLinha+5), 1, "<<- Voltar e cancelar operacao");
                    resetCor();
                    indiceLinha++;
                    continue;
                }
                
                setCor(3);
                mvprintw((indiceLinha+5), 1, "->> Camada %i", (indice+1));
                resetCor();
                mvprintw((indiceLinha+6), 1, "    - Arquivo de imagem: %s", (*camadas[indice]).getArquivo().c_str());
                mvprintw((indiceLinha+7), 1, "    - Descricao: %s", (*camadas[indice]).getDescricao().c_str());

                indiceLinha += 3;
                continue;
            }

            setCor(1);
            
            if(indice == -1){
                mvprintw((indiceLinha+5), 1, "Voltar e cancelar operacao");
                indiceLinha++;

            }else{
                mvprintw((indiceLinha+5), 1, "Camada %i ", (indice + 1));
                indiceLinha++;
            }
            
            resetCor();        
            
        }

        tecla = getch();

        if(tecla == 'W' || tecla == 'w' || tecla == KEY_UP){
            
            if(opcao == -1){
                opcao = (camadas.size()-1);    
                continue;
            }

            opcao--;
            continue;
        }

        if(tecla == 'S' || tecla == 's' || tecla == KEY_DOWN){
            
            if(opcao == (int) (camadas.size()-1)){
                opcao = -1;
                continue;
            }

            opcao++;
            continue;
        }

        if(tecla == 10 || tecla == 13){
            echo();
            curs_set(1);
            return opcao; // considerando que a primeira linha sempre vai ser uma opcao de voltar/cancelar
        }

    };

    
};

//chama o metodo edicoes gerais de uma camada especifica, possui o indice da camada como parametro
void Edicao :: edicoesGerais(int indice){
    (*camadas[indice]).edicoesGerais();
};

//exibe a edicao atual, que sao todas as camadas sobrepostas
void Edicao :: exibirEdicao(){

    string arquivoCopia; 


    if(camadas.empty())
        return;
    
    if(camadas.size() == 1){
        exibirImagem((*camadas[0]).getArquivo());
        return;
    }

    arquivoCopia = sobreporCamadas();
    exibirImagem(arquivoCopia);

    getch();
};

//----IMPLEMTANCAO-DE-METODOS-PRIVADOS----

//converte um arquivo de imagem qualquer para um .png
string Edicao :: converterArquivo(string nomeArquivo){

    setCor(1);
    mvprintw(15,0,"entrou na funcao");
    getch();
    
    PyObject* sys = PyImport_ImportModule("sys");
    PyObject* path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_DecodeFSDefault(DIR_COMPILACAO));
    
    PyObject* pModule = PyImport_ImportModule("funcoes_funcoesGlobais");

    if (pModule != nullptr) {
        mvprintw(15,0,"moodulo encontrado");
        getch();

        // OBtendo a referência da função Python
        PyObject* pFunction = PyObject_GetAttrString(pModule, "converterArquivo");
        
        if (pFunction != nullptr && PyCallable_Check(pFunction)) {
            
            mvprintw(15,0, "chamando funcao");
            getch();


            PyObject* pArg = Py_BuildValue("s", (nomeArquivo).c_str());
            PyObject  *retorno = PyObject_CallObject(pFunction, pArg);

            if((retorno != NULL) && (PyUnicode_Check(retorno))){
                nomeArquivo = string(PyUnicode_AsUTF8(retorno));
                mvprintw(15,0, "valor atribuido: %s", nomeArquivo.c_str());
                getch();
            }

            mvprintw(15,0, "funcao foi chamada");
            getch();


            
            //Py_XDECREF(pArg);
            //Py_DECREF(retorno);

        }
        //Py_XDECREF(pFunction);
    }
    //Py_XDECREF(pModule);

    return nomeArquivo;      
};

//gera um arquivo, resultado de todas as camadas sobrepostas
string Edicao :: sobreporCamadas(){
    
    string  imagemFundo,
            imagemFrente;

    PyObject    *sys,
                *path,
                *pModule,
                *pFunction,
                *pArgs;
    

    imagemFundo = (*camadas[0]).getArquivo(); 

    sys = PyImport_ImportModule("sys");
    path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_DecodeFSDefault(DIR_COMPILACAO));
    pModule = PyImport_ImportModule("funcoes_classeEdicao");

    if (pModule != nullptr) {

        // OBtendo a referência da função Python
        pFunction = PyObject_GetAttrString(pModule, "sobrepor");
        if (pFunction != nullptr && PyCallable_Check(pFunction)) {
            
            for(unsigned int indice = 1; indice < camadas.size(); indice++){

                imagemFrente = (*camadas[indice]).getArquivo();
                
                pArgs = PyTuple_Pack(3,
                    PyUnicode_DecodeFSDefault(imagemFundo.c_str()),
                    PyUnicode_DecodeFSDefault(imagemFrente.c_str()),
                    PyLong_FromLong((*camadas[indice]).getTransparencia()));
                
                PyObject  *retorno = PyObject_CallObject(pFunction, pArgs);

                if((retorno != NULL) && (PyUnicode_Check(retorno))){
                    imagemFundo = string(PyUnicode_AsUTF8(retorno));
                }
            };

            Py_DECREF(pArgs);
            Py_DECREF(pFunction);
        }
        Py_DECREF(pModule);
    }

    return imagemFundo;      
};

//obtem os nomes dos arquivos de um diretorio e os organiza em vetor de strings na formatacao necessaria para a funcaoe xibir opcoes
void Edicao :: obterNomesArquivos (const string caminho, vector<string>* nomesArquivos) {

    (*nomesArquivos).push_back("Voltar (! encerrar programa)");

    for (const auto& entry : fs::directory_iterator(caminho)) {
        if (fs::is_regular_file(entry.path())) {
            (*nomesArquivos).push_back(entry.path().filename().string());
        }
    }
};

//----IMPLEMTANCAO-DE-OPERADORES-SOBRECARREGADOS----