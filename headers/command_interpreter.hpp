#ifndef COMMAND_INTERPRETER_HPP_
#define COMMAND_INTERPRETER_HPP_

/* this class reads, interprets and executes game commands*/
class command_interpreter {
private:
public:
	command_interpreter();
	~command_interpreter();

	/* calls cin >> and waits until the user inserts a command
	 * if it is a valid command it will be executed by this same function
	 * and true will be returned if is not a valid command it will just return false*/
	bool wait_for_command();
};

#endif
