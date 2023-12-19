
from PIL import Image
from globais import exibirArquivoImagem
import os

def fazerCopiaNome(caminho_arquivo):
    diretorio, nome_arquivo = os.path.split(caminho_arquivo)

    novo_caminho_arquivo = os.path.join(diretorio, ("copia_" + nome_arquivo))

    return novo_caminho_arquivo



def sobrepor(imagemFundo, imagemFrente, transparencia):
    arquivoCopia = fazerCopiaNome(imagemFundo)

    camada_1 = Image.open(imagemFundo).convert('RGBA')
    camada_2 = Image.open(imagemFrente).convert('RGBA')

    # Obter as dimensões da imagem maior e da imagem menor
    largura_camada1, altura_camada1 = camada_1.size
    largura_camada2, altura_camada2 = camada_2.size

    if((largura_camada1, altura_camada1) != (largura_camada2, altura_camada2)):
        if(largura_camada1 > largura_camada2):
            maiorLargura = largura_camada1
        else:
            maiorLargura = largura_camada2

        if(altura_camada1 > altura_camada2):
            maiorAltura = altura_camada1
        else:
            maiorAltura = altura_camada2

        nova_camada_1 = Image.new('RGBA', (maiorLargura, maiorAltura), (0, 0, 0, 0))
        nova_camada_2 = Image.new('RGBA', (maiorLargura, maiorAltura), (0, 0, 0, 0))

        nova_camada_1.paste(camada_1, ((maiorLargura - largura_camada1)/2,(maiorAltura - altura_camada1)/2))
        nova_camada_2.paste(camada_2, ((maiorLargura - largura_camada2)/2,(maiorAltura - altura_camada2)/2))


        imagemSobreposta = Image.blend(nova_camada_1, nova_camada_2, 0.7)

    else:
        imagemSobreposta = Image.blend(camada_1, camada_2, 0.7)
    
    imagemSobreposta.save(arquivoCopia, "PNG")
    return arquivoCopia
    
exibirArquivoImagem(sobrepor("../dir_trabalho/edicaoFinal.png", "../dir_trabalho/centro_de_tecnologia_BLCA.png", 1))