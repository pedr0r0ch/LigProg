#funcoes que as funcoes globais utilizam
import os
from PIL import Image

def fazerCopiaNome(caminho_arquivo, prefixo = "copia_"):
    nome_base, extensao_atual = os.path.splitext(os.path.basename(caminho_arquivo))

    novo_nome = prefixo + nome_base + ".png"

    novo_caminho = os.path.join(os.path.dirname(caminho_arquivo), novo_nome)

    return novo_caminho

def exibirArquivoImagem(nomeArquivo):
    try:
        img = Image.open(nomeArquivo)
        img.show()        
        return 1

    except Exception as e:
        return 0

def copiarArquivoImagem(receptor, doador):

    img = Image.open(doador)

    img.save(receptor, "PNG")

    return receptor

def converterArquivo(arquivoOriginal):
    
    arquivoCopia = fazerCopiaNome(arquivoOriginal, "editor_")

    img = Image.open(arquivoOriginal)
    img.save(arquivoCopia, "PNG")
    
    os.remove(arquivoOriginal)

    return arquivoCopia
