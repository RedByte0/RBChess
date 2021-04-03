#include "../headers/piece.hpp"

std::shared_ptr<board> piece::board_ptr = board::instance();

piece::piece() {
	_position = 0;
	_team = false;
	_moved = false;
}

piece::piece(int position, bool team) {
	_position = position;
	_team = team;
	_moved = false;
}

piece::~piece() {
}

void piece::move(unsigned int position) {
	if(!_moved)
		_moved = true;
	_position = position;
}
