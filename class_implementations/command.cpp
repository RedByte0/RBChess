#include "../headers/command.hpp"

command::command(const char ch, const std::string str, const char* help, const char* example, const int num_parameters, std::function<void(command_interpreter*)> func)
	: _identifier_char(ch), _identifier_str(str), _number_of_parameters(num_parameters) {
	_help_message = help;
	_example_message = example;
	_function = func;
}

command::~command() {}

void command::execute(command_interpreter* interpreter) {
	_function(interpreter);
}


bool command::operator==(const std::string& str) const {
	if(str.length() == 1)
		return str[0] == _identifier_char; 
	else
		return str == _identifier_str;
}

bool command::operator==(const std::size_t num_parameters) const {
	return _number_of_parameters == num_parameters;
}

std::ostream& operator<<(std::ostream& os, const command& com) {
	os << com._identifier_char << ": " << com._identifier_str << std::endl
		<< "\thelp: " << com._help_message << std::endl
		<< "\tparameters: " << com._number_of_parameters << std::endl
		<< "\texample: " << com._example_message << std::endl;	
	//return the ostream object so it can be concatenated
	return os;
}

