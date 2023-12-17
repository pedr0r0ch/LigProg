#funcoes que os metodos da classe Camada utilizam   

import os

from rembg import remove
from PIL import Image
from PIL import ImageFilter
from PIL import ImageEnhance



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

def alterarContraste(imagemOriginal, intensidade):
    imagemCopia = fazerCopiaNome(imagemOriginal)

    imagem = Image.open(imagemOriginal)
    
    enhancer = ImageEnhance.Contrast(imagem)
    imagem_com_saturacao = enhancer.enhance(intensidade)
    
    imagem_com_saturacao.save(imagemCopia)

    return imagemCopia  

def alterarBrilho(imagemOriginal, intensidade):
    imagemCopia = fazerCopiaNome(imagemOriginal)
    
    imagem = Image.open(imagemOriginal)
    
    enhancer = ImageEnhance.Brightness(imagem)
    imagem_com_brilho = enhancer.enhance(intensidade)
    
    imagem_com_brilho.save(imagemCopia)

    return imagemCopia

def alterarSaturacao(imagemOriginal, intensidade):
    imagemCopia = fazerCopiaNome(imagemOriginal)

    imagem = Image.open(imagemOriginal)
    
    enhancer = ImageEnhance.Color(imagem)
    imagem_com_saturacao = enhancer.enhance(intensidade)
    
    imagem_com_saturacao.save(imagemCopia)

    return imagemCopia

def fazerCopiaNome(caminho_arquivo):
    caminho = os.path.split(caminho_arquivo)
    novo_caminho = (caminho[0] + "/" + "copia_" + caminho[1])
    return novo_caminho
