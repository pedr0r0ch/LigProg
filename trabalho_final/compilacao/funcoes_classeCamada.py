#funcoes que os metodos da classe Camada utilizam   

import os

import cv2
import numpy as np

from rembg import remove
from PIL import Image, ImageFilter



def manterObjeto(imagemOriginal):
    imagemCopia = fazerCopiaNome(imagemOriginal)

    imagem = cv2.imread(imagemOriginal)

    # Converte a imagem para o espaço de cores RGBA
    imagem_rgba = cv2.cvtColor(imagem, cv2.COLOR_BGR2BGRA)

    # Cria uma máscara inicial (tudo é considerado desconhecido)
    mascara = np.zeros(imagem.shape[:2], dtype=np.uint8)

    # Especifica um retângulo que contém o objeto de interesse (COI)
    retangulo_coi = (10, 10, imagem.shape[1]-10, imagem.shape[0]-10)

    # Inicializa a máscara com o COI conhecido (cv2.GC_FGD)
    cv2.grabCut(imagem_rgba, mascara, retangulo_coi, None, None, 5, cv2.GC_INIT_WITH_RECT)

    # Atualiza a máscara para incluir o COI (cv2.GC_FGD) e o COI possível (cv2.GC_PR_FGD)
    mascara2 = np.where((mascara == 2) | (mascara == 0), 0, 1).astype('uint8')

    # Multiplica os canais de cores pelo canal alfa da máscara
    imagem_sem_fundo = imagem_rgba * mascara2[:, :, np.newaxis]

    # Salva a imagem sem fundo como um novo arquivo
    cv2.imwrite(imagemCopia, imagem_sem_fundo)

    return imagemCopia

def efeitoDesfoque(imagemOriginal, imagemCopia, intensidade):

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
