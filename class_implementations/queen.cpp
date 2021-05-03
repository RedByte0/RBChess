#include "../headers/queen.hpp"

queen::queen(int position, bool team) : piece(position, team) {}

const char* queen::icon() const {
	return "Qu";
}


std::vector<unsigned int> queen::possible_movements() const {
	std::vector<unsigned int> movements;
	const int MOVEMENT_DIRECTIONS[8] = {
		(int)board_ptr->columns() + 1, (int)board_ptr->columns() - 1,
		-(int)board_ptr->columns() + 1, -(int)board_ptr->columns() - 1,
		(int)board_ptr->columns(), -(int)board_ptr->columns(),
		1, -1
	};

	//this code is the same for the queen, bishop and rook
	for(int direction : MOVEMENT_DIRECTIONS) {
		bool collision = false;
		unsigned int position = piece::position();
		//keep moving until it collides
		while(collision == false) {
			position += direction;
			//if there is a piece at the new position
			if(board_ptr->there_is_a_piece_at(position)) {
				collision = true;
				//add to the vector if the teams are not equal
				if((*board_ptr)[position]->team() != piece::team()) {
					movements.push_back(position);
				}
			}
			else {
				//make sure that the new position is inside the board
				if(board_ptr->position_out_of_bounds(position))
					collision = true;
				else // add new position to the vector
					movements.push_back(position);
			}
		}
	}	
	return movements;
}
