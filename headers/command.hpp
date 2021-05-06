#ifndef COMMAND_HPP_
#define COMMAND_HPP_

#include "command_interpreter.hpp"

#include <string>
#include <iostream>
#include <vector>
#include <functional>

class command_interpreter;

/* this class represents the commands that the player can execute,
 * every command has an unique char and an unique string that idetifies it*/
class command {
private:
	const char _identifier_char;
	const std::string _identifier_str;
	const char* _help_message;
	const char* _example_message;
	/* each command requires a different amount of parameters,
	* there are no commands that have a variable number of parameters*/
	const std::size_t _number_of_parameters;

	std::function<void(void)> _function;

public:
	command(const char ch, const std::string str, const char* help, const char* example, const int num_parameters, std::function<void(void)>);
	~command();

	command() = delete;
	command(const command& com) = delete; 
	command(const command&& com) = delete;
	command& operator=(const command& com) = delete; 
	command& operator=(const command&& com) = delete;
	
	void execute();

	/*compare str with _identifier_char and _identifier_str*/
	bool operator==(const std::string& str) const;
	/*compare num_parameters with _number_of_parameters*/
	bool operator==(const std::size_t num_parameters) const;
	friend std::ostream& operator<<(std::ostream& os, const command& com);

};

#endif
