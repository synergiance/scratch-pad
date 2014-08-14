CC=g++
CFLAGS=-std=c++11 -Wall -pthread
OFLAGS=-c $(CFLAGS)
OBJ=main.o
BIN=race


all: race

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

main.o: main.cpp
	$(CC) $(OFLAGS) main.cpp

%.o: %.cpp %.h
	$(CC) $(OFLAGS) -o $@ $<

.PHONY: clean cleanobj

clean: cleanobj
	rm -rf $(BIN)

cleanobj:
	rm -rf *.o
