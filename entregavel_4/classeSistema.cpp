#include <ncurses.h>
#include <string>

#include "classeSistema.h"
#include "classeAtleta.h"
#include "classeAtletaDerivacoes.h"

Sistema :: Sistema (string arquivoPadrao){
    
    this->arquivoPadrao = arquivoPadrao;
    string  esporte,
            nome,
            idade_str;


    string linha;
    ifstream arquivo(arquivoPadrao);

    if(arquivo.is_open()){
        while(getline(arquivo, linha)){
            stringstream streamLinha(linha);

            getline(streamLinha, nome, ',');
            getline(streamLinha, idade_str, ',');
            getline(streamLinha, esporte, ',');


            if(esporte == "Futebol")
                arvore = arvore + (new AtletaFutebol(nome, stoi(idade_str)));
            if(esporte == "Surf")
                arvore = arvore + (new AtletaSurf(nome, stoi(idade_str)));
            if(esporte == "Ginastica Olimpica")
                 arvore = arvore + (new AtletaGinastica(nome, stoi(idade_str)));
            
        }
    }
    
    arquivo.close();

};

Sistema :: ~Sistema(){
    vector<string> atributosObjetos;
    arvore.getAtributosObjetos(&atributosObjetos);
    
    ofstream arquivo(arquivoPadrao, ios::trunc);

    if (arquivo.is_open()) {
        for (const auto& linha : atributosObjetos) {
            arquivo << linha << std::endl;
        };
    }
    
    arquivo.close();

    endwin();
};

int Sistema :: insere(){
    

    initscr(); //inicializa o modulo ncurses
    start_color(); //habilita cores no terminal
    clear();
    echo();

    curs_set(1);

    if(has_colors()){
        //inicializa pares de cor [cor fonte, cor fundo]

        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_WHITE);  
        init_pair(4, COLOR_YELLOW, COLOR_BLACK); 
    } 

    string esporte;
    string nome;
    int idade;
    
    char mensagem[100];

    if(has_colors())
        attron(COLOR_PAIR(4));

    mvprintw(0, 1, "Por vafor preecha os dados do Atleta.");
        
    if(has_colors())
        attroff(COLOR_PAIR(4));

    Atleta* encontrado;
    do{
        if(has_colors())
            attron(COLOR_PAIR(1));

        mvprintw(3, 1, "Nome: ");
        getstr(mensagem);
        nome = string(mensagem);

        encontrado = arvore(nome);

        if(encontrado){
            if(has_colors())
                attron(COLOR_PAIR(2));

            mvprintw(10, 1, "! Nao eh permitido a inclusao de atletas com nomes iguais no sistema.");
            mvprintw(11, 1, "Se preferir cancelar a operacao, digite a palavra-chave 'sair'");

            if(has_colors())
                attron(COLOR_PAIR(4));
            mvprintw(1, 1, "! Pressione enter para prosseguir.");
            if(has_colors())
                attroff(COLOR_PAIR(4));

            getch();

            move(10, 0);//limpando os avisos
            clrtoeol();
            move(11, 0);
            clrtoeol();
            move(1, 0);
            clrtoeol();



            if(has_colors())
                attroff(COLOR_PAIR(2));
        }
        
    }while((encontrado != nullptr) && nome != "sair");

    if(nome == "sair")
        return -1;
    
    do{
        mvprintw(4, 1, "Idade: ");
        getstr(mensagem);

        try {
            idade = stoi(mensagem);

        } catch (const invalid_argument& e) {
            
            if(has_colors())
                attron(COLOR_PAIR(2));
            mvprintw(10, 1, "! Erro: O numero submetido eh invalido.");
            if(has_colors())
                attroff(COLOR_PAIR(2));

            if(has_colors())
                attron(COLOR_PAIR(4));
            mvprintw(1, 1, "! Pressione enter para prosseguir.");
            if(has_colors())
                attroff(COLOR_PAIR(4));
            
            getch();

            move(10, 0);
            clrtoeol();
            move(1, 0);
            clrtoeol();

            
            continue;
        }
       
        break;
    }while(1);
    

    do{
        mvprintw(5, 1, "Esporte que o atleta pratica: ");
        getstr(mensagem);
        esporte = string(mensagem);

        if(esporte != "Futebol" && esporte != "Surf" && esporte != "Ginastica Olimpica" && esporte != "sair"){
            if(has_colors())
                attron(COLOR_PAIR(2));
    
            mvprintw(10, 1, "! Erro: Esporte nao reconhecido.");
            mvprintw(11, 1, "! Esportes reconhecidos pelo sistema: Futebol, Surf e Ginastica Olimpica");
            mvprintw(12, 1, "Se preferir cancelar a operacao, digite a palavra-chave 'sair'");

            if(has_colors())
                attron(COLOR_PAIR(4));
            mvprintw(1, 1, "! Pressione enter para prosseguir.");
            if(has_colors())
                attroff(COLOR_PAIR(4));

            getch();

            move(10, 0);//limpando os avisos
            clrtoeol();
            move(11, 0);
            clrtoeol();
            move(12, 0);
            clrtoeol();
            move(1, 0);
            clrtoeol();

            if(has_colors())
                attroff(COLOR_PAIR(2));
            
            continue;
        };

        break;
    }while(esporte != "Futebol" && esporte != "Surf" && esporte != "Ginastica Olimpica" && esporte != "sair");

    if(esporte == "sair")
        return -1;

    if(has_colors())
        attron(COLOR_PAIR(4));

    mvprintw(1, 1, "! Pressione enter para prosseguir.");
        
    if(has_colors())
        attroff(COLOR_PAIR(4));
    
    if(esporte == "Futebol"){
        AtletaFutebol* atleta;
        atleta = new AtletaFutebol(nome, idade);
        arvore = arvore + atleta;
    }
    
    if(esporte == "Surf"){
        AtletaSurf* atleta;
        atleta = new AtletaSurf(nome, idade);
        arvore = arvore + atleta;
    }
    
    if(esporte == "Ginastica Olimpica"){
        AtletaGinastica* atleta;
        atleta = new AtletaGinastica(nome, idade);
        arvore = arvore + atleta;
    }


    refresh();
    getch();

    return 1;
    
};

Atleta* Sistema::busca() {
    
    initscr();
    start_color();
    clear();
    echo();
    curs_set(1);

    if (has_colors()) {
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);
        init_pair(3, COLOR_GREEN, COLOR_BLACK);
        init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    }

    string nomeBusca;
    char mensagem[100];

    if(has_colors())
        attron(COLOR_PAIR(4));
    
    mvprintw(1, 1, "! Utilize enter para avancar quando nescessario");

    if(has_colors())
        attroff(COLOR_PAIR(4));

    if (has_colors()) {
        attron(COLOR_PAIR(1));
    }

    mvprintw(3, 1, "Digite o nome do atleta que deseja buscar: ");

    getstr(mensagem);
    nomeBusca = string(mensagem);

    if (has_colors()) {
        attroff(COLOR_PAIR(1));
    }
    
    refresh();

    Atleta* encontrado = arvore(nomeBusca);

    if (encontrado) {
        if(has_colors())
            attron(COLOR_PAIR(1));
        mvprintw(5, 1, "Atleta encontrado:");
        
        if(has_colors())
            attron(COLOR_PAIR(3));
        mvprintw(5, 20, (encontrado->descricao().c_str()));
        if(has_colors())
            attroff(COLOR_PAIR(3));

    } else {
        if (has_colors()) {
            attron(COLOR_PAIR(2));
        }

        mvprintw(5, 1, "Atleta não encontrado.");

        if (has_colors()) {
            attroff(COLOR_PAIR(2));
        }
    }

    refresh();
    getch();
    
    return encontrado;
}

void Sistema :: imprime(){
    cout << arvore;
};

ostream& operator<<(ostream& os, Arvore<Atleta*> arvore) {
        vector<string> descricoes;
        arvore.percorrerArvore(arvore.raiz, &descricoes);

        initscr();
        start_color();
        clear();
        echo();
        curs_set(0);

        if (has_colors()) {
            init_pair(1, COLOR_WHITE, COLOR_BLACK);
            init_pair(2, COLOR_RED, COLOR_BLACK);
            init_pair(3, COLOR_GREEN, COLOR_BLACK);
            init_pair(4, COLOR_YELLOW, COLOR_BLACK);
        }

        string tamanho = to_string(descricoes.size());

        if(has_colors())
            attron(COLOR_PAIR(4));
        mvprintw(1, 1, "Abaixo estao todos os %s atletas encontados no sistema", tamanho.c_str());
        mvprintw(2, 1, "! Pressione enter para prosseguir.");
        if(has_colors())
            attroff(COLOR_PAIR(4));

        
        for(unsigned int n = 0; n < descricoes.size(); n++){
            
            if(has_colors())
                attron(COLOR_PAIR(1));
            mvprintw(3+n, 1, "-");
            if(has_colors())
                attroff(COLOR_PAIR(1));
                
            if(has_colors())
                attron(COLOR_PAIR(3));
            mvprintw(3+n, 3, descricoes[n].c_str());
            if(has_colors())
                attron(COLOR_PAIR(3));
        }
        

        getch();

        return os;
    }
