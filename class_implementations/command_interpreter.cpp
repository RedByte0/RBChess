#include "../headers/command_interpreter.hpp"
#include "../headers/interactive_layer.hpp"
#include "../headers/board.hpp"
#include <iostream>
#include <string>

//what a nightmare of a constructor
command_interpreter::command_interpreter() : _NUMBER_OF_COMMANDS(4) {
	_board = board::instance();
	_commands = new command[4] {

		{'h', "help", "this command displays all the available commands and how to use them", "h", 0, 
			[](command_interpreter* interpreter) {
				for (int i = 0; i < interpreter->number_of_commands(); i++) {
					std::cout << (*(*interpreter)[i]) << std::endl;
				}
				std::cin.get();
			}
		},

		{'q', "quit", "quit the game", "q", 0,
			[](command_interpreter* interpreter) {
				interactive_layer::instance()->quit_game();
			}
		},

		{'k', "kill", "kill the piece at the given position", "k a8", 1,
			[](command_interpreter* interpreter) {
				std::vector<std::string> args = std::move(interpreter->last_command_arguments());
				if (interpreter->algebraic_converter()->validate(args[0])) {
					unsigned int position = interpreter->_algebraic_converter(args[0]);
					if (board::instance()->delete_piece(position) == false) {
						interpreter->print_error_message("There is not a piece at the given position");
					}
				}
				else {
					interpreter->print_error_message("Invalid algebraic notation");
				}
			}
		},

		{'m', "move", "move one piece to a new location", "m a7 a5", 2,
			[](command_interpreter* interpreter) {
				std::vector<std::string> args = std::move(interpreter->last_command_arguments());
				algebraic_notation* algebraic = interpreter->algebraic_converter();

				if (algebraic->validate(args)) {
					//get a pointer to the piece selected by the user
					std::shared_ptr<piece> selected_piece = (*board::instance())[(*algebraic)(args[0])];
					if (selected_piece != nullptr) { //if its is nullptr is because there is not a piece at the given position
						unsigned int new_position = (*algebraic)(args[1]);
						if (selected_piece->valid_move(new_position)) {
							selected_piece->move(new_position);
						}
						else {
							interpreter->print_error_message(args[0] + " can not move to " + args[1]);
						}
					}
					else {
						interpreter->print_error_message("There is not a piece at " + args[0]);
					}
				}
					else {
						interpreter->print_error_message("Invalid algebraic notation");
					}
			}
		}
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

void command_interpreter::print_error_message(const char* msg) const {
	std::cout << msg << ", use h to display the help menu...";
	std::cin.get();
}


void command_interpreter::print_error_message(const std::string msg) const {
	std::cout << msg << ", use h to display the help menu...";
	std::cin.get();
}

/* the command_str parameter contains the name of the command and the parameters of the command*/
void command_interpreter::execute_command(std::string& command_str) {
	//the command is split into a vector of strings
	_last_command_args = std::move(command_to_parameter_vector(command_str));
	
	//the first parameter is the _identifier_char or the _identifier_str of the command
	command* command_ptr = find_command(_last_command_args[0]);
	
	//since we already have a pointer to the command the command _identifier is not needed anymore
	_last_command_args.erase(_last_command_args.begin());

	//if the pointer is null it means the given _identifier is not a valid one
	if(command_ptr == nullptr) {
		print_error_message("Invalid command");
	}
	//compares the number of elements of the vector with the number of parameters that the command can take
	else if ((*command_ptr) == _last_command_args.size()) {
		//this is a bit confusing, the _function hold by the command is a pointer to a function
		//from the command_interpreter class, so in order to execute the _function from the command
		//an instance of command_interpreter is required
		command_ptr->execute(this);
	}
	else {
		print_error_message("Invalid number of arguments");
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

command* command_interpreter::operator[](int index) const {
	if (index >= 0 && index < _NUMBER_OF_COMMANDS)
		return &_commands[index];
	return nullptr;
}
