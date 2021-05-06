#include "../headers/command_interpreter.hpp"
#include "../headers/interactive_layer.hpp"
#include "../headers/board.hpp"
#include <iostream>
#include <string>

//what a nightmare of a constructor
command_interpreter::command_interpreter() : _NUMBER_OF_COMMANDS(6) {
	_board = board::instance();
	_commands = new command[6] {
		//since they are not static method they have to be linked to and instance of command_interpreter
		{'h', "help", "this command displays all the available commands and how to use them", "h", 0, std::bind(&command_interpreter::command_help, this)},
		{'q', "quit", "quit the game", "q", 0, std::bind(&command_interpreter::command_quit, this)},
		{'k', "kill", "kill the piece at the given position (debug)", "k a8", 1, std::bind(&command_interpreter::command_kill, this)},
		{'m', "move", "move one piece to a new location", "m a7 a5", 2, std::bind(&command_interpreter::command_move, this)},
		{'s', "swap", "swap team (debug)", "s", 0, std::bind(&command_interpreter::command_swap, this)},
		{'r', "reveal", "reveals all the positions that a piece can moveo to", "r f4", 1, std::bind(&command_interpreter::command_reveal, this)}
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
		interactive_layer::instance()->print_error_message("Invalid command");
	}
	//compares the number of elements of the vector with the number of parameters that the command can take
	else if ((*command_ptr) == _last_command_args.size()) {
		//this is a bit confusing, the _function hold by the command is a pointer to a function
		//from the command_interpreter class, so in order to execute the _function from the command
		//an instance of command_interpreter is required
		command_ptr->execute();
	}
	else {
		interactive_layer::instance()->print_error_message("Invalid number of arguments");
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

void command_interpreter::command_help() {
	for (int i = 0; i < number_of_commands(); i++) {
		std::cout << (*(*this)[i]) << std::endl;
	}
	std::cin.get();
}

void command_interpreter::command_quit() {
	interactive_layer::instance()->quit_game();
}

void command_interpreter::command_move() {
	std::vector<std::string> args = std::move(last_command_arguments());
	if (_algebraic_converter.validate(args)) {
		//get a pointer to the piece selected by the user
		std::shared_ptr<piece> selected_piece = (*board::instance())[_algebraic_converter(args[0])];
		if (selected_piece != nullptr) { //if its is nullptr is because there is not a piece at the given position
			if(selected_piece->team() == board::instance()->team()) {
				unsigned int new_position = _algebraic_converter(args[1]);
				if (selected_piece->valid_move(new_position)) {
					selected_piece->move(new_position);
					board::instance()->swap_team();
				}
				else {
					interactive_layer::instance()->print_error_message(args[0] + " can not move to " + args[1]);
				}
			}
			else {
				interactive_layer::instance()->print_error_message("You can not move that piece");
			}
		}
	}
}

void command_interpreter::command_reveal() {
	std::vector<std::string> args = std::move(last_command_arguments());
	if(_algebraic_converter.validate(args[0])) {
		std::shared_ptr<piece> piece_ptr = (*board::instance())[_algebraic_converter(args[0])]; 
		if(piece_ptr != nullptr) {
			board_printer* printer = interactive_layer::instance()->get_board_printer();
			printer->highlight_positions(piece_ptr->possible_movements());
		}
	}
}

void command_interpreter::command_swap() {
	board::instance()->swap_team();
}

void command_interpreter::command_kill() {
	std::vector<std::string> args = std::move(last_command_arguments());
	if (_algebraic_converter.validate(args[0])) {
	unsigned int position = _algebraic_converter(args[0]);
		if (board::instance()->delete_piece(position) == false) {
			interactive_layer::instance()->print_error_message("There is not a piece at the given position");
		}
	}
}
