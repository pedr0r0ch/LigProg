#funcoes que as funcoes globais utilizam
from pathlib import Path 
from PIL import Image

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
    
    arquivoCopia = Path(arquivoOriginal).stem + ".png"

    img = Image.open(arquivoOriginal)
    img.save(arquivoCopia, "PNG")

    return arquivoCopia
