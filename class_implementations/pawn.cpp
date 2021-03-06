#include "../headers/pawn.hpp"

void pawn::promote() {
	std::cout << "Promote" << std::endl;
}

pawn::pawn(int position, bool team) : piece(position, team) {
}

/* when a pawn moves some extra conditions have to be taken into account 
 * for instance when a pawn reaches the other end of the board
 * it has to be promoted*/
void pawn::move(int position) {
	int row = board_ptr->get_row_from_position(position);
	//if the new position of the pawn is the end of the board then the pawn is promoted
	if(row == 0 || row == board_ptr->rows()-1) {
		promote();	
	}
	piece::move(position);
}

const char* pawn::icon() const {
	return "Pa";
}

std::vector<int> pawn::possible_movements() const {
	std::vector<int> movements;
	bool collision = false;
	//black pawns advance by adding to their current position and white pawns by subtracting 
	int const MOVEMENT_DIRECTION = piece::team() ? -(int)board_ptr->columns() : board_ptr->columns();

	/* if it is the first time that a pawn moves it can move twice the usual distance.
	 * if a pawns collides against another piece the pawn can not longer move on that direction*/	
	for(int i = 0; i < (piece::moved() ? 1 : 2) && collision == false; i++) {
		int position = piece::position() + MOVEMENT_DIRECTION * (i + 1);
		if(board_ptr->there_is_a_piece_at(position))
			collision = true;
		else {
			if(board_ptr->position_out_of_bounds(position) == false) {
				movements.push_back(position);	
			}
		}
	}
	
	/* pawns can move diagonally as long as there is a piece from the other
	 * team on that position*/
	int row = board_ptr->get_row_from_position(piece::position() + MOVEMENT_DIRECTION); 
	for(int i : {MOVEMENT_DIRECTION -1, MOVEMENT_DIRECTION +1}) {
		int position = piece::position() + i;
		/* first check if there is an piece from the other team at the new position
		 * and then make sure that the new position is on the same row*/
		if(board_ptr->there_is_a_piece_at(position, !piece::team()) && board_ptr->get_row_from_position(position) == row) {
			movements.push_back(position);
		}
	}	

	return movements;
}
