#include "../headers/rook.hpp"

rook::rook(int position, bool team) : piece(position, team) {}

const char* rook::icon() const {
	return "Ro";
}

std::vector<unsigned int> rook::possible_movements() const {
	std::vector<unsigned int> movements;
	horizontal_movements(movements);
	vertical_movements(movements);
	return movements;
}


void rook::horizontal_movements(std::vector<unsigned int>& movements) const {
	const int HORIZONTAL_DIRECTIONS[2] = { 1, -1 };
	const unsigned int CURRENT_ROW = board_ptr->get_row_from_position(piece::position());

	for (int direction : HORIZONTAL_DIRECTIONS) {
		bool collision = false;
		unsigned int position = piece::position() + direction;
		unsigned int row = board_ptr->get_row_from_position(position);
		//stop when there is a collision and when the piece trie to move to a new row
		while (row == CURRENT_ROW && collision == false) {
			std::shared_ptr<piece> piece_ptr = (*board_ptr)[position];
			if (piece_ptr != nullptr) {
				collision = true;
				if (piece_ptr->team() != piece::team()) {
					movements.push_back(position);
				}
			}
			else {
				movements.push_back(position);
			}
			position += direction;
			row = board_ptr->get_row_from_position(position);
		}
	}

}

void rook::vertical_movements(std::vector<unsigned int>& movements) const {
	const int VERTICAL_DIRECTIONS[2] = { (int)board_ptr->columns(), -(int)board_ptr->columns() };
	for (int direction : VERTICAL_DIRECTIONS) {
		bool collision = false;
		unsigned int position = piece::position() + direction;
		
		while (collision == false && board_ptr->position_out_of_bounds(position) == false) {
			std::shared_ptr<piece> piece_ptr = (*board_ptr)[position];
			if (piece_ptr != nullptr) {
				collision = true;
				if (piece_ptr->team() != piece::team()) {
					movements.push_back(position);
				}
			}
			else {
				movements.push_back(position);
			}
			position += direction;
		}
	}
}