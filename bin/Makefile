CC = g++
FLAGS = -lncurses
OBJ = ../obj/
SRC = ../src/
INC = ../includes/
all: main.o
	$(CC) main.o -o PasswordMenager $(FLAGS)
main.o: $(SRC)main.cc menu.o
	$(CC) -c $(SRC)main.cc

menu.o: $(SRC)menu.cc $(INC)menu.h
	$(CC) -c $(SRC)menu.cc