#funcoes que os metodos da classe Camada utilizam   

import os

from rembg import remove
from PIL import Image, ImageFilter



def manterObjeto(imagemOriginal):

    imagemCopia = fazerCopiaNome(imagemOriginal)

    imagem = Image.open(imagemOriginal) 
    
    objeto = remove(imagem) 
    
    objeto.save(imagemCopia) 

    return imagemCopia

def efeitoDesfoque(imagemOriginal, intensidade):

    imagemCopia = fazerCopiaNome(imagemOriginal)
    imagem = Image.open(imagemOriginal)
    imagem = imagem.filter(ImageFilter.GaussianBlur(intensidade))

    imagem.save(imagemCopia)
    
    return imagemCopia

def alterarContraste(imagemOriginal, imagemCopia, intensidade):
    return imagemCopia  

def alterarBrilho(imagemOriginal, imagemCopia, intensidade):
    return imagemCopia

def alterarSaturacao(imagemOriginal, imagemCopia, intensidade):
    return imagemCopia

def fazerCopiaNome(caminho_arquivo):
    caminho = os.path.split(caminho_arquivo)
    novo_caminho = (caminho[0] + "/" + "copia_" + caminho[1])
    return novo_caminho
