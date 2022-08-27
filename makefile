CC = gcc
INCLUDE= include
CFLAGS =  -I$(INCLUDE) -
BIN= bin
SRC= src
OBJ= obj

all: $(SRC)/example.c 
	$(CC) $(CFLAGS) -o $@ $^

