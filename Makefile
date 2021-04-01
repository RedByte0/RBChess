CC=g++
FLAGS=-Wall -Wextra -pedantic -c -g

output: main.o board.o board_ui.o
	g++ *.o -o RBChess

main.o: main.cpp
	$(CC) main.cpp $(FLAGS)

board.o: ./class_implementations/board.cpp ./headers/board.hpp
	$(CC) ./class_implementations/board.cpp $(FLAGS)

board_ui.o: ./class_implementations/board_ui.cpp ./headers/board_ui.hpp
	$(CC) ./class_implementations/board_ui.cpp $(FLAGS)
clean:
	rm *.o RBChess
