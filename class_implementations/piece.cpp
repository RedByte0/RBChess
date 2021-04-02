#include "../headers/piece.hpp"

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
