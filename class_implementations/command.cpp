#include "../headers/command.hpp"

command::command(const char ch, const std::string& str, const char* help, const char* example) 
	: _identifier_char(ch), _identifier_str(str) {
	_help_message = help;
	_example_message = example;
}

command::~command() {}

std::ostream& operator<<(std::ostream& os, const command& com) {
	os << com._identifier_char << ": " << com._identifier_str << std::endl
		<< "help: " << com._help_message << std::endl
		<< "example: " << com._example_message << std::endl;	
	//return the ostream object so it can be concatenated
	return os;
}
