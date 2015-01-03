all: TicTacToe

TicTacToe: Player.o Input.o Board.o main.o
	g++ -o TicTacToe main.o Player.o Input.o Board.o

main.o : main.cpp Input.h Board.h Player.h
	g++ -Wall -c main.cpp

Player.o : Player.cpp Player.h
	g++ -Wall -c Player.cpp

Input.o : Input.cpp Input.h Board.h Player.h
	g++ -Wall -c Input.cpp

Board.o : Board.cpp Board.h
	g++ -Wall -c Board.cpp
clean :
	rm -rf *.o  
