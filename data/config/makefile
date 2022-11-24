CC=g++
ARGS=
CFLAGS=$(ARGS) -std=c++11 -Wall
OFLAGS=-c $(CFLAGS)
LFLAGS=$(CFLAGS)
OBJ=main.o config.o
BIN=displayconfig

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) $(LFLAGS) -o $(BIN)

main.o: main.cpp
	$(CC) $(OFLAGS) main.cpp

%.o: %.cpp %.h
	$(CC) $(OFLAGS) -o $@ $<

.PHONY: clean cleanobj cleanbin

clean: cleanobj cleanbin

cleanobj:
	rm -rf $(OBJ)

cleanbin:
	rm -rf $(BIN)
