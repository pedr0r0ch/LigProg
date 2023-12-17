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
    
def copiarArquivoImagem(receptor, doador):

    nome_base, extensao_atual = os.path.splitext(os.path.basename(receptor))
    
    novo_caminho = os.path.join(os.path.dirname(receptor), (nome_base + ".png"))

    img = Image.open(doador)

    img.save(novo_caminho, "PNG")

    return novo_caminho