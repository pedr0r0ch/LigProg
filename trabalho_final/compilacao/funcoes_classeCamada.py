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

    objeto.save(imagemCopia, "PNG") 


    return imagemCopia

def efeitoDesfoque(imagemOriginal, intensidade):

    imagemCopia = fazerCopiaNome(imagemOriginal)
    imagem = Image.open(imagemOriginal)
    imagem = imagem.filter(ImageFilter.GaussianBlur(intensidade))

    imagem.save(imagemCopia, "PNG")
    return imagemCopia

def alterarContraste(imagemOriginal, intensidade):
    imagemCopia = fazerCopiaNome(imagemOriginal)

    imagem = Image.open(imagemOriginal)
    
    enhancer = ImageEnhance.Contrast(imagem)
    imagem_com_saturacao = enhancer.enhance(intensidade)
    
    imagem_com_saturacao.save(imagemCopia, "PNG")

    return imagemCopia  

def alterarBrilho(imagemOriginal, intensidade):
    imagemCopia = fazerCopiaNome(imagemOriginal)
    
    imagem = Image.open(imagemOriginal)
    
    enhancer = ImageEnhance.Brightness(imagem)
    imagem_com_brilho = enhancer.enhance(intensidade)
    
    imagem_com_brilho.save(imagemCopia, "PNG")

    return imagemCopia

def alterarSaturacao(imagemOriginal, intensidade):
    imagemCopia = fazerCopiaNome(imagemOriginal)

    imagem = Image.open(imagemOriginal)
    
    enhancer = ImageEnhance.Color(imagem)
    imagem_com_saturacao = enhancer.enhance(intensidade)
    
    imagem_com_saturacao.save(imagemCopia, "PNG")

    return imagemCopia

def fazerCopiaNome(caminho_arquivo):
    nome_base, extensao_atual = os.path.splitext(os.path.basename(caminho_arquivo))

    novo_nome = "copia_" + nome_base + ".png"

    novo_caminho = os.path.join(os.path.dirname(caminho_arquivo), novo_nome)

    return novo_caminho
