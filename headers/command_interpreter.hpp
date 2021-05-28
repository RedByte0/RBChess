#ifndef COMMAND_INTERPRETER_HPP_
#define COMMAND_INTERPRETER_HPP_

#include "command.hpp"
#include <string>
#include <vector>
#include "algebraic_notation.hpp"
#include "board.hpp"
#include <memory>

class command;

/* this class reads, interprets and executes game commands*/
class command_interpreter {
private:
	std::shared_ptr<board> _board;
	algebraic_notation _algebraic_converter;
	const int _NUMBER_OF_COMMANDS;
	command* _commands;

	/* stores the arguments of the last command*/
	std::vector<std::string> _args;

public:

	command_interpreter();
	~command_interpreter();

	/* calls cin >> and waits until the user inserts a command
	 * if it is a valid command it will be executed by this same function*/
	void wait_for_command();
	int number_of_commands() const { return _NUMBER_OF_COMMANDS; }

	/* it tries to execute the command given by the player and does all sort
	 * of error checking */
	void execute_command(std::string& command_str);

	/* compares the command_str with the commands inside the _commands array
	 * and if any of then matches it will return its index*/
	command* find_command(std::string& command_str) const;

	/* when the user enters a command it can have parameters so the command and
	 * the parameters have to be separated, the ' ' char is used as a the divider*/
	std::vector<std::string> command_to_parameter_vector(const std::string& user_command) const;

	//returns the command at the given index
	command* operator[](int index) const;

	//this methods wrap some from the board and add some error messges

	std::shared_ptr<piece> piece_at(int position);


	/*class methods that can be accesed by commands*/
	void command_help();
	void command_quit();
	void command_move();
	void command_reveal();

	//debug
	void command_swap();
	void command_kill();
};

#endif
