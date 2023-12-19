#include <unistd.h>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

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

void mensagemDeAviso(string mensagem){
    clear();
    curs_set(0);
    
    setCor(4);
    mvprintw(0, 0, "Pressione enter para prosseguir");
    setCor(5);
    mvprintw(1, 0, "!! %s", mensagem.c_str());
    resetCor();
    getch();

    clear();

    setCor(5);
    mvprintw(0, 0, "!! %s", mensagem.c_str());
    resetCor();
};

void exibirImagem(string caminhoImagem){
    // exibe a imagem com as alteracoes mais recentes

    noecho();
    curs_set(0);
    setCor(2);
    clear();
    mvprintw(0, 0, "!! Aguarde ate que a imagem seja exibida.");
    resetCor();

    PyObject* sys = PyImport_ImportModule("sys");
    PyObject* path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_DecodeFSDefault(DIR_COMPILACAO));
    
    PyObject* pModule = PyImport_ImportModule((char *)"globais");
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

//copia o conteudo de arquivo 1 para o arquivo 2
void copiarConteudo(string *receptor, string doador){
    
    PyObject  *sys,
              *path,
              *modulo,
              *funcao,
              *argumentos,
              *retorno;
    
    
    sys = PyImport_ImportModule("sys");
    path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_DecodeFSDefault(DIR_COMPILACAO));
    
    modulo = PyImport_ImportModule((char *)"globais");
    if (modulo != nullptr) {

        funcao = PyObject_GetAttrString(modulo, "copiarArquivoImagem");
        if (funcao != nullptr && PyCallable_Check(funcao)) {
            
            argumentos = PyTuple_Pack(2,
                    PyUnicode_DecodeFSDefault((*receptor).c_str()),
                    PyUnicode_DecodeFSDefault(doador.c_str()));

            retorno = PyObject_CallObject(funcao, argumentos);
            
            if(retorno != NULL)
                (*receptor) = string(PyUnicode_AsUTF8(retorno));

            Py_DECREF(argumentos);
            Py_DECREF(funcao);
        }
        
        Py_DECREF(modulo);
    }

    //finaliza a API
};

//retorna uma string contendo data e hora
string obterDiaHoraAtual() {
    auto agora = chrono::system_clock::now();
    time_t tempoAtual = chrono::system_clock::to_time_t(agora);

    ostringstream ss;
    ss << put_time(localtime(&tempoAtual), "%Y%m%d_%H%M%S");

    // Obter os milissegundos atuais
    auto duracao = agora.time_since_epoch();
    auto milissegundos = chrono::duration_cast<chrono::milliseconds>(duracao).count() % 1000;

    // Adicionar os milissegundos à string
    ss << '_' << setfill('0') << setw(3) << milissegundos;

    // Substituir caracteres não permitidos por sublinhados
    for (char& c : ss.str()) {
        if (!isalnum(c) && c != '_' && c != '-') {
            c = '_';
        }
    }

    return ss.str();
}


