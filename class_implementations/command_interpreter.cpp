#include "../headers/command_interpreter.hpp"
#include <iostream>
#include <string>

command_interpreter::command_interpreter() {

}

command_interpreter::~command_interpreter() {}

bool command_interpreter::wait_for_command() {
	std::string command;
	std::cout << "$ ";
	std::getline(std::cin, command);
	
	return false;
}	
