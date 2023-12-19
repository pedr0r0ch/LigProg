
from PIL import Image
from globais import exibirArquivoImagem
import os

def fazerCopiaNome(caminho_arquivo):
    diretorio, nome_arquivo = os.path.split(caminho_arquivo)

    novo_caminho_arquivo = os.path.join(diretorio, ("copia_" + nome_arquivo))

    return novo_caminho_arquivo



def sobrepor(imagemFundo, imagemFrente, transparencia):
    try:
        arquivoCopia = fazerCopiaNome(imagemFundo)

        camada_1 = Image.open(imagemFundo).convert('RGBA')
        camada_2 = Image.open(imagemFrente).convert('RGBA')

        # Obter as dimensões da imagem maior e da imagem menor
        largura_maior, altura_maior = camada_1.size
        largura_menor, altura_menor = camada_2.size

        # Calcular o offset para centralizar a imagem menor na imagem maior
        offset_x = (largura_maior - largura_menor) // 2
        offset_y = (altura_maior - altura_menor) // 2

        # Criar uma imagem em branco do mesmo tamanho da imagem maior
        imagem_resultante = Image.new('RGBA', (largura_maior, altura_maior), (0, 0, 0, 0))

        # Colocar a imagem menor no centro da imagem em branco
        imagem_resultante.paste(camada_2, (offset_x, offset_y), camada_2)

        # Aplicar a transparência à imagem de frente
        imagem_frente_transparente = Image.new('RGBA', (largura_maior, altura_maior), (0, 0, 0, 0))
        imagem_frente_transparente = Image.alpha_composite(imagem_frente_transparente, camada_2)
        imagem_frente_transparente.putalpha(int(transparencia * 255))

        # Sobrepor as imagens
        imagem_sobreposta = Image.alpha_composite(camada_1, imagem_frente_transparente)

        # Salvar a imagem sobreposta
        imagem_sobreposta.save(arquivoCopia, "PNG")

        return arquivoCopia

    except Exception as e:
        # Tratamento de erro genérico
        print(f"Erro: {e}")
        return None
    
exibirArquivoImagem(sobrepor("../dir_trabalho/edicaoFinal.png", "../dir_trabalho/centro_de_tecnologia_BLCA.png", 1.0))