#include "../headers/king.hpp"

king::king(int position, bool team) : piece(position, team) {}

const char* king::icon() const {
	return "Ki";
}

std::vector<unsigned int> king::possible_movements() const {
	std::vector<unsigned int> movements;
	const int MOVEMENT_DIRECTIONS[8] = {
		1, (int)board_ptr->columns(),
	       -1, -(int)board_ptr->columns(),
       		(int)board_ptr->columns() + 1, (int)board_ptr->columns() - 1,	       
       		-(int)board_ptr->columns() + 1, -(int)board_ptr->columns() - 1
	};
	
	for(int direction : MOVEMENT_DIRECTIONS) {
		unsigned int position = piece::position() + direction;
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
	return movements;
}
