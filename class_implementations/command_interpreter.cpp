#include "../headers/command_interpreter.hpp"
#include "../headers/interactive_layer.hpp"
#include "../headers/board.hpp"
#include <iostream>
#include <string>

command_interpreter::command_interpreter() {
	_error_messages[0] = {
		"Invalid command, use h to display all the valid commands"
	};
	_commands = new command[2] {
		{'h', "help", "this command displays all the available commands and how to use them", "h", 0, &command_interpreter::cmmd_help},
		{'q', "quit", "quit the game", "q", 0, &command_interpreter::cmmd_quit}
	};
}

command_interpreter::~command_interpreter() {
	delete [] _commands;
}

bool command_interpreter::wait_for_command() {
	std::string command;
	std::cout << '[' << (board::instance()->team() ? "white" : "black") << ']' << "$ ";
	std::getline(std::cin, command);
	execute_command(command);

	return false;
}

void command_interpreter::print_error_message(int msg) const {
	std::cout << _error_messages[msg] << std::endl;
	std::cin.get();
}

void command_interpreter::execute_command(std::string& command_str) {
	bool valid_command = false;
	int command_index = find_command(command_str, valid_command);
	
	if(!valid_command) {
		print_error_message(0);
		return;
	}

	_commands[command_index].execute(this);
}

/*I dont like the method returning 0*/
int command_interpreter::find_command(std::string& command_str, bool& valid_command) const {
	valid_command = true;
	for(int i = 0; i < _NUMBER_OF_COMMANDS; i++) {
		if(_commands[i] == command_str)
			return i;
	}
	valid_command = false;
	return 0;
}

void command_interpreter::cmmd_help() {
	for(int i = 0; i < _NUMBER_OF_COMMANDS; i++)
		std::cout << _commands[i];
	std::cout << std::endl;
	std::cin.get();
}

void command_interpreter::cmmd_quit() {
	interactive_layer::instance()->quit_game();
}
