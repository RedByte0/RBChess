#ifndef COMMAND_INTERPRETER_HPP_
#define COMMAND_INTERPRETER_HPP_

#include "command.hpp"
#include <string>
#include <vector>
#include "algebraic_notation.hpp"
#include "board.hpp"

class command;

/* this class reads, interprets and executes game commands*/
class command_interpreter {
private:
	std::shared_ptr<board> _board;
	algebraic_notation _algebraic_converter;
	const int _NUMBER_OF_COMMANDS;
	command* _commands;

	/* stores the arguments that the user entered if any
	 * alongside the last command*/
	std::vector<std::string> _last_command_args;
public:
	command_interpreter();
	~command_interpreter();

	/* calls cin >> and waits until the user inserts a command
	 * if it is a valid command it will be executed by this same function
	 * and true will be returned, if is not a valid command it will just return false*/
	bool wait_for_command();
	int number_of_commands() const { return _NUMBER_OF_COMMANDS; }

	void print_error_message(const char* msg) const;
	void print_error_message(const std::string msg) const;

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

	algebraic_notation* algebraic_converter() { return &_algebraic_converter; }

	std::vector<std::string> last_command_arguments() const { return _last_command_args; }

};

#endif