#ifndef INTERACTIVE_LAYER_HPP_
#define INTERACTIVE_LAYER_HPP_

#include "board_printer.hpp"
#include "command_interpreter.hpp"

/* this class is the one that the user will interact with,
 * it allows the user to input commands, it displays the board when required
 * and does all sort of comprobations to make sure that the users input
 * is passed properly to the board and piece classes*/
class interactive_layer {
private:
	bool _run_game;
	board_printer _board_printer;
	command_interpreter _interpreter;
public:
	interactive_layer();
	~interactive_layer();

	/* this is the main game loop of the game
	 * and it should keep running until _run_game is false*/
	void start_game();
};

#endif
