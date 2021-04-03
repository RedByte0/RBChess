#ifndef COMMAND_HPP_
#define COMMAND_HPP_

#include <string>
#include <iostream>

/* this class represents the commands that the player can execute,
 * every command has an unique char and an unique string that idetifies it*/
class command {
private:
	const char _identifier_char;
	const std::string _identifier_str;
	const char* _help_message;
	const char* _example_message;
public:
	command(const char ch, const std::string& str, const char* help, const char* example);
	~command();

	//this class can't be copied, moved or assigned
	command() = delete;
	command(const command& com) = delete;
	command(const command&& com) = delete;
	command& operator=(const command& com) = delete;
	command& operator=(const command&& com) = delete;

	friend std::ostream& operator<<(std::ostream& os, const command& com);
};

#endif
