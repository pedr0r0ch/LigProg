#funcoes que os metodos da classe Edicao utilizam

from PIL import Image

def sobrepor(arquivoReserva, imagemFundo, imagemFrente, transparencia=0):

    imagem_fundo = Image.open(imagemFundo)
    imagem_sobreposta = Image.open(imagemFrente)

    # convertendo as imagens para o modo RGBA para que sejapossivel controlar a trasnparencia
    imagem_fundo = imagem_fundo.convert("RGBA")
    imagem_sobreposta = imagem_sobreposta.convert("RGBA")

    imagem_sobreposta = Image.eval(imagem_sobreposta, lambda x: x * transparencia)


    # Sobrepondo as imagens
    imagem_fundo.paste(imagem_sobreposta, (0, 0), imagem_sobreposta)

    # Salvar a imagem sobreposta
    imagem_fundo.save(arquivoReserva)