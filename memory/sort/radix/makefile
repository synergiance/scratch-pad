CC=g++
ARGS=
BIN=radix
CFLAGS=$(ARGS) -O3 -std=c++11 -ggdb -Wall
OFLAGS=-c $(CFLAGS)
LFLAGS=$(CFLAGS)
OBJ=main.o radix.o

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) $(LFLAGS) -o $(BIN)

main.o: main.cpp
	$(CC) $(OFLAGS) main.cpp

%.o: %.cpp %.h
	$(CC) $(OFLAGS) -o $@ $<

.PHONY: clean cleanobj

clean: cleanobj
	rm -rf $(BIN)

cleanobj:
	rm -rf $(OBJ)
