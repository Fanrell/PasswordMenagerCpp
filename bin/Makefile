CC = g++
FLAGS = -lncurses
OBJ = ../obj/
SRC = ../src/
INC = ../includes/
all: main.o 
	$(CC) main.o  -o PasswordMenager  $(FLAGS)
main.o: $(SRC)main.cc mainWindow.o 
	$(CC) -c $(SRC)main.cc 
mainWindow.o: $(SRC)mainWindow.cc $(SRC)Menu.o
	$(CC) -c $(SRC)mainWindow.cc
Menu.o: $(SRC)Menu.cc 
	$(CC) -c $(SRC)Menu.cc 