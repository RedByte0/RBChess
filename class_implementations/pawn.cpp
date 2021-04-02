#include "../headers/pawn.hpp"

pawn::pawn(int position, bool team) : piece(position, team) {
}


const char* pawn::icon() const {
	return "Pa";
}

std::vector<unsigned int> pawn::possible_movements() const {
	std::vector<unsigned int> movements;
	bool collision = false;
	//black pawns advance by adding to their current position and white pawns by subtracting 
	unsigned int const MOVEMENT_DIRECTION = piece::team() ? -board::instance()->rows() : board::instance()->rows();

	/* if it is the first time that a pawn moves it can move twice the usual distance.
	 * if a pawns collides against another piece the pawn can not longer move on that direction*/	
	for(int i = 0; i < (piece::moved() ? 1 : 2) && collision == false; i++) {
		unsigned int position = piece::position() + MOVEMENT_DIRECTION * (i + 1);
		if(board::instance()->there_is_a_piece_at(position))
			collision = true;
		else
			movements.push_back(position);	
	}
	
	/* pawns can move diagonally as long as there is a piece from the other
	 * team on that position*/
	unsigned int row = board::instance()->get_row_from_position(piece::position() + MOVEMENT_DIRECTION); 
	for(int i : {MOVEMENT_DIRECTION -1, MOVEMENT_DIRECTION +1}) {
		unsigned int position = piece::position() + i;
		/* first check if there is an piece from the other team at the new position
		 * and then make sure that the new position is on the same row*/
		if(board::instance()->there_is_a_piece_at(position, !piece::team()) && board::instance()->get_row_from_position(position) == row) {
			movements.push_back(position);
		}
	}	

	return movements;
}
