#include "../headers/board.hpp"

board::board() {
	_team = true;
}

board::board(const board& b) {
	*this = b;
}

// copy operator
board& board::operator=(const board& b) {
	return *this;
}

//move operator
board& board::operator=(const board&& b) {
	return *this;
}
