#include "../headers/command_interpreter.hpp"
#include "../headers/interactive_layer.hpp"
#include "../headers/board.hpp"
#include <iostream>
#include <string>

command_interpreter::command_interpreter() {
	_error_messages[0] = {"Invalid command"};
       	_error_messages[1] = {"Invalid number of arguments"};
	_commands = new command[3] {
		{'h', "help", "this command displays all the available commands and how to use them", "h", 0, &command_interpreter::cmmd_help},
		{'q', "quit", "quit the game", "q", 0, &command_interpreter::cmmd_quit},
		{'k', "kill", "kill the piece at the given position", "k a8", 1, &command_interpreter::cmmd_kill}
	};
}

command_interpreter::~command_interpreter() {
	delete [] _commands;
}

bool command_interpreter::wait_for_command() {
	
	std::string command;
	
	while(command.length() == 0) {
		std::cout << '[' << (board::instance()->team() ? "white" : "black") << ']' << "$ ";
		std::getline(std::cin, command);
	}

	execute_command(command);

	return false;
}

void command_interpreter::print_error_message(int msg) const {
	std::cout << _error_messages[msg] << ", use h to display the help menu...";
	std::cin.get();
}


/* the command_str parameter contains the name of the command and the parameters of the command*/
void command_interpreter::execute_command(std::string& command_str) {
	//the command is split into a vector of strings
	_last_command = std::move(command_to_parameter_vector(command_str));
	
	//the first parameter is the _identifier_char or the _identifier_str of the command
	command* command_ptr = find_command(_last_command[0]);
	
	//since we already have a pointer to the command the command _identifier is not needed anymore
	_last_command.erase(_last_command.begin());

	//if the pointer is null it means the given _identifier is not a valid one
	if(command_ptr == nullptr) {
		print_error_message(0);
	}
	//compares the number of elements of the vector with the number of parameters that the command can take
	else if ((*command_ptr) == _last_command.size()) {
		//this is a bit confusing, the _function hold by the command is a pointer to a function
		//from the command_interpreter class, so in order to execute the _function from the command
		//an instance of command_interpreter is required
		command_ptr->execute(this);
	}
	else {
		print_error_message(1);
	}
}

/* compares a given string with all the commands and if it 
 * finds a command that matches it returns a pointer to it, 
 * if not returns nullptr*/
command* command_interpreter::find_command(std::string& command_str) const {
	for(int i = 0; i < _NUMBER_OF_COMMANDS; i++) {
		if(_commands[i] == command_str)
			return &_commands[i];
	}
	return nullptr;
}

std::vector<std::string> command_interpreter::command_to_parameter_vector(const std::string& user_command) const {
	std::vector<std::string> parameters;
	std::string str = "";
	for(std::size_t i = 0; i <  user_command.length(); i++) {
		if(user_command[i] == ' ') {
			parameters.push_back(str);
			str = "";
		}
		else {
			str += user_command[i];
		}
	}
	parameters.push_back(str);
	return parameters;
}

void command_interpreter::cmmd_help() {	
	for(int i = 0; i < _NUMBER_OF_COMMANDS; i++)
		std::cout << _commands[i] << std::endl;
	std::cin.get();
}

void command_interpreter::cmmd_quit() {
	interactive_layer::instance()->quit_game();
}

void command_interpreter::cmmd_kill() {
	if(_algebraic_converter == _last_command[0]) {
	}	
}
