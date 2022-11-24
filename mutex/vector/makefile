CC=g++
CFLAGS=-c -std=c++11

all: thvector

thvector: main.o
	$(CC) main.o -o thvector

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

