#include "../headers/king.hpp"
#include <algorithm>

king::king(int position, bool team) : piece(position, team) {}

const char* king::icon() const {
	return "Ki";
}

void king::move(int position) {
	std::vector<int> castle_movements;
	castling_moves(castle_movements);
	//if the king can castle to that position, the rook and the king must be swaped
	if (std::find(castle_movements.begin(), castle_movements.end(), position) != castle_movements.end()) {
		//move the rook to the position that the king is currently at
		//the moved flag is not set but it does not matter
		(*board_ptr)[position]->position(piece::position());	
	}
	//move the king to its new location
	piece::move(position);	
}

std::vector<int> king::possible_movements() const {
	std::vector<int> movements;

	const int MOVEMENT_DIRECTIONS[8] = {
		1, (int)board_ptr->columns(),
	       -1, -(int)board_ptr->columns(),
       		(int)board_ptr->columns() + 1, (int)board_ptr->columns() - 1,	       
       		-(int)board_ptr->columns() + 1, -(int)board_ptr->columns() - 1
	};
	
	//check if the positions at MOVEMENT_DIRECTIONS are valid, if they are add them to the movements vector
	for(int direction : MOVEMENT_DIRECTIONS) {
		int position = piece::position() + direction;
		if(board_ptr->position_out_of_bounds(position) == false) {
			std::shared_ptr<piece> piece_ptr = (*board_ptr)[position];
			if(piece_ptr != nullptr) {
				if(piece::team() != piece_ptr->team())
					movements.push_back(position);
			}
			else {
				movements.push_back(position);
			}
		}
	}

	//check if the king can castle
	castling_moves(movements);

	return movements;
}

void king::castling_moves(std::vector<int>& movements) const {
	if(piece::moved() == false) {
		//check all ther rooks that are on the same row as the king
		int row = board_ptr->get_row_from_position(position());
		for(int i = row * board_ptr->columns(); i < (row + 1) * board_ptr->columns(); i++) {
			std::shared_ptr<piece> current_piece = (*board_ptr)[i];
			if(current_piece != nullptr && std::string(current_piece->icon()) == "Ro" && current_piece->moved() == false && current_piece->team() == team()) {
				//make sure that the path to the rook is clear
				if(path_is_clear(i)) {
					movements.push_back(i);
				}
			}
		}
	}	
}

bool king::path_is_clear(const int position) const {
	int difference = position - piece::position();
	bool forward = difference > 0;
	difference = forward ? difference : -difference;

	for(int i = 1; i  < difference; i++) {
		std::cout << "i: " << i << std::endl;
		if(board_ptr->there_is_a_piece_at(piece::position() + (forward ? i : -i))) {
			return false;
		}
	}
	return true;
}
