#include "../headers/board.hpp"

board::board() {
	_team = true;
	_pieces = std::vector<piece*>();
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

piece* board::operator[](unsigned int position) {
	for(std::size_t i = 0; i < _pieces.size(); i++) {
		if(_pieces[i]->position() == position)
			return _pieces[i];
	}
	return nullptr;
}

const piece* board::operator[](unsigned int position) const {
	for(std::size_t i = 0; i < _pieces.size(); i++) {
		if(_pieces[i]->position() == position)
			return _pieces[i];
	}
	return nullptr;
}
