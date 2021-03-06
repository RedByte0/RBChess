CC=g++
FLAGS=-Wall -Wextra -Wpedantic -pedantic -c -g -std=c++17 -O0 -e -j10

output: main.o board.o board_printer.o piece.o pawn.o interactive_layer.o command_interpreter.o command.o algebraic_notation.o rook.o bishop.o queen.o king.o knight.o
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

interactive_layer.o: ./class_implementations/interactive_layer.cpp ./headers/interactive_layer.hpp	
	$(CC) ./class_implementations/interactive_layer.cpp $(FLAGS)

command_interpreter.o: ./class_implementations/command_interpreter.cpp ./headers/command_interpreter.hpp	
	$(CC) ./class_implementations/command_interpreter.cpp $(FLAGS)

command.o: ./class_implementations/command.cpp ./headers/command.hpp	
	$(CC) ./class_implementations/command.cpp $(FLAGS)

algebraic_notation.o: ./class_implementations/algebraic_notation.cpp ./headers/algebraic_notation.hpp
	$(CC) ./class_implementations/algebraic_notation.cpp $(FLAGS)

rook.o: ./class_implementations/rook.cpp ./headers/rook.hpp	
	$(CC) ./class_implementations/rook.cpp $(FLAGS)

bishop.o: ./class_implementations/bishop.cpp ./headers/bishop.hpp	
	$(CC) ./class_implementations/bishop.cpp $(FLAGS)

queen.o: ./class_implementations/queen.cpp ./headers/queen.hpp	
	$(CC) ./class_implementations/queen.cpp $(FLAGS)

king.o: ./class_implementations/king.cpp ./headers/king.hpp	
	$(CC) ./class_implementations/king.cpp $(FLAGS)

knight.o: ./class_implementations/knight.cpp ./headers/knight.hpp	
	$(CC) ./class_implementations/knight.cpp $(FLAGS)


clean:
	rm *.o RBChess
	clear
