CC=g++
CFLAGS=-c -std=c++11

all: mpass

mpass: main.o cclass.o
	$(CC) main.o cclass.o -o mpass

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

cclass.o: cclass.cpp
	$(CC) $(CFLAGS) cclass.cpp
