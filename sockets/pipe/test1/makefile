CC=g++
CFLAGS=-c -std=c++11
OBJ=main.o

all: testprog

testprog: $(OBJ)
	$(CC) $(OBJ) -o testprog

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean cleanobj

clean: cleanobj
	rm -rf ibot

cleanobj:
	rm -rf *.o
