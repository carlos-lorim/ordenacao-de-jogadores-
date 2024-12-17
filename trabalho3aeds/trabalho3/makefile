# Nome do compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g

# Alvo do executável
TARGET = trabalho3

# Alvo principal (compilação do executável)
all: $(TARGET)

# Regra para compilar o programa
$(TARGET): trabalho3.c
	$(CC) $(CFLAGS) -o $(TARGET) trabalho3.c

# Limpeza dos arquivos gerados
clean:
	rm -f $(TARGET)
	rm -f *.o

# Alvo para rodar o programa com um argumento
run: $(TARGET)
	./$(TARGET) $(ARGS)
