#include "../headers/piece.hpp"
#include <algorithm>

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
	if(board_ptr->there_is_a_piece_at(position)) {
		board_ptr->delete_piece(position);
	//delete the piece at the new location
	}
	//set the moved flag to true if is not set
	if(!_moved)
		_moved = true;
	//change the position
	_position = position;	
}

bool piece::valid_move(unsigned int new_position) {
	std::vector<unsigned int> movements = std::move(possible_movements());
	std::vector<unsigned int>::iterator result = std::find(movements.begin(), movements.end(), new_position);
	return result != movements.end();
}
