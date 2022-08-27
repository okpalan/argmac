CC = gcc
INCLUDE= include
CFLAGS =  -I$(INCLUDE)
BIN= bin
SRC= src
OBJ= obj

all: argmac.o
	$(CC) $(CFLAGS) -o $(BIN)/argmac $(OBJ)/argmac.o 

argmac.o:
	$(CC) $(CFLAGS) -c $(SRC)/argmac.c -o $(OBJ)/argmac.o

