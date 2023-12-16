
#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>
#include <stack>
#include <limits>
#include <cmath>


#include "funcoesGlobais.h"
#include "classeGrafoSimetrico.h"
#include "tipos.h"

GrafoSimetrico :: ~GrafoSimetrico(){
    for (short i = 0; i < listaArestas.size(); i++)
        delete listaArestas[i];
    for(short i = 0; i < listaVertices.size(); i++)
        delete listaVertices[i];

    delete matrizAdjacencia;
}

GrafoSimetrico :: GrafoSimetrico(bool * verificador, string nomeArquivo){
    

    string  linha_,
            linha,
            elemento;

    vector <string> elementos;

    ExibirMensagem("Arquivo lido:", nomeArquivo);
    ExibirMensagem("Conteudo:");
    ifstream arquivo (nomeArquivo);
    
    if(!arquivo.is_open())
        ExibirMensagemErro(arquivoNEncontrado);

    //o proximo escopo instancia os objetos vertices e arestas

    else{
        while(getline(arquivo, linha_))
        {
            ExibirMensagem(linha_);
            stringstream linha(linha_);
            
            while(getline(linha, elemento, ',')){
                elementos.push_back(elemento);
            }
            
            Vertice* vertice_A = new Vertice(elementos[0]);
            Vertice* vertice_B = new Vertice(elementos[1]);
            Aresta* aresta = new Aresta(stof(elementos[2]), vertice_A, vertice_B);
            
            (*vertice_A).setArestas(aresta);
            (*vertice_B).setArestas(aresta);

            inserirVertice(vertice_A);
            inserirVertice(vertice_B);
            inserirAresta(aresta);

            elementos.clear();

        };
        (*verificador) = true;
    };

    matrizAdjacencia = new float*[listaVertices.size()];
    for (short indice = 0; indice < listaVertices.size(); indice++) {
        matrizAdjacencia[indice] = new float[listaVertices.size()];       
    }
    
    setMatrizAdjacencia();

};

void GrafoSimetrico :: inserirVertice(Vertice* novoVertice){
    bool verificacao = true;
    for(short indice = 0; indice < listaVertices.size(); indice++){
        if((*listaVertices[indice]).getNome() == (*novoVertice).getNome()){
            verificacao = false;
            break;
        }
    }
    if(verificacao)
        listaVertices.push_back(novoVertice);
};

void GrafoSimetrico :: inserirAresta(Aresta* novaAresta){
    bool verificacao = true;
    for(short indice = 0; indice < listaArestas.size(); indice++){
        if(((((*((*listaArestas[indice]).getVertice_A())).getNome() == (*(*novaAresta).getVertice_A()).getNome()) &&
            (*((*listaArestas[indice]).getVertice_B())).getNome() == (*(*novaAresta).getVertice_B()).getNome())) ||
           (((*((*listaArestas[indice]).getVertice_A())).getNome() == (*(*novaAresta).getVertice_B()).getNome() &&
            (*(*listaArestas[indice]).getVertice_B()).getNome() == (*(*novaAresta).getVertice_A()).getNome()))){
            
            ExibirMensagem();
            ExibirMensagem("Em um grafo simetrico nao eh possivel definir duas arestas diferentes com os mesmos vertices.");
            ExibirMensagem("Somente a primeira aresta foi considerada.");
            verificacao = false;
            break;
        }
    }
    if(verificacao == true)
        listaArestas.push_back(novaAresta);
};
 
void GrafoSimetrico :: exibirEnlaces(){
    ExibirMensagem("Os enlaces estao listados abaixo:");
    for(short indice = 0; indice<listaArestas.size(); indice++){
        string vertice_A = (*(*listaArestas[indice]).getVertice_A()).getNome();
        string vertice_B = (*(*listaArestas[indice]).getVertice_B()).getNome();
         ExibirMensagem((indice+1)," - enlace entre o vertice", vertice_A, "e o vertice", vertice_B);
    };
};

void GrafoSimetrico :: setMatrizAdjacencia(){
    
    float peso = 0;    
    for(short indice_linha = 0; indice_linha < listaVertices.size(); indice_linha ++){
        for(short indice_coluna = 0; indice_coluna < listaVertices.size(); indice_coluna++){
            for(short indice = 0; indice < listaArestas.size(); indice++)
                if( (((*listaVertices[indice_linha]).getNome() == (*(*listaArestas[indice]).getVertice_A()).getNome()) &&
                    ((*listaVertices[indice_linha]).getNome() == (*(*listaArestas[indice]).getVertice_B()).getNome())) ||
                    (((*listaVertices[indice_coluna]).getNome() == (*(*listaArestas[indice]).getVertice_A()).getNome()) &&
                    ((*listaVertices[indice_coluna]).getNome() == (*(*listaArestas[indice]).getVertice_B()).getNome())) ||
                    (((*listaVertices[indice_coluna]).getNome() == (*(*listaArestas[indice]).getVertice_A()).getNome()) &&
                    ((*listaVertices[indice_linha]).getNome() == (*(*listaArestas[indice]).getVertice_B()).getNome())) ||
                    (((*listaVertices[indice_linha]).getNome() == (*(*listaArestas[indice]).getVertice_A()).getNome()) &&
                    ((*listaVertices[indice_coluna]).getNome() == (*(*listaArestas[indice]).getVertice_B()).getNome()))){
                    peso = (*listaArestas[indice]).getPeso();
                };
            matrizAdjacencia[indice_linha][indice_coluna] = peso;
            peso = 0.0;
        };
    };


};

void GrafoSimetrico :: exibirMatrizAdjacencias(){

    ExibirMensagem("Matriz de adjacencias abaixo:");
    ExibirMensagem();
    cout << setw (3) << " ";
    for(int indice = 0; indice < listaVertices.size(); indice++)
        cout << setw (5) << ((*listaVertices[indice]).getNome());

    ExibirMensagem();

    for(int vertices_linha = 0; vertices_linha < listaVertices.size(); vertices_linha++){
        cout << ((*listaVertices[vertices_linha]).getNome()) << " ";
        for(int vertices_coluna = 0; vertices_coluna < listaVertices.size(); vertices_coluna++){
            cout << setw (5) <<matrizAdjacencia[vertices_coluna][vertices_linha];
        };
        ExibirMensagem();
        ExibirMensagem();

    };
};

tipoErros GrafoSimetrico :: exibirCaminhoMenorCusto(string vertice_A, string vertice_B, float* menorCusto){
    
    //verificacao

    int origem,
        destino;

    bool verificacao = false,
         verificacao_ = false;

    for(int indice = 0; indice < listaVertices.size(); indice++){
        if((*listaVertices[indice]).getNome() == vertice_A){
            origem = indice;
            verificacao = true;    
        };
        if((*listaVertices[indice]).getNome() == vertice_B){
            destino = indice;
            verificacao_ = true;
        };

    };

    if (!(verificacao && verificacao_)){
        
        ExibirMensagemErro(verticeNExiste);
        return verticeNExiste;
    };

    //adequando a estrutura que armazena os vertices e arestas pra uma implementacao
    // simplificada do algoritmo

    list<pair<float, int>>  lista_adjacencias [listaVertices.size()];

    //(debug)ExibirMensagem("__________________________________________________");

    for(short indice = 0; indice < listaVertices.size(); indice++){
        //(debug)ExibirMensagem((*listaVertices[indice]).getNome());
        for(short indice_ = 0; indice_ < listaArestas.size(); indice_++)
            {

                if(((*((*(listaArestas[indice_])).getVertice_A())).getNome() == (*listaVertices[indice]).getNome()) ||
                    ((*((*(listaArestas[indice_])).getVertice_B())).getNome() == (*listaVertices[indice]).getNome())){
                    int vertice;
                    string vertice_str = (*((*listaArestas[indice_]).getVertice_B())).getNome();
                    for(short indice__ = 0; indice__ < listaVertices.size(); indice__++)
                    {
                        if((*(listaVertices[indice__])).getNome() == vertice_str)
                            vertice = indice__;
                    };  
                    //(debug)ExibirMensagem("       ", vertice_str , ":",(*(listaArestas[indice_])).getPeso() );
                    lista_adjacencias[indice].push_back(make_pair((*(listaArestas[indice_])).getPeso(), vertice));
                }
            };
    };

    //(debug)ExibirMensagem("__________________________________________________");

    //implementando o algoritmo de Dijkstra

    //guarda os indices dos caminhos percorridos
    vector <int> verticesCaminho (listaVertices.size(), -1);

    float distancias [listaVertices.size()];
    //array de distancias dos vertices em relacao ao vertice de origem
    
    bool visitados [listaVertices.size()];
    //array de vertices visitados

    priority_queue <pair<float, int>, 
                    vector<pair<float, int>>, 
                    greater<pair<float, int >>> fila;
    //fila de prioridade de pares distancia-vertice

    for(short indice = 0; indice < listaVertices.size(); indice++){
        distancias[indice] = INFINITY;
        visitados[indice] = false;
    };

    distancias[origem] = 0;
    
    verticesCaminho.push_back(origem);

    fila.push(make_pair(distancias[origem], origem));

    while(!fila.empty())
    {
        pair <float, int> p = fila.top();
        int vertice_atual = p.second;
        fila.pop();

        if(visitados[vertice_atual] == false)
        {
            visitados[vertice_atual] = true;

            //iterando os enalces que o proximo vertice possui, percorre os vertices adjacentes.
            list<pair<float, int>> :: iterator iteravel;
            for(iteravel = lista_adjacencias[vertice_atual].begin(); iteravel != lista_adjacencias[vertice_atual].end(); iteravel++){     

                int vertice_adjacente = iteravel ->second;
                float custoAresta = iteravel ->first;

                //relaxamento
                if(distancias[vertice_adjacente] > (distancias[vertice_atual] + custoAresta)){

                    distancias[vertice_adjacente] = distancias[vertice_atual] + custoAresta;
                    fila.push(make_pair(distancias[vertice_adjacente], vertice_adjacente));
                    
                    verticesCaminho[vertice_adjacente] = vertice_atual;
                };
            };
        };
    };

    if(menorCusto != NULL){
        *menorCusto = distancias[destino];
        return sucesso;
    }

    if(verticesCaminho[destino] == -1){
        ExibirMensagem("O caminho de", vertice_A, "ate", vertice_B, "nao existe!");
        return sucesso;
    }

    ExibirMensagem("O caminho de", vertice_A, "ate", vertice_B, "existe e tem um distancia (minima) de:", distancias[destino]);
    ExibirMensagem("Caminho da distancia minima:");
    
    stack<int> caminho;
    
    int vertice_anterior = destino;
    
    while (vertice_anterior != -1){
        caminho.push(vertice_anterior);
        vertice_anterior = verticesCaminho[vertice_anterior];
    }

    vector<string> verticesCaminho_str;

    while(!caminho.empty())
        {
            verticesCaminho_str.push_back((*(listaVertices[caminho.top()])).getNome());
            caminho.pop();
        }

    for(short indice=0; indice < verticesCaminho_str.size() -1; indice++)
        ExibirMensagem(verticesCaminho_str[indice], "-", verticesCaminho_str[indice+1]);

    return sucesso;
};

void GrafoSimetrico :: exibirDensidadeGrafo(){
    //A densidade de um grfo nao direcionado é dada pela razao da quantidade de arestas pela quantidade de arestas possiveis
    float densidade = listaArestas.size()*1.0 / (listaVertices.size() * (listaVertices.size() - 1)*1.0);
    ExibirMensagem("A densidade deste grafo é:", densidade);
};

void GrafoSimetrico :: exibirVerticeMaiorCentralidade(){
    
    vector<float> centralidade(listaVertices.size());
    float caminhoMinimo;

    string vertice_A,
           vertice_B;

    for(short indice = 0; indice < listaVertices.size(); indice++){
        for(short indice_ = 0; indice_ < listaArestas.size(); indice_++){
            if((*(listaVertices[indice])).getNome() == (*((*(listaArestas[indice_])).getVertice_A())).getNome()){
                vertice_A = (*(listaVertices[indice])).getNome();
                vertice_B = (*((*(listaArestas[indice_])).getVertice_B())).getNome();      
            }

            if((*(listaVertices[indice])).getNome() == (*((*(listaArestas[indice_])).getVertice_B())).getNome()){
                vertice_A = (*((*(listaArestas[indice_])).getVertice_A())).getNome();
                vertice_B = (*(listaVertices[indice])).getNome();
      
            }
            caminhoMinimo = 0;
            exibirCaminhoMenorCusto(vertice_A, vertice_B, &caminhoMinimo);
            centralidade[indice] = centralidade[indice] + caminhoMinimo;
        }
    }

    int indice_menorValor = 0;
    for(short indice = 0; indice < listaVertices.size(); indice++){
        if(centralidade[indice] < centralidade[indice_menorValor])
            indice_menorValor = indice;
    }

    ExibirMensagem("Quem possui a maior centralidade de proximidade é:", (*(listaVertices[indice_menorValor])).getNome());
    ExibirMensagem("Com um valor numerico aproximado de:", 1/centralidade[indice_menorValor]);

};

