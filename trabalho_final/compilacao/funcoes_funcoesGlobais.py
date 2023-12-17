#funcoes que as funcoes globais utilizam
import os
from PIL import Image

def exibirArquivoImagem(nomeArquivo):
    try:
        img = Image.open(nomeArquivo)
        img.show()        
        return 1

    except Exception as e:
        return 0
    
def converterArquivo(arquivo):
    if arquivo.lower().endswith(".png"):
        return arquivo

    imagem = Image.open(arquivo)
    novo_arquivo = os.path.splitext(arquivo)[0] + ".png"
    imagem.save(novo_arquivo, "PNG")
    return novo_arquivo

def copiarArquivoImagem(receptor, doador):

    img = Image.open(doador)

    img.save(receptor, "PNG")

    return receptor
