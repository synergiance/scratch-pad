LFLAGS=-lssl -lcrypto
CC=g++
BIN=sget
OBJ=ssl.o sock.o main.o

ALL: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LFLAGS) $(OBJ)
