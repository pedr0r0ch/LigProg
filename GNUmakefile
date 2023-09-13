# Variáveis para o compilador e as opções de compilação
CC = g++
CFLAGS = -Wall

# Nome do executável
TARGET = primeiro_entregavel

# Lista de arquivos-fonte
CPP = classeAlunos.cpp\
	  classeDisciplina.cpp\
	  classeGestorAcademico.cpp\
	  main.cpp

# Lista de arquivos-objeto gerados a partir dos arquivos-fonte
OBJS = $(CPP:.cpp=.o)

# Regra de compilação do alvo principal
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regra de compilação para cada arquivo-fonte

.o.cpp:
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos-objeto e o executável
clean:
	rm -f $(OBJS)

clean-all:
	rm -f $(OBJS) $(TARGET)

# Define o alvo "all" para construir o programa (o alvo padrão)
all: $(TARGET)