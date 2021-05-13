#include "../headers/knight.hpp"

knight::knight(int position, bool team) : piece(position, team) {}

const char* knight::icon() const {
	return "Kn";
}

std::vector<unsigned int> knight::possible_movements() const {
	std::vector<unsigned int> movements;
	horizontal_movements(movements);
	vertical_movements(movements);
	return movements;
}

void knight::horizontal_movements(std::vector<unsigned int>& movements) const {
	for(int horizontal : {2,-2}) {
		unsigned int horizontal_position = position() + horizontal;
		if(board_ptr->get_row_from_position(horizontal_position) == board_ptr->get_row_from_position(position())) {
			for(int vertical : {-board_ptr->columns(), board_ptr->columns()}) {
				unsigned int vertical_position = horizontal_position + vertical;
				std::shared_ptr<piece> piece_ptr = (*board_ptr)[vertical_position];
				if(piece_ptr != nullptr) {
					if(piece_ptr->team() != team()) {
						movements.push_back(vertical_position);
					}
				}
				else {
					if(board_ptr->position_out_of_bounds(vertical_position) == false) {
						movements.push_back(vertical_position);
					}
				}
			}
		}	
	}
}

void knight::vertical_movements(std::vector<unsigned int>& movements) const {
	for(int vertical : {board_ptr->columns()*2, -board_ptr->columns()*2}) {
		unsigned int vertical_position = position() + vertical;
		if(board_ptr->position_out_of_bounds(vertical_position) == false) {
			for(int horizontal : {1, -1}) {
				unsigned int horizontal_position = vertical_position + horizontal;
				if(board_ptr->get_row_from_position(horizontal_position) == board_ptr->get_row_from_position(vertical_position)) {
					std::shared_ptr<piece> piece_ptr = (*board_ptr)[horizontal_position];
					if(piece_ptr != nullptr) {
						if(piece_ptr->team() != team()) {
							movements.push_back(horizontal_position);
						}
					}
					else {
						if(board_ptr->position_out_of_bounds(horizontal_position) == false) {
							movements.push_back(horizontal_position);
						}
					}
	
				}

			}	
		}
	}
}
