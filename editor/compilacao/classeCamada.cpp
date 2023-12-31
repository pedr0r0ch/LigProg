#include "/usr/include/python3.10/Python.h"
#include "funcoesGlobais.h"
#include "classeCamada.h"

using namespace std;

//----CONSTRUTOR-E-DESTRUTOR---------------
Camada :: Camada(string nomeArquivo, string descricao){
    this->transparencia = 1.0;
    this->imagem = nomeArquivo;
    this->descricao = descricao;
};

Camada :: ~Camada(){
    remove(imagem.c_str());
};

//----IMPLEMENTACAO-DE-METODOS-PUBLICOS----

//retorna a trasparencia da camada
double Camada :: getTransparencia(){
   return (double)this->transparencia; 
}; 

//metodo para definir a transparencia da camada
void Camada :: setTransparencia(){
    
    curs_set(0);
    char tecla;
    double  transparencia;

    while(1){
        clear();
        refresh();

        setCor(4);
        mvprintw(0, 1, "! Use as teclas W, S e 'enter' para almentar");
        mvprintw(1, 1, "ou diminuir o efeito de profundidade de campo");
        resetCor();

        setCor(1);
        mvprintw(3, 0, "O nivel padrao para a trasparencia/opacidade eh: 100%%");
        mvprintw(4, 0, "Ajustar efeito de profundidade de campo para %.0f%%", (transparencia * 100.0));

        tecla = getch();

        if(tecla == 'S' || tecla == 's' || tecla == KEY_DOWN){
            if((transparencia - 0.1) < 0){
                transparencia = 1;
                continue;
            }else{
                transparencia = transparencia - 0.1;
                continue;
            }
        }

        if(tecla == 'W' || tecla == 'w' || tecla == KEY_UP){
            if((transparencia + 0.1) > 1.0){
                transparencia = 0;
                continue;
            }else{
                transparencia = transparencia + 0.1;
                continue;
            }
        }

        if(tecla == 10 || tecla == 13){
            break;
        }
    }

    this->transparencia = transparencia;
};

//metodo com opcoes gerais como remover fundo, aplicar efeito de desfoque etc.
void Camada :: edicoesGerais(){
    curs_set(0);
    
    int opcao;

    vector<string> menu = {
        "Voltar e cancelar operacao",
        /*"Definir transparencia da camada",*/
        "Recortar objeto e remover fundo",
        "Aplicar efeito de profundidade de campo",
        "Abrir menu de opcoes de cor e luz",
        "Exibir a camada selecionada"

    };
    while(1){
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
            
            case 3:
                exibirCamada();
                break;
        }
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
        
    PyObject  *sys = PyImport_ImportModule("sys");
    PyObject  *path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_DecodeFSDefault(DIR_COMPILACAO));
    
    PyObject  *modulo = PyImport_ImportModule((char *)"camada");
    if (modulo != nullptr) {

        PyObject  *funcao = PyObject_GetAttrString(modulo, "manterObjeto");
        if (funcao != nullptr && PyCallable_Check(funcao)) {

            PyObject  *argumento = Py_BuildValue("s", imagem.c_str());

            mensagemDeAviso("Aguarde ate ate que a operacao seja concluida");
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

    if(arquivo_copia != "")
        remove(arquivo_copia.c_str());

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

    clear();
    curs_set(0);
    noecho();

    int opcao = -1;
    char tecla;
    double intensidade = 0;

    string arquivo_copia = "";
    vector<string> opcoes = {"Voltar e cancelar operacao",
                             "Salvar e sair"};
    while(1){
            clear();
            refresh();

            setCor(4);
            mvprintw(0, 1, "! Use as teclas W, S e 'enter' para almentar");
            mvprintw(1, 1, "ou diminuir o efeito de profundidade de campo");
            resetCor();

            setCor(1);
            mvprintw(3, 0, "O nivel padrao do efeito de profundidade de campo eh: 0%%");
            mvprintw(4, 0, "Ajustar efeito de profundidade de campo para %.0f%%", (intensidade * 10.0));

            tecla = getch();

            if(tecla == 'S' || tecla == 's' || tecla == KEY_DOWN){
                if(intensidade == (double)0.0){
                    intensidade = (double)10;
                    continue;
                }else{
                    intensidade = intensidade - 1;
                    continue;
                }
            }

            if(tecla == 'W' || tecla == 'w' || tecla == KEY_UP){
                if(intensidade == (double)10){
                    intensidade = (double)0.0;
                    continue;
                }else{
                    intensidade = intensidade + 1;
                    continue;
                }
            }

            if(tecla == 10 || tecla == 13){
                break;
            }
    }

    if(arquivo_copia != "")
        remove(arquivo_copia.c_str());
    
    PyObject  *sys = PyImport_ImportModule("sys");
    PyObject  *path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_DecodeFSDefault(DIR_COMPILACAO));
    
    PyObject  *modulo = PyImport_ImportModule((char *)"camada");
    if (modulo != nullptr) {

        PyObject  *funcao = PyObject_GetAttrString(modulo, "efeitoDesfoque");
        if (funcao != nullptr && PyCallable_Check(funcao)) {
            
            PyObject  *argumentos = PyTuple_Pack(2, 
            PyUnicode_DecodeFSDefault(imagem.c_str()), PyLong_FromLong(intensidade));

            mensagemDeAviso("Aguarde ate ate que a operacao seja concluida");
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

    opcao = exibirOpcoes(opcoes); 
    
    if(opcao == -1)
        return;

    if(arquivo_copia != ""){
        copiarConteudo(&imagem, arquivo_copia);
        remove(arquivo_copia.c_str());
        return;
    }

    
    if(arquivo_copia != "")
        remove(arquivo_copia.c_str());

    clear();
    setCor(4);
    mvprintw(0, 0, "Pressione enter para continuar");
    setCor(1);
    mvprintw(2, 0, "Arquivo nao salvo");
    resetCor();

    getch();
    return;
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

    vector<string> opcoes_3 = {"voltar e descartar alteracoes", "Salvar e voltar para o menu"};

    

    while(1){
        
        opcao_1 = exibirOpcoes(opcoes_1);
        if(opcao_1 == -1)
            return;
        
        if(opcao_1 != 3){

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
                    if((intensidade - 0.1) < 0.0){
                        intensidade = 2.0;
                        continue;
                    }else{
                        intensidade = intensidade - 0.1;
                        continue;
                    }
                }

                if(tecla == 'W' || tecla == 'w' || tecla == KEY_UP){
                    if((intensidade + 0.1) > 2.0){
                        intensidade = 0.0;
                        continue;
                    }else{
                        intensidade = intensidade + 0.1;
                        continue;
                    }
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

            
            PyObject  *sys = PyImport_ImportModule("sys");
            PyObject  *path = PyObject_GetAttrString(sys, "path");
            PyList_Append(path, PyUnicode_DecodeFSDefault(DIR_COMPILACAO));
            
            PyObject  *modulo = PyImport_ImportModule("camada");
            
            if (modulo != nullptr) {

                PyObject  *funcao = PyObject_GetAttrString(modulo, ("alterar" + efeitos[opcao_1]).c_str());
                if (funcao != nullptr && PyCallable_Check(funcao)) {
                    
                    PyObject *argumentos = PyTuple_Pack(2, PyUnicode_DecodeFSDefault(arquivo_base.c_str()),
                                   PyFloat_FromDouble(intensidade));

                    mensagemDeAviso("Aguarde ate ate que a operacao seja concluida");
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
                remove(arquivo_base.c_str());
                remove(arquivo_copia.c_str());
                return;
            }

        if(arquivo_copia != "")
            remove(arquivo_copia.c_str());

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




