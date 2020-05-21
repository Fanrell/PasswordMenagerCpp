CC = g++
FLAGS = -lncurses
OBJ = ../obj/
SRC = ../src/
INC = ../includes/
all: main.o 
	$(CC) main.o  -o PasswordMenager  $(FLAGS)
main.o: $(SRC)main.cc Menu.o $(INC)Menu.h
	$(CC) -c $(SRC)main.cc -I $(INC)

Menu.o: $(SRC)Menu.cc $(INC)Menu.h
	$(CC) -c $(SRC)Menu.cc -I $(INC)