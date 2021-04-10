#ifndef COMMAND_HPP_
#define COMMAND_HPP_

#include "command_interpreter.hpp"

#include <string>
#include <iostream>
#include <vector>

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
	* there are no commands that have a variable amount of parameters so
	* a simple int should be enough, if need be I could turn this into an array
	* or I could create two variables min and max*/
	const int _number_of_parameters;

	/* every command is related to a method from command_interpreter*/
	void(command_interpreter::* _function)();
public:
	command(const char ch, const std::string str, const char* help, const char* example, const int num_parameters, void(command_interpreter::* func)());
	~command();

	void execute(command_interpreter* interpreter);

	/*compare str with _identifier_char and _identifier_str*/
	bool operator==(const std::string& str) const;
	/*compare num_parameters with _number_of_parameters*/
	bool operator==(const int num_parameters) const;
	friend std::ostream& operator<<(std::ostream& os, const command& com);	

	//this class can't be copied, moved or assigned
	command() = delete;
	command(const command& com) = delete;
	command(const command&& com) = delete;
	command& operator=(const command& com) = delete;
	command& operator=(const command&& com) = delete;

};

#endif
