#funcoes que os metodos da classe Edicao utilizam

from PIL import Image
import os


def fazerCopiaNome(caminho_arquivo):
    diretorio, nome_arquivo = os.path.split(caminho_arquivo)

    novo_caminho_arquivo = os.path.join(diretorio, ("copia_" + nome_arquivo))

    return novo_caminho_arquivo

def sobrepor(imagemFundo, imagemFrente, transparencia=0):

    copia_arquivoFundo = fazerCopiaNome(imagemFundo)

    imagem_fundo = Image.open(imagemFundo)
    imagem_sobreposta = Image.open(imagemFrente)

    # convertendo as imagens para o modo RGBA para que sejapossivel controlar a trasnparencia
    imagem_fundo = imagem_fundo.convert("RGBA")
    imagem_sobreposta = imagem_sobreposta.convert("RGBA")

    imagem_sobreposta = Image.eval(imagem_sobreposta, lambda x: x * transparencia)


    # Sobrepondo as imagens
    imagem_fundo.paste(imagem_sobreposta, (0, 0), imagem_sobreposta)

    # Salvar a imagem sobreposta
    imagem_fundo.save(copia_arquivoFundo)


