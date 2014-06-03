CC=g++
CFLAGS=-c -std=c++11

all: recursivity

recursivity: main.o
	$(CC) main.o -o recursivity

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

