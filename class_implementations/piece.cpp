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

void piece::move(int position) {
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

bool piece::valid_move(int new_position) {
	std::vector<int> movements = std::move(possible_movements());
	std::vector<int>::iterator result = std::find(movements.begin(), movements.end(), new_position);
	return result != movements.end();
}

void piece::horizontal_movements(std::vector<int>& movements) const {
	const int CURRENT_ROW = board_ptr->get_row_from_position(_position);

	for (int direction : {-1, 1}) {
		bool collision = false;
		
		//stop when there is a collision and when the piece tries to move to a new row
		for(int i = _position + direction, row = board_ptr->get_row_from_position(i); 
		row == CURRENT_ROW && collision == false; 
		i += direction, row = board_ptr->get_row_from_position(i)) {

			std::shared_ptr<piece> piece_ptr = (*board_ptr)[i];
			if (piece_ptr != nullptr) {
				//if there is already a piece at the new_position collision is set to true
				collision = true;
				//if the teams are different the piece can be eaten
				if (piece_ptr->team() != piece::team()) {
					movements.push_back(i);
				}
			}
			else {
				//the new position is empty
				movements.push_back(i);
			}

		}
	}
}

void piece::vertical_movements(std::vector<int>& movements) const {
	for(int direction : {board_ptr->columns(), -board_ptr->columns()}) {
		bool collision = false;
		for(int i = _position + direction; board_ptr->position_out_of_bounds(i) == false && collision == false; i += direction) {
			std::shared_ptr<piece> piece_ptr = (*board_ptr)[i];
			if(piece_ptr != nullptr) {
				collision = true;
				if(piece_ptr->team() != team()) {
					movements.push_back(i);
				}
			}
			else {
				movements.push_back(i);
			}
		}
	}
}

void piece::diagonal_movements(std::vector<int>& movements) const {
	const std::vector<int> directions = {
		(int)board_ptr->columns() + 1, (int)board_ptr->columns() - 1,
		-(int)board_ptr->columns() + 1, -(int)board_ptr->columns() - 1,
	};

	for(int direction : directions) {
		bool collision = false;
		int previous_column = board_ptr->get_column_from_position(_position);
		int i = _position + direction;
		int column = board_ptr->get_column_from_position(i);
		int column_difference = previous_column - column;

		while(collision == false && board_ptr->position_out_of_bounds(i) == false && 
		std::max(column_difference, -column_difference) == 1) {
			std::shared_ptr<piece> piece_ptr = (*board_ptr)[i];
			if(piece_ptr != nullptr) {
				collision = true;
				if(piece_ptr->team() != team()) {
					movements.push_back(i);
				}
			}
			else {
				movements.push_back(i);
			}
			previous_column = column;
			i += direction;
			column = board_ptr->get_column_from_position(i);
			column_difference = previous_column - column;
		}
	}
}
