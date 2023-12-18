#funcoes que os metodos da classe Edicao utilizam

from PIL import Image
import os


def fazerCopiaNome(caminho_arquivo):
    diretorio, nome_arquivo = os.path.split(caminho_arquivo)

    novo_caminho_arquivo = os.path.join(diretorio, ("copia_" + nome_arquivo))

    return novo_caminho_arquivo

def sobrepor(imagemFundo, imagemFrente, transparencia = 1.0):

    arquivoCopia = fazerCopiaNome(imagemFundo)

    camada_1 = Image.open(imagemFundo)
    camada_2 = Image.open(imagemFrente)
    
    Image.blend(camada_1, camada_2, 0.7).save(arquivoCopia)

    return arquivoCopia


