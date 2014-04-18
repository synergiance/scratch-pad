CC=g++
CFLAGS=-c -std=c++11

all: scout

scout: main.o
	$(CC) main.o -o scout

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

