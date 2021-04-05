#ifndef COMMAND_INTERPRETER_HPP_
#define COMMAND_INTERPRETER_HPP_

#include "command.hpp"
#include <string>

class command;

/* this class reads, interprets and executes game commands*/
class command_interpreter {
private:
	const char* _error_messages[1];
	command* _commands;
	const int _NUMBER_OF_COMMANDS = 2;
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
	int find_command(std::string& command_str, bool& valid_command) const; 


	/*all the methods with the cmmd prefix can be accesed by a command*/
	void cmmd_help(); //display all commands
	void cmmd_quit(); //quit program
};

#endif
