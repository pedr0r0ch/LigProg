#funcoes que as funcoes globais utilizam
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
    img.save(receptor)