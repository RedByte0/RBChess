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

	/* this class is a singleton so the only constructor is private*/
	interactive_layer();
public:
	~interactive_layer();

	static std::shared_ptr<interactive_layer> instance() {
		static std::shared_ptr<interactive_layer> inst{new interactive_layer()};
		return inst;
	}

	/* this is the main loop of the game
	 * and it should keep running until _run_game is set to false*/
	void start_game();
	void quit_game();

	board_printer* get_board_printer() {return &_board_printer;}

	//this errors only occur when there is some input from the user, this is why they are part of the interactive layer
	inline void print_error_message(const char* message) const {
		std::cout << message << ", use h to display help menu... ";
		std::cin.get();
	}

	inline void print_error_message(const std::string message) const {
		std::cout << message << ", use h to display help menu... ";
		std::cin.get();
	}

	/* this class can not be copied or moved*/
	interactive_layer(const interactive_layer& inte) = delete;
	interactive_layer(const interactive_layer&& inte) = delete;
	interactive_layer& operator=(const interactive_layer& inte) = delete;
	interactive_layer& operator=(const interactive_layer&& inte) = delete;
};

#endif
