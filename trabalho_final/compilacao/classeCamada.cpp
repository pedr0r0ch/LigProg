#include "/usr/include/python3.10/Python.h"
#include "classeCamada.h"

using namespace std;

//----CONSTRUTOR-E-DESTRUTOR---------------
Camada :: Camada(string nomeArquivo, string descricao){
    this->transparencia = 255;
    this->imagem = nomeArquivo;
    this->descricao = descricao;
};

Camada :: ~Camada(){

};

//----IMPLEMENTACAO-DE-METODOS-PUBLICOS----

//retorna a trasparencia da camada
unsigned Camada :: getTransparencia(){
   return (unsigned)this->transparencia; 
}; 

//metodo para definir a transparencia da camada
void Camada :: setTransparencia(){
    clear();
    
    char mensagem[4];
    int transparencia;

    do{
        mvprintw(4, 1, "Digite a porcentagem da transparencia da imagem: ");
        getstr(mensagem);

        try {
            transparencia = stoi(mensagem);

        } catch (const invalid_argument& e) {
            
            setCor(2);
            mvprintw(10, 1, "! Erro: O numero submetido eh invalido.");
            setCor(4);
            mvprintw(1, 1, "! Pressione enter para prosseguir.");
            resetCor();
            
            getch();

            move(10, 0);
            clrtoeol();
            move(1, 0);
            clrtoeol();

            continue;
        }

        if(transparencia < 0 || transparencia > 100){
            
            setCor(2);
            mvprintw(10, 1, "! Erro: Apenas sao permitidos numeros entre 0 e 100.");
            resetCor();

            setCor(4);
            mvprintw(1, 1, "! Pressione enter para prosseguir.");
            resetCor();
            
            getch();

            move(10, 0);
            clrtoeol();
            move(1, 0);
            clrtoeol();

            continue;
        }
       
        break;
    }while(1);

    this->transparencia = transparencia;
};

//metodo com opcoes gerais como remover fundo, aplicar efeito de desfoque etc.
void Camada :: edicoesGerais(){
    
    int opcao;

    vector<string> menu = {
        "Voltar e cancelar operacao",
        "Recortar objeto e remover fundo",
        "Aplicar efeito de profundidade de campo",
        "Abrir menu de opcoes de cor e luz",

    };

    opcao = exibirOpcoes(menu);

    if(opcao == -1)
        return;

    switch(opcao){
        case 0:
            removerFundo();
            break;
        case 1:
            profundidadeCampo();
            break;
        case 2:
            menuLuzCor();
            break;
    }
};

//metodo que exibe a camada na tela
void Camada :: exibirCamada(){
    exibirImagem(getArquivo());
};

//retorna a descricaod da camada
string Camada :: getDescricao(){
    return descricao;
};

//retorna o nome do arquivo utilizado na camada
string Camada :: getArquivo(){
    return imagem;
};

//----IMPLEMENTACAO-DE-METODOS-PRIVADOS----

//remove o plano de fundo, restando apenas a imagem
void Camada :: removerFundo(){
    
    string arquivo_copia = "";
    int opcao;

    PyObject  *sys,
              *path,
              *modulo,
              *funcao,
              *argumento,
              *retorno;
        
    Py_Initialize(); //inicializa a API
    sys = PyImport_ImportModule("sys");
    path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_DecodeFSDefault(DIR_COMPILACAO));
    
    modulo = PyImport_ImportModule((char *)"funcoes_classeCamada");
    if (modulo != nullptr) {

        funcao = PyObject_GetAttrString(modulo, "manterObjeto");
        if (funcao != nullptr && PyCallable_Check(funcao)) {
            setCor(1);
            mvprintw(13, 9, "Chamando funcao");
            getch();

            argumento = Py_BuildValue("s", imagem.c_str());

            retorno = PyObject_CallFunctionObjArgs(funcao, argumento, nullptr);
            
            setCor(1);
            mvprintw(13, 9, "Funcao executada");
            getch();

            if(retorno != NULL){
                const char* resultado_cstr = PyUnicode_AsUTF8(retorno);
                arquivo_copia = string(resultado_cstr);

                setCor(1);
                mvprintw(13, 9, "Resultado %s", resultado_cstr);
                getch();
            }
        }
        
    }

    Py_Finalize();//finaliza a API

    if(arquivo_copia != "")
            exibirImagem(arquivo_copia);   

    vector<string> opcoes =  { "Descartar alteracao e voltar",
                               "Salvar alteraco"};
    opcao = exibirOpcoes(opcoes);

    if(opcao == -1)
        return;

    if(arquivo_copia != ""){
        copiarConteudo(imagem, arquivo_copia);
        remove(arquivo_copia.c_str());
        return;
    }

    clear();
    setCor(3);
    mvprintw(0, 0, "Pressione enter para continuar");
    setCor(4);
    mvprintw(2, 0, "Erro inesperado ao concluir operacao, tente novamnete");
    resetCor();
    getch();

    Py_DECREF(modulo);
    Py_DECREF(retorno);
    Py_DECREF(argumento);
    Py_DECREF(funcao);

    return;

};

//aplica efeito de desfoque na intensidade escolhida pelo usuario
void Camada :: profundidadeCampo(){
    
    PyObject  *sys,
              *path,
              *modulo,
              *funcao,
              *argumentos,
              *retorno;

    int opcao = -1;
    string arquivo_copia = "";
    vector<string> opcoes = {"Voltar e cancelar operacao",
                             "Intensidade 1 (Menos desfocado)",
                             "Intensidade 2",
                             "Intensidade 3",
                             "Intensidade 4 (Moderadamente desfocado)",
                             "Intensidade 5",
                             "Intensidade 6",
                             "Intensidade 7 (Mais desfoacado)",
                             "Salvar e sair"};

    while(1){
        opcao = exibirOpcoes(opcoes); 
        
        if(opcao == -1)
            return;

        if(opcao != 8){

            if(arquivo_copia != "")
                remove(arquivo_copia.c_str());

            Py_Initialize(); //inicializa a API
            sys = PyImport_ImportModule("sys");
            path = PyObject_GetAttrString(sys, "path");
            PyList_Append(path, PyUnicode_DecodeFSDefault(DIR_COMPILACAO));
            
            modulo = PyImport_ImportModule((char *)"funcoes_classeCamada");
            if (modulo != nullptr) {

                funcao = PyObject_GetAttrString(modulo, "efeitoDesfoque");
                if (funcao != nullptr && PyCallable_Check(funcao)) {
                    
                    argumentos = PyTuple_Pack(2, 
                    PyUnicode_DecodeFSDefault(imagem.c_str()), PyLong_FromLong((opcao + 1)*2));

                    retorno = PyObject_CallObject(funcao, argumentos);
                    

                    if(retorno != NULL){
                        const char* resultado_cstr = PyUnicode_AsUTF8(retorno);
                        arquivo_copia = string(resultado_cstr);

                        setCor(1);
                        mvprintw(13, 9, resultado_cstr);
                        getch();
                    }
                }
                
            }
            
            Py_Finalize();//finaliza a API
        }
        if(arquivo_copia != "")
            exibirImagem(arquivo_copia);   

        if(opcao == 8){

            if(arquivo_copia != ""){
                copiarConteudo(imagem, arquivo_copia);
                remove(arquivo_copia.c_str());
                return;
            }

            clear();
            setCor(3);
            mvprintw(0, 0, "Pressione enter para continuar");
            setCor(4);
            mvprintw(2, 0, "Erro inesperado ao concluir operacao, tente novamnete");
            resetCor();
            getch();

            Py_DECREF(modulo);
            Py_DECREF(retorno);
            Py_DECREF(argumentos);
            Py_DECREF(funcao);

            return;
        }
    };

    

};

//altera brilho, saturacao e contraste
void Camada :: menuLuzCor(){
    curs_set(0);
    
    int opcao_1,
        opcao_2;
    
    PyObject  *sys,
              *path,
              *modulo,
              *funcao,
              *argumentos,
              *retorno;

    string arquivo_copia = "";

    vector<string> efeitos = {"Contraste", "Brilho", "Saturacao"};

    vector<string> opcoes_1 = {   "Voltar e cancelar operacao",
                                "Alterar niveis de contraste",
                                "Alterar niveis de brilho",
                                "Alterar niveis de saturacao",
                                "Salvar alteracoes e sair"};
    vector<string> opcoes_2;

    

    while(1){
        
        opcao_1 = exibirOpcoes(opcoes_1);
        if(opcao_1 == -1)
            return;
        
        opcoes_2 = { "Voltar",
                     "Diminuir " + efeitos[opcao_1] + " para o nivel 0",
                    "Diminuir " + efeitos[opcao_1] + " para o nivel 1",
                    "Diminuir " + efeitos[opcao_1] + " para o nivel 2",
                    "Diminuir " + efeitos[opcao_1] + " para o nivel 3",
                    "Manter " + efeitos[opcao_1] + " no nivel 4",
                    "Almentar " + efeitos[opcao_1] + " para o nivel 5",
                    "Almentar " + efeitos[opcao_1] + " para o nivel 6",
                    "Almentar " + efeitos[opcao_1] + " para o nivel 7",
                    "Almentar " + efeitos[opcao_1] + " para o nivel 8"}; 

        opcao_2 = exibirOpcoes(opcoes_2);
        
        if(opcao_2 == -1)
            continue;
        
        if(opcao_1 != 3){

            if(arquivo_copia != "")
                remove(arquivo_copia.c_str());

            Py_Initialize(); //inicializa a API
            
            sys = PyImport_ImportModule("sys");
            path = PyObject_GetAttrString(sys, "path");
            PyList_Append(path, PyUnicode_DecodeFSDefault(DIR_COMPILACAO));
            
            modulo = PyImport_ImportModule("funcoes_classeCamada");
            
            if (modulo != nullptr) {

                funcao = PyObject_GetAttrString(modulo, ("alterar" + efeitos[opcao_1]).c_str());
                if (funcao != nullptr && PyCallable_Check(funcao)) {
                    
                    argumentos = PyTuple_Pack(2, PyUnicode_DecodeFSDefault(imagem.c_str()),
                            PyLong_FromLong(((double)opcao_2 / 7.0) * 2.0));

                    retorno = PyObject_CallObject(funcao, argumentos);

                    if((retorno != NULL) && (PyUnicode_Check(retorno))){
                        const char* resultado_cstr = PyUnicode_AsUTF8(retorno);
                        arquivo_copia = string(resultado_cstr);
                    }
                }         
            }
            Py_Finalize();//finaliza a API  
        }

        if(opcao_1 == 3){
            
            if(arquivo_copia != ""){
                copiarConteudo(imagem, arquivo_copia);
                remove(arquivo_copia.c_str());
                return;
            }

            clear();
            setCor(3);
            mvprintw(0, 0, "Pressione enter para continuar");
            setCor(4);
            mvprintw(2, 0, "Erro inesperado ao concluir operacao, tente novamnete");
            resetCor();
            getch();

            Py_DECREF(modulo);
            Py_DECREF(retorno);
            Py_DECREF(argumentos);
            Py_DECREF(funcao);

            return;

        }

    }
};

//copia o conteudo de arquivo 1 para o arquivo 2
void Camada :: copiarConteudo(string receptor, string doador){
    
    PyObject  *sys,
              *path,
              *modulo,
              *funcao,
              *argumentos;
    
    Py_Initialize(); //inicializa a API
    sys = PyImport_ImportModule("sys");
    path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_DecodeFSDefault(DIR_COMPILACAO));
    
    modulo = PyImport_ImportModule((char *)"funcoes_funcoesGlobais");
    if (modulo != nullptr) {

        funcao = PyObject_GetAttrString(modulo, "copiarArquivoImagem");
        if (funcao != nullptr && PyCallable_Check(funcao)) {
            
            argumentos = PyTuple_Pack(2,
                    PyUnicode_DecodeFSDefault(receptor.c_str()),
                    PyUnicode_DecodeFSDefault(doador.c_str()));

            PyObject_CallObject(funcao, argumentos);

            Py_DECREF(argumentos);
            Py_DECREF(funcao);
        }
        
        Py_DECREF(modulo);
    }

    Py_Finalize();//finaliza a API
};



