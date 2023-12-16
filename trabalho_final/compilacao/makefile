# Variáveis para o compilador e as opções de compilação
CC = g++
CFLAGS=-Wall -std=c++17 
LDFLAGS= -lncurses -lpython3.10

# Nome do executável
TARGET = trabalho_final_Editor_Fotografias

# Lista de arquivos-fonte
#
CPP= funcoesGlobais.cpp\
	 classeEdicao.cpp\
	 classeCamada.cpp\
	 main.cpp

# Lista de arquivos-objeto gerados a partir dos arquivos-fonte
OBJS = $(CPP:.cpp=.o)

# Regra de compilação do alvo principal
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Regra de compilação para cada arquivo-fonte

.cpp.o:
	$(CC) $(CFLAGS) -c $<

# Regra para limpar os arquivos-objeto e o executável
clean:
	rm -f $(OBJS)

clean-all:
	rm -f $(OBJS) $(TARGET)

# Define o alvo "all" para construir o programa (o alvo padrão)
all: $(TARGET)
