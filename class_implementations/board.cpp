#include "../headers/board.hpp"
#include "../headers/interactive_layer.hpp"

board::board() {
	_team = true;
	_pieces = std::vector<std::shared_ptr<piece>>();
}

bool board::there_is_a_piece_at(unsigned int position) const {
	for(std::size_t i = 0; i < _pieces.size(); i++) {
		/* if there is piece with the same _position as the given position
		 * simply return true and exit the method*/
		if(_pieces[i]->position() == position)
			return true;
	}
	return false;
}

bool board::there_is_a_piece_at(unsigned int position, bool team) const {
	for(std::size_t i = 0; i < _pieces.size(); i++) {
		if(_pieces[i]->position() == position && _pieces[i]->team() == team)
			return true;
	}
	return false;
}

bool board::delete_piece(unsigned int position) {
	for(std::size_t i = 0; i < _pieces.size(); i++) {
		if(_pieces[i]->position() == position) {
			_pieces.erase(_pieces.begin() + i);
			return true;
		}
	}
	return false;
}

std::shared_ptr<piece> board::operator[](unsigned int position) {
	for(std::size_t i = 0; i < _pieces.size(); i++) {
		if(_pieces[i]->position() == position)
			return _pieces[i];
	}
	interactive_layer::instance()->print_error_message("There is not a piece at the given position");
	return nullptr;
}

const std::shared_ptr<piece> board::operator[](unsigned int position) const {
	for(std::size_t i = 0; i < _pieces.size(); i++) {
		if(_pieces[i]->position() == position)
			return _pieces[i];
	}
	interactive_layer::instance()->print_error_message("There is not a piece at the given position");
	return nullptr;
}
