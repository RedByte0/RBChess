#include "../headers/interactive_layer.hpp"

interactive_layer::interactive_layer() {
	_run_game = true;
}

interactive_layer::~interactive_layer() {}

void interactive_layer::start_game() {
	while(_run_game) {
		_board_printer();
		_interpreter.wait_for_command();
	}
}
