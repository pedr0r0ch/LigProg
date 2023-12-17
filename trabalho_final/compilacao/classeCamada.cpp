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
        "Definir transparencia da camada",
        "Recortar objeto e remover fundo",
        "Aplicar efeito de profundidade de campo",
        "Abrir menu de opcoes de cor e luz",

    };

    opcao = exibirOpcoes(menu);

    if(opcao == -1)
        return;

    switch(opcao){
        case 0:
            setTransparencia();
            break;

        case 1:
            removerFundo();
            break;
        
        case 2:
            profundidadeCampo();
            break;
        
        case 3:
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
    
    vector<string> opcoes =  { "Descartar alteracao e voltar",
                               "Salvar alteraco"};
    string arquivo_copia = "";
    int opcao;
        
    
    clear();
    curs_set(0);
    noecho();

    setCor(5);
    mvprintw(0, 0, "!! Aguarde ate que a operaco saja concluida");
    resetCor();

    PyObject  *sys = PyImport_ImportModule("sys");
    PyObject  *path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_DecodeFSDefault(DIR_COMPILACAO));
    
    PyObject  *modulo = PyImport_ImportModule((char *)"funcoes_classeCamada");
    if (modulo != nullptr) {

        PyObject  *funcao = PyObject_GetAttrString(modulo, "manterObjeto");
        if (funcao != nullptr && PyCallable_Check(funcao)) {

            PyObject  *argumento = Py_BuildValue("s", imagem.c_str());

            PyObject  *retorno = PyObject_CallFunctionObjArgs(funcao, argumento, nullptr);
            
            if(retorno != NULL){
                arquivo_copia = string(PyUnicode_AsUTF8(retorno));
            }


            Py_DECREF(retorno);
            Py_DECREF(argumento);
        }
        Py_DECREF(funcao);                
    }

    Py_DECREF(sys);
    Py_DECREF(path);
    Py_DECREF(modulo);


    if(arquivo_copia != "")
            exibirImagem(arquivo_copia);   

    opcao = exibirOpcoes(opcoes);

    if(opcao == -1)
        return;

    if(arquivo_copia != ""){
        remove(imagem.c_str());
        copiarConteudo(&imagem, arquivo_copia);
        remove(arquivo_copia.c_str());
        return;
    }

    clear();
    setCor(4);
    mvprintw(0, 0, "Pressione enter para continuar");
    setCor(1);
    mvprintw(2, 0, "Arquivo nao salvo");
    resetCor();
    
    getch();
    return;

};

//aplica efeito de desfoque na intensidade escolhida pelo usuario
void Camada :: profundidadeCampo(){

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

        if(opcao != 7){

            if(arquivo_copia != "")
                remove(arquivo_copia.c_str());
            
            clear();
            curs_set(0);
            noecho();

            setCor(5);
            mvprintw(0, 0, "!! Aguarde ate que a operaco saja concluida");
            resetCor();
            
            PyObject  *sys = PyImport_ImportModule("sys");
            PyObject  *path = PyObject_GetAttrString(sys, "path");
            PyList_Append(path, PyUnicode_DecodeFSDefault(DIR_COMPILACAO));
            
            PyObject  *modulo = PyImport_ImportModule((char *)"funcoes_classeCamada");
            if (modulo != nullptr) {

                PyObject  *funcao = PyObject_GetAttrString(modulo, "efeitoDesfoque");
                if (funcao != nullptr && PyCallable_Check(funcao)) {
                    
                    PyObject  *argumentos = PyTuple_Pack(2, 
                    PyUnicode_DecodeFSDefault(imagem.c_str()), PyLong_FromLong((opcao + 1)*2));

                    PyObject  *retorno = PyObject_CallObject(funcao, argumentos);
                    

                    if(retorno != NULL){
                        arquivo_copia = string(PyUnicode_AsUTF8(retorno));
                    }

                    Py_DECREF(retorno);
                    Py_DECREF(argumentos);
                }
                Py_DECREF(funcao);                
            }

            Py_DECREF(sys);
            Py_DECREF(path);
            Py_DECREF(modulo);

            if(arquivo_copia != "")
                exibirImagem(arquivo_copia);

            continue;
        }

        if(arquivo_copia != ""){
            copiarConteudo(&imagem, arquivo_copia);
            remove(arquivo_copia.c_str());
            return;
        }

        clear();
        setCor(4);
        mvprintw(0, 0, "Pressione enter para continuar");
        setCor(1);
        mvprintw(2, 0, "Arquivo nao salvo");
        resetCor();

        getch();
        return;
    };

    

};

//altera brilho, saturacao e contraste
void Camada :: menuLuzCor(){
    curs_set(0);
    
    int opcao_1;

    double intensidade = 1.0;
    
    char tecla;

    string  arquivo_copia = "",
            arquivo_base = imagem;

    vector<string> efeitos = {"Contraste", "Brilho", "Saturacao"};

    vector<string> opcoes_1 = {   "Voltar e cancelar operacao",
                                "Alterar niveis de contraste",
                                "Alterar niveis de brilho",
                                "Alterar niveis de saturacao",
                                "Salvar alteracoes e sair"};
    vector<string> opcoes_2;

    vector<string> opcoes_3 = {"voltar e descartar alteracoes", "Salvar e voltar para o menu de edicoes gerais"};

    

    while(1){
        
        opcao_1 = exibirOpcoes(opcoes_1);
        if(opcao_1 == -1)
            return;
        
        if(opcao_1 != 3){
        /*
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
        */

            while(1){
                clear();
                refresh();

                setCor(4);
                mvprintw(0, 1, "! Use as teclas W, S e 'enter' para alternar");
                mvprintw(1, 1, "entre os niveis de %s e selecionar - las", efeitos[opcao_1].c_str());
                resetCor();

                setCor(1);
                mvprintw(3, 0, "Nivel padrao de %s: 50%%", efeitos[opcao_1].c_str());
                mvprintw(4, 0, "Ajustar %s para %.0f%%", efeitos[opcao_1].c_str(), (intensidade * 50.0));

                tecla = getch();

                if(tecla == 'S' || tecla == 's' || tecla == KEY_DOWN){
                    if(intensidade == 0){
                        intensidade = 2;
                        continue;
                    }
                    intensidade = intensidade - 0.1;
                    continue;
                }

                if(tecla == 'W' || tecla == 'w' || tecla == KEY_DOWN){
                    if(intensidade == 2){
                        intensidade = 0;
                        continue;
                    }
                    intensidade = intensidade + 0.1;
                    continue;
                }

                if(tecla == 10 || tecla == 13){
                    break;
                }
            }  

            clear();
            setCor(5);

            mvprintw(0,0, "instensidade: %f", intensidade);

            if(arquivo_copia != "")
                remove(arquivo_copia.c_str());

            clear();
            curs_set(0);
            noecho();

            setCor(5);
            mvprintw(0, 0, "!! Aguarde ate que a operaco saja concluida");
            resetCor();
            
            PyObject  *sys = PyImport_ImportModule("sys");
            PyObject  *path = PyObject_GetAttrString(sys, "path");
            PyList_Append(path, PyUnicode_DecodeFSDefault(DIR_COMPILACAO));
            
            PyObject  *modulo = PyImport_ImportModule("funcoes_classeCamada");
            
            if (modulo != nullptr) {

                PyObject  *funcao = PyObject_GetAttrString(modulo, ("alterar" + efeitos[opcao_1]).c_str());
                if (funcao != nullptr && PyCallable_Check(funcao)) {
                    
                    PyObject *argumentos = PyTuple_Pack(2, PyUnicode_DecodeFSDefault(arquivo_base.c_str()),
                                   PyFloat_FromDouble(intensidade));

                    PyObject  *retorno = PyObject_CallObject(funcao, argumentos);

                    if((retorno != NULL) && (PyUnicode_Check(retorno))){
                        arquivo_copia = string(PyUnicode_AsUTF8(retorno));
                        arquivo_base = arquivo_copia; 
                    }

                    Py_DECREF(retorno);
                    Py_DECREF(argumentos);
                } 
                Py_DECREF(funcao);        
            }
            
            Py_DECREF(sys);
            Py_DECREF(path);
            Py_DECREF(modulo);
            
            //finaliza a API  
            
            if(arquivo_copia != "")
                exibirImagem(arquivo_base);
        }

        opcao_1 = exibirOpcoes(opcoes_3);
        if(opcao_1 == 0)
            if(arquivo_copia != ""){
                copiarConteudo(&imagem, arquivo_base);
                remove(arquivo_copia.c_str());
                return;
            }

        clear();
        setCor(4);
        mvprintw(0, 0, "Pressione enter para continuar");
        setCor(1);
        mvprintw(2, 0, "Arquivo nao salvo");
        resetCor();

        getch();        
        return;

    }
};

//copia o conteudo de arquivo 1 para o arquivo 2
void Camada :: copiarConteudo(string *receptor, string doador){
    
    PyObject  *sys,
              *path,
              *modulo,
              *funcao,
              *argumentos,
              *retorno;
    
    
    sys = PyImport_ImportModule("sys");
    path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_DecodeFSDefault(DIR_COMPILACAO));
    
    modulo = PyImport_ImportModule((char *)"funcoes_funcoesGlobais");
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



