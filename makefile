CC = gcc
INCLUDE= include
CFLAGS =  -I$(INCLUDE) 
BIN= bin
SRC= src
OBJ= obj

all:$(BIN)/example
	$(CC) $(CFLAGS) -o $@ $^
