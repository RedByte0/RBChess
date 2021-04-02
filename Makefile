CC=g++
FLAGS=-Wall -Wextra -pedantic -c -g -std=c++17 -O0 -e -j10

output: main.o board.o board_printer.o piece.o pawn.o
	g++ *.o -o RBChess

main.o: main.cpp
	$(CC) main.cpp $(FLAGS)

board.o: ./class_implementations/board.cpp ./headers/board.hpp
	$(CC) ./class_implementations/board.cpp $(FLAGS)

board_printer.o: ./class_implementations/board_printer.cpp ./headers/board_printer.hpp
	$(CC) ./class_implementations/board_printer.cpp $(FLAGS)

piece.o: ./class_implementations/piece.cpp ./headers/piece.hpp	
	$(CC) ./class_implementations/piece.cpp $(FLAGS)

pawn.o: ./class_implementations/pawn.cpp ./headers/pawn.hpp	
	$(CC) ./class_implementations/pawn.cpp $(FLAGS)

clean:
	rm *.o RBChess
