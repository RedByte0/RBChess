#ifndef COMMAND_INTERPRETER_HPP_
#define COMMAND_INTERPRETER_HPP_

#include "command.hpp"
#include <string>
#include <vector>
#include "algebraic_notation_converter.hpp"

class command;

/* this class reads, interprets and executes game commands*/
class command_interpreter {
private:
	algebraic_notation_converter _algebraic_converter;
	const char* _error_messages[2];
	command* _commands;
	const int _NUMBER_OF_COMMANDS = 3;

	/* store the last command ans its parameters
	 * this is used by the cmmd methods to read the parameters*/
	std::vector<std::string> _last_command;
public:
	command_interpreter();
	//I am fine with using raw pointers if there is not any memory allocation happening
	~command_interpreter();

	/* calls cin >> and waits until the user inserts a command
	 * if it is a valid command it will be executed by this same function
	 * and true will be returned if is not a valid command it will just return false*/
	bool wait_for_command();
	int number_of_commands() const {return _NUMBER_OF_COMMANDS;}

	void print_error_message(int msg) const;

	/* it tries to execute the command given by the player and does all sort
	 * of error checking */	
	void execute_command(std::string& command_str);

	/* compares the command_str with the commands inside the _commands array
	 * and if any of then matches it will return its index*/
	command* find_command(std::string& command_str) const;
       
	/* when the user enters a command it can have parameters so the command and
	 * the parameters have to be separated, the ' ' char is used as a the divider*/	
	std::vector<std::string> command_to_parameter_vector(const std::string& user_command) const;

//	int extract_parameters_from_commands

	/*all the methods with the cmmd prefix can be accesed by a command*/
	void cmmd_help(); //display all commands
	void cmmd_quit(); //quit program
	
	void cmmd_kill(); //kill a given piece  : debug
};

#endif
