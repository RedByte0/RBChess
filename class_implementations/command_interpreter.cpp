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

void command_interpreter::execute_command(std::string& command_str) {
	_last_command = std::move(command_to_parameter_vector(command_str));
	//the first parameter is the _identifier_char or the _identifier_str of the command
	command* command_ptr = find_command(_last_command[0]);
	_last_command.pop_back(); //remove the 


	if(command_ptr == nullptr) {
		print_error_message(0);
	}
	else if ((*command_ptr) == _last_command.size()) {
		command_ptr->execute(this);
	}
	else {
		print_error_message(1);
	}
}

/*I dont like the method returning 0*/
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
}
