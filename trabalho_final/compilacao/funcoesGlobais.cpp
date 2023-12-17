#include <unistd.h>
#include "funcoesGlobais.h"


using namespace std;


int exibirOpcoes(vector<string>& opcoes){ //funcao que exibe o menu interativo

    noecho();
    curs_set(0);

    int limite = 100;
    const char* menu[limite];

    int nOpcoes = opcoes.size();
    int opcao = 0; //posicao do "voltar"
    char tecla;

    for(int n = 0; (n < nOpcoes && n < limite); n++){
        menu [n] = opcoes[n].c_str();
    }

    while(1){
        
        clear();
        refresh();

        for(int indice = 0; indice < nOpcoes; indice++){
            
            if(indice == opcao)
            {   
                setCor(4);
                mvprintw(0, 1, "! Use as teclas W, S e 'enter' para alternar");
                mvprintw(1, 1, "entre as opcoes e selecionar - las");
                resetCor();

                if(opcao == 0){ // se a opcao voltar estiver selecionada, a fonte deve ficar vermelha
                    
                    setCor(2);
                    mvprintw((indice+3), 1, "<<-");
                    mvprintw((indice+3), 4, "%s", menu[indice]);
                    resetCor();

                    continue;
                }
                
                setCor(3);//caso contrario deve ser na cor verde
                mvprintw((indice+3), 1, "->>"); 
                mvprintw((indice+3), 4, "%s",menu[indice]);
                resetCor();

                continue;
            }

            setCor(1);
            mvprintw((indice+3), 1, "%s", menu[indice]);
            resetCor();        
            
        }

        tecla = getch();

        if(tecla == 'W' || tecla == 'w' || tecla == KEY_UP){
            
            if(opcao == 0){
                opcao = (nOpcoes-1);    
                continue;
            }

            opcao--;
            continue;
        }

        if(tecla == 'S' || tecla == 's' || tecla == KEY_DOWN){
            
            if(opcao == (nOpcoes-1)){
                opcao = 0;
                continue;
            }

            opcao++;
            continue;
        }

        if(tecla == 10 || tecla == 13){
            echo();
            curs_set(1);
            return (opcao - 1); // considerando que a primeira linha sempre vai ser uma opcao de voltar/cancelar
        }

    };

    
};

void exibirImagem(string caminhoImagem){
    // exibe a imagem com as alteracoes mais recentes

    noecho();
    curs_set(0);
    setCor(2);
    mvprintw(0, 0, "!! Aguarde ate que a imagem seja exibida.");
    resetCor();

    PyObject* sys = PyImport_ImportModule("sys");
    PyObject* path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_DecodeFSDefault(DIR_COMPILACAO));
    
    PyObject* pModule = PyImport_ImportModule((char *)"funcoes_funcoesGlobais");
    if (pModule != nullptr) {

        // OBtendo a referência da função Python
        PyObject* pFunction = PyObject_GetAttrString(pModule, "exibirArquivoImagem");
        if (pFunction != nullptr && PyCallable_Check(pFunction)) {
            
            // Criando a string de argumento
            PyObject* pArg = Py_BuildValue("s", (caminhoImagem).c_str());

            // Chamando a função Python com o argumento
            PyObject_CallFunctionObjArgs(pFunction, pArg, nullptr);

            Py_DECREF(pArg);
            Py_DECREF(pFunction);
        }
        
        Py_DECREF(pModule);
    }

    getch();
    clear();
    
};

void setCor(int n){
    if(has_colors())
        attron(COLOR_PAIR(n));
};

void resetCor(){
    if(has_colors())
        attroff(COLOR_PAIR(0));
};




